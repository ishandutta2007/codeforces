#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define debug //
using namespace std;
typedef long long ll;
typedef long double ld;

//Suffix array
const int N=3e5+3; //max. length of word
//stuff::play (string, greatest letter)
//Ranks of indices in rnk, sorted indices in SA
//lcp[i] = LCP of i-th and (i+1)-th suffix
namespace suff {
	int rnk[N], SA[N], Txt[N], lcp[N];
	void RadixSort (int n, int *k, int *a, int *b, int K) {
		int *c = new int [K];
		rep(i,0,K) c[i]=0;
		rep(i,0,n) c[k[a[i]]]++;
		int suma=0;
		rep(i,0,K) {int t = c[i]; c[i] = suma; suma +=t; }
		rep(i,0,n) b[c[k[a[i]]]++] = a[i];
		delete[] c;
	}
	bool cmp (int a, int b, int *T) {
		while (true) {
			if (T[a]!=T[b]) return T[a] < T[b];
			if (a%3!=0 && b%3!=0) return rnk[a] < rnk[b];
			a++; b++; 
		}
	}
	void suffArr (int *T, int *A, int n, int K) {
		T[n] = T[n+1] = T[n+2] = T[n+3]= 0;
		n++; //powstal nowy znak
		//1. Sortuj znaki
		int Temp[n];
		rep(i,0,n) Temp[i]=i;
		RadixSort(n, T+2, Temp, A, K);
		RadixSort(n, T+1, A, Temp, K);
		RadixSort(n, T, Temp, A, K);
		int k=1;
		Temp[A[0]]=k;
		rep(i,1,n) {
			k+= (T[A[i]]!=T[A[i-1]] || T[A[i]+1]!= T[A[i-1]+1] || T[A[i]+2]!=T[A[i-1]+2]);
			Temp[A[i]]=k;
		}
		//tekst jest w Temp, posortowane indeksy w A
		rep(i,1,n) if (Temp[A[i]]==Temp[A[i-1]]) {
			int c=0, d=0;
			int n0 = (n+2)/3, n1 = (n+1)/3, n2 = n/3;
			int W0[n0], W[n];
			rep(a,0,n) if (a%3==0) W0[d++] = a;
			rep(a,0,n) if (a%3==1) T[c++] = Temp[a];
			rep(a,0,n) if (a%3==2) T[c++] = Temp[a];
			suffArr(T, A, c, k+1); //mam jeszcze rangi
			
			rep(i,0,c) {
				if (A[i]<n1) A[i] = A[i] * 3 +1;
				else A[i] = (A[i] - n1) * 3 +2;
			}
			rep(i,0,c) rnk[A[i]] = i + 1;
			rnk[n] = 0;
			RadixSort(n0, rnk+1, W0, W, n+1);
			RadixSort(n0, Temp, W, W0, k+1);
			
			d=0; c=0;
			while (d<n0 && c<n1+n2) {
				if (cmp (W0[d], A[c], Temp)) {
					W[c+d]=W0[d];
					d++;
				}
				else {
					W[c+d] = A[c];
					c++;
				}
			}
			while (d<n0) {W[c+d] = W0[d]; d++;}
			while (c<n1+n2) {W[c+d] = A[c]; c++;}
			rep(i,0,n) A[i] = W[i];
			break;
		}
		rep(i,1,n) A[i-1] = A[i]; //usun pusty sufiks
	}
	void play (string s, int K='z') {
		int n = s.size();
		rep(i,0,n) Txt[i] = s[i];
		suffArr(Txt, SA, n, K+1);
		rep(i,0,n) rnk[SA[i]] = i;
		
		rep(i,0,n-1) lcp[i] = 1;
		int p = 0; s.pb('#');
		rep(i,0,n) {
			if (rnk[i]==n-1) {
				p = 0;
				continue;
			} 
			while (s[i+p] == s[SA[rnk[i]+1]+p]) p++;
			lcp[rnk[i]] = p;
			if (p>0) p--;
		}
	}
};

const int S = 1e5+10;
const int L = 18;
set <int> pos[S];
ll sum[S]; //# roznych prefiksow
int ojce[S], SRnk[N], PRnk[N], SLCP[S], PLCP[S], ST[L][S], BST[L][S], LOG[1<<L], SLen[S];
ll stan;
int krol (int a)
{
	if (ojce[a]==-1) return a;
	return (ojce[a] = krol(ojce[a]));
}
ll lcp (int l, int r) 
{
	l++;
	int d = LOG[r-l+1];
	debug ("d = %d\n", d);
	debug ("lcp (%d %d) = %d (%d %d)\n", l-1, r, min( ST[d][l], ST[d][r-(1<<d) +1]), ST[d][l], ST[d][r - (1<<d) +1]);
	return min( ST[d][l], ST[d][r - (1<<d) +1]);
}
ll add (set <int> &wor, int pos)
{
	ll ret = SLen[pos] + 1LL;
	if (pos < *wor.begin())
	{
		ret -= (lcp(pos, *wor.begin()) +1LL);
		wor.insert(pos);
		return ret;
	}
	
	auto it = wor.end();
	it--;
	if (pos > *it)
	{
		ret -= lcp( *it, pos) +1LL;
		wor.insert(pos);
		return ret;
	}
	
	it = wor.lower_bound(pos);
	int r= *it;
	it--;
	int l = *it;
	wor.insert(pos);
	
	ret += lcp(l, r) +1LL;
	
	ret -= lcp(l, pos) + 1LL;
	ret -= lcp(pos, r) + 1LL;
	
	return ret;
}
bool unia (int a, int b)
{
	debug ("polacz %d %d\n", a, b);
	int ka = krol(a), kb = krol(b);
	
	if (ka==kb) return false;
	
	if ((int)pos[ka].size() < (int)pos[kb].size()) swap(ka, kb);
	
	stan -= sum[kb];
	stan -=sum[ka];
	ojce[kb] = ka;
	
	debug ("lacze %d(%lld) %d (%lld)\n", ka, sum[ka], kb, sum[kb]);
	
	for (int p: pos[kb]) sum[ka] += add(pos[ka], p);
	stan += sum[ka];
	
	return true;
}


int main ()
{
	string s;
	cin>>s;
	int n = (int)s.size();
	rep(i,0,n+1) ojce[i] = -1LL;
	ll res = 0LL;
	
	s.pb('#');
	suff::play(s);
	
	debug ("policzylem SA: ");
	rep(i,0,n+1) debug ("%d ", suff::SA[i]);
	debug ("\n");
	rep(i,0,n) debug ("%d ", suff::lcp[i]);
	debug ("\n");
	
	
	rep(i,0,n+1) 
	{
		SRnk[i] = suff::rnk[i];
		SLen[SRnk[i]] = n-i;
	}
	rep(i,1,n+1) 
	{
		SLCP[i] = suff::lcp[i-1];
	}
	
	s.pop_back();
	s.pop_back();
	reverse(s.begin(), s.end());
	s.pb('#');
	
	cerr<<s <<"\n";
	suff::play(s);
	rep(i,0,n) PRnk[i] = suff::rnk[i];
	rep(i,0,n) PLCP[i+1] = suff::lcp[i];
	
	reverse(s.begin(), s.end());
	
	rep(i,1,n+1) 
	{
		ST[0][i] = SLCP[i];
		debug ("%d: %d\n", i, ST[0][i]);
	}
	rep(k,0,L-1)
	{
		rep(i,0,n+1) if (i+(1<<k)<n+1) ST[k+1][i] = min(ST[k][i], ST[k][i+(1<<k)]);
		rep(i,(1<<k),(1<<(k+1))) 
		{
			LOG[i] = k;
		}
	}
	
	vector <pair <int, pair <int, int> > > lacz;
	
	rep(i,1,n) 
	{
		int l1 = n-1-suff::SA[i-1], l2 = n-1-suff::SA[i]; 
		debug ("lcp %d (%d) %d (%d) to %d\n", SRnk[l1+1], l1, SRnk[l2+1], l2, PLCP[i]);
		
		lacz.pb(mp(PLCP[i], mp(SRnk[l1+1], SRnk[l2+1])));
	}
	
	sort(lacz.begin(), lacz.end());
	reverse(lacz.begin(), lacz.end());
	int p = 0;
	for (int len = n-1; len>=0; len--)
	{
		int rsuf = SRnk[len+1];
		debug ("wprowadz %d\n", rsuf);
		
		sum[rsuf] = n - len;
		stan+= sum[rsuf];
		
		pos[rsuf].insert(rsuf);
		
		while (p<(int)lacz.size() && lacz[p].fi==len)
		{
			unia(lacz[p].se.fi, lacz[p].se.se);
			p++;
		}
		
		debug ("pref_len = %d, stan %lld\n\n", len, stan);
		
		res += stan;
	}
	
	//dolicz bez *
	rep(i,0,n+1) res += ll(i+1); //dlugosci +1
	rep(i,1,n+1)
	{
		debug ("%lld - %d\n", res, SLCP[i]+1);
		res -= ll(SLCP[i]+1);
	}
	printf ("%lld\n", res);
}
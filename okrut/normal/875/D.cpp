#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define debug //
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 2e5+100;
const int L = 19;
int n, R[L][N], RM[N], LM[N], LOG[1<<L];
bool on[N];

int krol (int a)
{
	if (LM[a]==-1) return a;
	return (LM[a] = krol(LM[a]));
}
bool unia (int a, int b)
{
	if (min(a,b) < 0 || max(a,b)>=n || !on[a] || !on[b]) return false;
	int ka = krol(a), kb = krol(b);
	if (kb < ka) swap(kb, ka);
	LM[kb] = ka;
	RM[ka] = RM[kb];
	return true;
}
int query (int l, int r)
{
	int lvl = LOG[r-l+1];
	return R[lvl][l] | R[lvl][r-(1<<lvl)+1];
}
int main ()
{
	int pos = 1;
	rep(i,0,18)
	{
		for (;pos < (1<<(i+1)); pos++) LOG[pos]=i;
	}
	
	scanf ("%d", &n);
	vector <pair <int, int> > tab(n);
	rep(i,0,n) 
	{
		scanf ("%d", &R[0][i]);
		tab[i] = mp(R[0][i], i);
	}
	
	rep(i,0,n) LM[i] = -1;
	rep(i,0,n) RM[i] = i;
	
	rep(p,1,L) 
	{
		rep(i,0,n - (1<<p) +1) R[p][i] = R[p-1][i] | R[p-1][i+(1<<(p-1))];
	}
	
	sort(tab.begin(), tab.end());
	ll res = 0LL;
	for (auto p: tab)
	{
		int l, r, sl, sr; //gobalne konce
		if (p.se==0) sl = 0;
		else
		{
			if (on[p.se-1]) sl = krol(p.se-1);
			else sl = p.se;
		}
		if (p.se==n-1) sr = n-1;
		else
		{
			if (on[p.se+1]) sr = RM[krol(p.se+1)];
			else sr = p.se;
		}
		
		debug ("\nrobie (%d %d) [%d %d] - %lld\n", p.fi, p.se, sl, sr, res);
		
		vector <pair <int, int> > lewe, prawe; //xor - 1.pozycja od srodka
		l = sl;
		r = p.se;
		while (r>=sl)
		{
			int curr = query(r, p.se);
			//znajdz ostatnie, gdzie sie rowna
			while (l<r)
			{
				int mid = (l+r)/2;
				int w = query(mid, p.se);
				if (w==curr) r = mid;
				else l = mid+1;
			}
			lewe.pb(mp(curr, l)); //ostatnia pozycja
			r = l-1;
			l = sl;
		}
		l = p.se;
		r = sr;
		while (l<=sr)
		{
			int curr = query(p.se, l);
			while (l<r)
			{
				int mid = (l+r)/2;
				int w = query(p.se, mid+1);
				if (w==curr) l = mid+1;
				else r = mid;
			}
			prawe.pb(mp(curr, r));
			l = r+1;
			r = sr;
		}
		
		int lold = p.se+1;
		int inr = (int)prawe.size() - 1;
		
		debug ("lewe ory: ");
		for (auto q: lewe) debug ("(%d %d) ", q.fi, q.se);
		debug ("\nprawe ory: ");
		for (auto q: prawe) debug ("(%d %d) ", q.fi, q.se);
		debug ("\n");
		
		for (auto lin: lewe)
		{
			while (inr>=0 && (prawe[inr].fi | lin.fi) > p.fi) inr--; //moge Cie dodac
			
			if (inr>=0) l = prawe[inr].se; //pierwszy, ktorego nie mozemy
			else l = p.se;
			
			ll ile = lold - lin.se;
			lold = lin.se;
			
			debug ("(%d %d): %d += %lld\n", lin.fi, lin.se, inr, ile * ll(sr -l));
			
			res += ile * ll(sr -l);
		}
		//srodek po prawej
		lold = p.se; //tego nie licze
		for (auto lin: lewe) 
		{
			ll ile = lold - lin.se;
			lold = lin.se;
			
			if (lin.fi > p.fi) res+=ile;
		}
		
		on[p.se] = true;
		unia(p.se, p.se-1);
		unia(p.se, p.se+1);
	}
	printf ("%lld\n", res);
}
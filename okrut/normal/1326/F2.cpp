#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) //fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 18;
const int R = 400;
bool Knows[N][N];

ll Dp[1<<N][N], Paths[N+1][1<<N]; //Number of paths exatly on this mask
ll F[1<<N], D[1<<N], FP[R], RP[R], Res[1<<N]; //number of permutations that produce at least those 1's
int Bits[1<<N];
map <vector <int>, int> PN; //Partition Number
int n;

void partition(int mask, vector <int> &p)
{
	p.clear();
	int cnt = 1;
	rep(i,0,n-1)
	{
		if (mask & (1<<i)) cnt++;
		else
		{
			p.pb(cnt);
			cnt = 1;
		}
	}
	p.pb(cnt);
	sort(p.begin(), p.end());
}

int partno (int mask)
{
	vector <int> p;
	partition(mask, p);
	return PN[p];
}

ll incExl(int mask, ll *T)
{
	ll ret = 0;
	for (int m = mask; m>=0; m = (m-1)&mask)
	{
		if (Bits[m^mask]&1)
		{
			ret-=T[m];
		}
		else ret += T[m];
		
		if (m==0) break;
	}
	return ret;
}


int main ()
{
	//ios_base::sync_with_stdio(false);
	
	// init:
	rep(i,0,(1<<N)) Bits[i] = __builtin_popcount(i);
	
	//read In
	cin>>n;
	rep(i,0,n)
	{
		string s;
		cin>>s;
		rep(j,0,n) Knows[i][j] = (s[j]=='1');
	}
	
	//make PN
	int pn = 0;
	rep(i,0,(1<<(n-1)))
	{
		vector <int> p;
		partition(i, p);
		
		if (PN.count(p)==0) PN[p] = pn++;
	}
	
	rep(i,0,n) Dp[(1<<i)][i] = 1;
	
	rep(m,1,(1<<n)) rep(i,0,n) if (m&(1<<i)) rep(j,0,n) if ((m&(1<<j))==0 and Knows[i][j])
	{
		Dp[m|(1<<j)][j] += Dp[m][i];
	}
	
	rep(m,1,(1<<n)) rep(i,0,n) Paths[Bits[m]][m] += Dp[m][i];
	
	debug ("Calculated Paths\n");
	
	rep(len,1,n+1)
	{
		debug ("Paths of len %d: ", len);
		rep(m,0,(1<<n)) debug ("%lld ", Paths[len][m]);
		debug ("\n");
	}
	
	//SOS
	rep(len,1,n+1)
	{
		rep(i,0,n) for (int m = (1<<n)-1; m>=0; m--) if (m&(1<<i))
		{
			Paths[len][m] += Paths[len][m^(1<<i)];
		}
	}
	
	debug ("Calculated SOS\n");
	
	rep(len,1,n+1)
	{
		debug ("Paths of len %d: ", len);
		rep(m,0,(1<<n)) debug ("%lld ", Paths[len][m]);
		debug ("\n");
	}
	
	
	rep(i,0,pn) FP[i] = RP[i] = -1;
	
	rep(m,0,(1<<(n-1)))
	{
		vector <int> part;
		partition(m, part);
		int p = PN[part];
		
		debug ("calc %d: ", m);
		for (int len: part) debug ("%d ", len);
		debug ("\n");
		
		if (FP[p]==-1)
		{
			rep(i,0,(1<<n)) D[i] = 1LL;
			
			rep(i,0,(1<<n)) for (int len: part)
			{
				 D[i]*=Paths[len][i];
			}
			
			FP[p] = incExl((1<<n)-1, D);
		}
		
		F[m] = FP[p];
	}
	
	
	debug ("Calculated F\n");
	
	rep(m,0,(1<<(n-1))) debug ("%lld ", F[m]);
	debug ("\n");
	
	//zamieniam semantyke, teraz mowie o pozycji zer
	rep(i,0,(1<<(n-2))) swap(F[i], F[i^((1<<(n-1))-1)]);
	
	/* Policz Inclusion Exclusion na F */
	
	rep(m,0,(1<<(n-1))) Res[m] = incExl(m, F);
	
	rep(i,0,(1<<(n-2))) swap(Res[i], Res[i^((1<<(n-1))-1)]);
	
	rep(m,0,(1<<(n-1))) cout<<Res[m] <<" ";
	cout<<"\n";
}
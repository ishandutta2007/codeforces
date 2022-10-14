#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) //fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

const ll mod = 998244353;
const ll pod = 29;

const int N = 3005;




ll Dp1[N][N], Dp2[N][N], Pref[N][N], Pref2[N][N]; //juz sie nie da przedluzyc
// pierwsze t liter dalo mi sufiks takiej dlugosci


int main ()
{
	ios_base::sync_with_stdio(false);
	
	ll half = 1, d=2;
	rep(i,0,30)
	{
		 if ((mod-2)&(1<<i)) half = half * d % mod;
		 d = d*2LL % mod;
	}
	
	string S, T;
	cin>>S >>T;
	
	int s = S.size(), t = T.size();
	
	
	rep(i,0,t) if (T[i]==S[0])
	{
		Dp1[i][i] = Dp2[i][i] = 1;
	}
	
	for (int a = t-1; a>=0; a--) rep(b,a+1,t)
	{
		int cnt = b-a;
		if (T[b]==S[cnt])
		{
			Dp2[a][b]+= Dp1[a][b-1] + Dp2[a][b-1];
		}
		if (T[a]==S[cnt]) 
		{
			Dp1[a][b]+= Dp1[a+1][b] + Dp2[a+1][b];
		}
		
		Dp1[a][b]%=mod;
		Dp2[a][b]%=mod;
	}
	
	Pref[s][0] = 1;
	
	for (int i=s-1; i>=0; i--)
	{
		Pref[i][0]++;
		rep(j,0,t) 
		{
			if (S[i]==T[j])  Pref[i][j+1] += Pref[i+1][j];
		}
		
		Pref[i][t] += Pref[i+1][t]; //jesli juz jest wszystko, moge dokladac z lewej bezkarnie
		
		rep(j,0,t+1)
		{
			Pref[i][j] += Pref[i+1][j];
			Pref[i][j] %= mod;
		}	
	}
	
	//i==0
	
	debug ("\nDp1: \n");
	rep(i,0,t) 
	{
		rep(j,0,t) debug ("%lld ", Dp1[i][j]);
		debug ("\n");
	}
	debug ("\nDp2: \n");
	rep(i,0,t) 
	{
		rep(j,0,t) debug ("%lld ", Dp2[i][j]);
		debug ("\n");
	}
	debug ("\nPref: \n");
	rep(i,0,s+1)
	{
		rep(j,0,t+1) debug ("%lld ", Pref[i][j]);
		debug ("\n");
	} 
	
	
	
	ll res = Pref[0][t];
	//wszytkie dolorzenia z lewej
	rep(len,1,t+1)
	{
		ll right = Dp2[t-len][t-1]; //ostatnie dolorzenie bylo z prawej
		ll left = Pref[len][t-len]; //reszta
		
		debug ("For length %d: %lld * %lld\n", len, left, right);
		
		
		res += left * right % mod;
	}
	
	cout<<res % mod <<"\n";
}
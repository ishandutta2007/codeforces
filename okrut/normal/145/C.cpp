#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug //
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
vector <int> tab;
bool ten_test;
bool check (int a)
{
	while (a>0)
	{
		if (a%10!=4 && a%10!=7) return false;
		a/=10;
	}
	return true;
}
const int L=(1<<10)+100; //tyle jest liczb szczesliwych
vector <vector <ll> > dp;
vector <ll> ile;
map <int, int> mapa;
vector <ll> odwr, sil;
int x;
int n, k;
int nr (int a)
{
	if (mapa.count(a)==0) mapa[a]=x++;
	return mapa[a];
}
ll turn (ll a, ll wyk=mod-2LL)
{
	ll ret=1LL;
	ll pot=a; //od razu do pierwszej
	while (wyk>0LL)
	{
		if (wyk%2LL==1) ret*=pot;
		pot=pot*pot;
		if (pot>=mod) pot%=mod;
		if (ret>=mod) ret%=mod;
		wyk/=2LL;
	}
	return ret;
}
ll newton (int a, int b) //a po b
{
	if (b>a) return 0LL;
	return (((sil[a]*odwr[a-b])%mod)*odwr[b])%mod;
}
int main ()
{
	x=1;
	scanf ("%d %d", &n, &k);
	
	if (n==1000 && k==10) ten_test=false;
	else ten_test=false;
	
	sil.resize(n+1);
	odwr.resize(n+1);
	sil[0]=1;
	rep(i,1,n+1) sil[i]=(sil[i-1]*ll(i))%mod;
	rep(i,0,n+1) odwr[i]=turn(sil[i]);
	
	
	tab.resize(n);
	ile.resize(L+1,0);
	int m=0; //nieszczesliwych
	int a;
	rep(i,0,n) 
	{
		scanf ("%d", &tab[i]);
		if (check(tab[i]))
		{
			a=nr(tab[i]);
			if (a>(int)ile.size())
			{
				printf ("%d vs %d\n", a, (int)ile.size());
				return 0;
			}
			ile[a]++;
		}
		else m++;
	}
	//update
	if (ten_test)
	{
		printf ("line 83\n");
		return 0;
	}
	dp.resize(2);
	dp[0].resize(k+1,0LL);
	dp[1].resize(k+1,0LL);
	dp[1][0]=1LL; //zawsze sie da
	rep(i,0,k+1) dp[0][i]=newton(m, i);
	if (ten_test) 
	{
		printf ("%d\n", x);
		return 0;
	}
	rep(i,1,x+1)
	{
		rep(j,1,k+1)
		{
			dp[i%2][j]=dp[(i-1)%2][j]+ile[i]*dp[(i-1)%2][j-1];  //beze mnie+ze zmna
			if (dp[i%2][j]>=mod) dp[i%2][j]%=mod;
		}
		if (ile[i]>0LL) debug ("%lld %lld\n", dp[i%2][0], dp[i%2][1]);
	}
	printf ("%lld\n", dp[x%2][k]);
}

//Mam wszystkie mozliwoc bez tej liczbys szczesliwej - moge ja dodac + 

//ile jest tych liczb 64*8 * k i styknie
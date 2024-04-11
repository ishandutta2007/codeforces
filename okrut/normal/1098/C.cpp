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

const int N = 1e5+20;

ll ukl[N];
vector <int> ojce[N]; //i juz bedzie prosto
ll n, s;

int main ()
{
	scanf ("%lld %lld", &n, &s);
	if (2LL*s>n*(n+1LL))
	{
		printf ("No\n");
		return 0;
	}
	ll b = 1;
	ll sum, pot, st, m;
	while (b<n) //minimalna suma, jaka mozemy uzyskac
	{
		sum=0;
		pot = 1;
		st=1;
		m = n;
		while (m>pot)
		{
			m-=pot; //pakujemy cie
			sum+=st * pot;
			st++;
			pot*=ll(b);
		}
		sum+=st * m;
		pot/=b;
		
		if (sum<=s) break; //mozna uzyskac
		b++;
	}
	if (b==n) 
	{
		printf ("No\n");
		return 0;
	}
	
	//robimy branching = b
	if (b==1)
	{
		printf ("Yes\n");
		rep(i,1,n) printf ("%d ", i);
		printf ("\n");
		return 0;
	}
	
	debug ("robie stopien %lld\n", b);
	
	debug ("roznica to %lld %lld\n", sum, s);
	ll szyja = 0;
	while (n - (st + szyja) <= s - sum)
	{
		sum+=n - (st + szyja);
		debug ("step by %lld (%lld %lld %lld)\n", n - (st + szyja), m, st , szyja);
		assert( n - (st + szyja) >=0);
		
		szyja++;
		m--;
		if (m==0)
		{
			debug ("no left on level - %lld th\n", st);
			m = pot;
			pot/=(ll)b;
			st--;
		}
	}
	
	
	ll t = 0;
	rep(i,1,szyja+1) 
	{
		ukl[i] = 1;
		t+=ll(i);
	}
	st = szyja+1;
	m = n - szyja;
	pot = 1;
	
	while (m>pot)
	{
		ukl[st] = pot;
		m-=pot;
		t+=st * pot;
		pot*=b;
		st++;
	}
	ukl[st] = m;
	t+=st * m;
	
	debug ("%lld vs %lld\n", t, s);
	
	while (t < s)
	{
		int x=st;
		while (ukl[x]==1) x--;
		
		ukl[x]--;
		ukl[x+1]++;
		t++;
		if (x==st) st++;
	}
	
	debug ("profil: ");
	rep(i,1,n+1) debug ("%lld ", ukl[i]);
	debug ("\n");
	
	//to jest nasz profil
	printf ("Yes\n");
	int x=1;
	while (ukl[x]>0) x++;
	int y=1;
	rep(i,1,x) rep(j,0,(int)ukl[i]) 
	{
		if (y>1)
		{
			printf ("%d ", ojce[i-1][j/b]);
		}
		ojce[i].pb(y++);
	}
	printf ("\n");
	 
}
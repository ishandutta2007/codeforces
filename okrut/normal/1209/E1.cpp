#pragma GCC optimize "O3"
#pragma GCC optimize "unroll-loops"
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
typedef long double ld;

const int N = 4, M = 100;
int n, m;
int tab[M][N];
int gdzie[N];
vector <int> T[M];
int res;
int zkz;
vector <int> porob; //rzeczy do wyboru
inline void shift (int k)
{
	int l = tab[k][n-1];
	for (int i = n-1; i>0; i--) tab[k][i] = tab[k][i-1];
	tab[k][0] = l;
}
void ustal (int a)
{
	debug ("ustal %d: ", a);
	rep(i,0,a) debug ("%d ", gdzie[i]);
	debug ("\n");
	
	
	if (a==n)
	{
		vector <int> wor;
		rep(i,0,n) T[gdzie[i]].clear();
		rep(i,0,n) 
		{
			if (T[gdzie[i]].empty()) wor.pb(gdzie[i]);
			T[gdzie[i]].pb(i);
		}
		int suma = 0;
		for (int s: wor)
		{
			debug ("dla %d: ", s);
			int naj = 0;
			rep(i,0,n) 
			{
				int d = 0;
				for (int t: T[s]) d+=tab[s][(t+i)%n];
				naj = max(d, naj);
			}
			suma+=naj;
			debug (" = %d\n", naj);
		}
		debug ("wynik to %d\n", suma);
		
		res =max(suma, res);
		return;
	}
	if (zkz==a) 
	{
		ustal(a+1);
		return;
	}
	
	for (int i: porob)
	{
		gdzie[a] = i;
		ustal(a+1);
	}
}
void choose (int b, int a)
{
	if (a<=0)
	{
		debug ("\nwybralem: ");
		for (int s: porob) debug ("%d ", s);
		debug ("\n");
		ustal(1);
		return;
	}
	
	rep(i,b,m)
	{
		porob.pb(i);
		choose(i,a-1);
		porob.pop_back();
	}
}
int main ()
{
	int t;
	scanf ("%d", &t);
	rep(i,0,M) T[i].reserve(4);
	rep(q,0,t)
	{
		scanf ("%d %d", &n, &m);
		res =0;
		int naj = -1, B = 0;
		rep(i,0,n) rep(j,0,m) 
		{
			scanf ("%d", &tab[j][i]);
			if (tab[j][i]>B)
			{
				B = tab[j][i];
				naj  = j;
			}
		}
		gdzie[0] = naj;
		while (B!=tab[naj][0]) shift(naj);
		
		//4 rozne
		vector <int> best;
		rep(i,0,m)
		{
			int b = 0;
			rep(j,0,n) b = max(b, tab[i][j]);
			best.pb(b);
		}
		
		if (n==1)
		{
			printf ("%d\n", B);
			continue;
		}
		
		sort(best.begin(), best.end());
		reverse(best.begin(), best.end());
		int suma = 0;
		rep(i,0,min((int)best.size(), n))
		{
			suma+=best[i];
		}
		res = suma;
		
		//naj jest gdzies jeszcze
		vector <int> all;
		rep(i,0,m) all.pb(i);
		porob= all;
		rep(i,1,n)
		{
			gdzie[i] = naj;
			zkz = i;
			ustal(1);
		}
		zkz = -1;
		//nie ma 3 tylko 2
		porob.clear();
		choose(0, n-2);
		
		printf ("%d\n", res);
	}
}
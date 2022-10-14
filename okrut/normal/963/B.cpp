#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug printf
using namespace std; 
typedef long long ll;
typedef long double ld;
 
const int N = 2e5+100;
vector <int> graf[N];
int Przed[N];

void dfs (int a, int b)
{
	int st = 0;
	int przed = 0;
	for (int s: graf[a]) if (s!=b)
	{
		dfs(s, a);
		st++;
		przed+=Przed[s];
	}
	Przed[a] = (st ^ przed) & 1;
}

void pisz (int a, int b)
{
	for (int s: graf[a]) if (s!=b) if (Przed[s])
	{
		pisz(s, a);
	}
	printf ("%d\n", a);
	for (int s: graf[a]) if (s!=b) if (!Przed[s])
	{
		pisz(s, a);
	}
}

int main ()
{
	int n;
	scanf ("%d", &n);
	rep(i,1,n+1)
	{
		int a;
		scanf ("%d", &a);
		if (a>0)
		{
			graf[a].pb(i);
			graf[i].pb(a);
		}
	}
	
	dfs(1,0);
	if (Przed[1]) printf ("NO\n");
	else
	{
		printf ("YES\n");
		pisz(1,0);
	}
}
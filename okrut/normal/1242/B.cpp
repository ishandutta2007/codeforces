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

vector <set <int> > zkz;
set <int> brak;

int main ()
{
	int n, m;
	scanf ("%d %d", &n, &m);
	zkz.resize(n+1);
	
	rep(i,1,n+1) brak.insert(i);
	
	
	
	rep(i,0,m)
	{
		int a, b;
		scanf ("%d %d", &a, &b);
		zkz[a].insert(b);
		zkz[b].insert(a);
	}
	queue <int> kol;
	
	int res = -1;
	
	while (!brak.empty())
	{
		res++;
		int s = *brak.begin();
		kol.push(s);
		brak.erase(s);
		while (!kol.empty())
		{
			int v = kol.front();
			kol.pop();
			vector <int> usun;
			for (int b: brak) if (zkz[v].count(b)==0)
			{
				kol.push(b);
				usun.pb(b);
			}
			for (int b: usun) brak.erase(b);
		}
	}
	printf ("%d\n", res);
}
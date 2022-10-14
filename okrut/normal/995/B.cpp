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



int main ()
{
	//ios_base::sync_with_stdio(false);
	int n;
	scanf ("%d", &n);
	vector <int> tab(2*n), Cnt(n+1, 0);
	for (int &a: tab) scanf ("%d", &a);
	int res = 0;
	rep(i,0,n*2)
	{
		int a = tab[i];
		if (Cnt[a]==1) continue;
		map <int, int> mapa;
		rep(j,i+1,n*2)
		{
			if (tab[j]==a) break;
			mapa[tab[j]]++;
		}
		for (auto p: mapa)
		{
			if (p.se==2)
			{
				res+=2;
			}
			if (p.se==1)
			{
				res += Cnt[p.fi];
			}
		}
		Cnt[a]++;
	}
	printf ("%d\n", res);
}
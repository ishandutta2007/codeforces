#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define debug printf

typedef long long ll;
typedef pair<int, int> pii;

vector <int> darmo;
vector <pii> tab;
vector <bool> done;
vector <int> wolne;
int n, k;
int main()
{
	scanf ("%d %d", &n, &k);
	darmo.resize(n);
	tab.resize(n);
	done.resize(k+1, false);
	ll res=0;
	rep(i,0,n) scanf ("%d", &darmo[i]);
	rep(i,0,n)
	{
		scanf ("%d", &tab[i].fi);
		tab[i].se=i;
	}
	sort(tab.begin(), tab.end());
	reverse(tab.begin(), tab.end());
	rep(i,0,n)
	{
		if (!done[darmo[tab[i].se]])
		{
			done[darmo[tab[i].se]]=true;
		}
		else wolne.pb(tab[i].fi);
	}
	sort(wolne.begin(), wolne.end());
	int x=0;
	rep(i,1,k+1) if (!done[i])
	{
		res+=(ll)wolne[x];
		x++;
	}
	printf ("%lld\n", res);
	return 0;
}
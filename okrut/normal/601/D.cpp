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
vector <set <ll> > wor;
vector <vector <int> > graf;
vector <int> dod, znak; //poddrzewo
string lett;
int n;
const ll pod=29, mod=1e12+1123;
pair <int, int> best;
string s;
void dfs (int a, int b, ll hasz=0)
{
	ll moj=(hasz*pod+lett[a-1]-'a'+1)%mod;
	debug ("%d %d %c ", a, b, lett[a-1]);
	rep(i,0,(int)graf[a].size()) if (graf[a][i]!=b)
	{
		dfs(graf[a][i], a, moj);
	}
	if ((a!=1 && graf[a].size()==1) || (a==1 && graf[a].size()==0)) znak[a]=a;
	else
	{
		debug ("line 30 %d \n", a);
		pair <int, int> maks=mp(0,0);
		rep(i,0,(int)graf[a].size()) if (graf[a][i]!=b)
		{
			debug ("a moze z %d %d\n", graf[a][i], znak[graf[a][i]]);
			if ((int)wor[znak[graf[a][i]]].size()>maks.fi)
			{
				debug ("a jasne\n");
				maks.fi=wor[znak[graf[a][i]]].size();
				maks.se=graf[a][i];
			}
		}
		znak[a]=znak[maks.se];
		debug ("nasz znak to %d\n", znak[a]);
		rep(i,0,(int)graf[a].size()) if (graf[a][i]!=maks.se) if (graf[a][i]!=b)
		{
			for (set<ll>::iterator it=wor[znak[graf[a][i]]].begin(); it!=wor[znak[graf[a][i]]].end(); it++) wor[znak[a]].insert(*it);
			wor[znak[graf[a][i]]].clear();
		}
	}
	debug ("lien 45 %d\n", a);
	wor[znak[a]].insert(moj);
	if (wor[znak[a]].size()+dod[a]>best.fi) best=mp(wor[znak[a]].size()+dod[a], 1);
	else if (wor[znak[a]].size()+dod[a]==best.fi) best.se++;
}
int main ()
{
	ios_base::sync_with_stdio(false);
	cin>>n;
	graf.resize(n+1);
	dod.resize(n+1);
	znak.resize(n+1, -1); //oto indeks 
	rep(i,1,n+1) cin>>dod[i];
	wor.resize(n+1);
	cin>>lett;
	int a, b;
	rep(i,1,n)
	{
		cin>>a >>b;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	best=mp(0,0);
	dfs(1, -1);
	cout <<best.fi <<"\n" <<best.se <<"\n";	
}
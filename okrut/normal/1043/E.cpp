#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define debug //
using namespace std;
typedef long long ll;
vector <pair <pair <int,int>, int> > tab;
vector <long long> sum;
vector <pair <int, ll> > wyn;
int n, m;
int main ()
{
	ios_base::sync_with_stdio(false);
	cin>>n >>m;
	tab.resize(n);
	rep(i,0,n)
	{
		cin>>tab[i].fi.fi >>tab[i].fi.se;
		tab[i].se=i;
	}
	sum.resize(n+1,0);
	wyn.resize(n, mp(0,0));
	sort(tab.begin(), tab.end(), [] (pair <pair <int, int>, int> a, pair <pair <int, int>, int> b) {return a.fi.fi-a.fi.se<b.fi.fi-b.fi.se;});
	rep(i,0,n)
	{
		
		wyn[i].se=(ll)i*(ll)tab[i].fi.se+(ll)(n-i-1)*(ll)tab[i].fi.fi;
		sum[i+1]+=(ll)tab[i].fi.fi;
		sum[i]-=(ll)tab[i].fi.se;
		sum[0]+=(ll)tab[i].fi.se;
	}
	ll chan=0;
	rep(i,0,n) 
	{
		chan+=sum[i];
		wyn[i].se+=chan; //te wyniki sa spermutowane
		wyn[i].fi=tab[i].se;
	}
	int a, b;
	sort(wyn.begin(), wyn.end());
	sort(tab.begin(), tab.end(), [] (pair <pair <int, int>, int> a, pair <pair <int, int>, int> b) {return a.se<b.se;});
	debug ("wszyscy sa ok\n");
	debug ("\n");
	rep(i,0,m)
	{
		cin>>a >>b;
		a--; b--;
		wyn[a].se-=(ll)min(tab[a].fi.fi+tab[b].fi.se, tab[a].fi.se+tab[b].fi.fi);
		wyn[b].se-=(ll)min(tab[a].fi.fi+tab[b].fi.se, tab[a].fi.se+tab[b].fi.fi);
	}
	rep(i,0,n) cout<<wyn[i].se <<" ";
	cout<<"\n";
}
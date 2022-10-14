#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug printf
using namespace std;
int lewy[100][100][300];
long long best[100][300];
set <long long> wor;
vector <pair <long long, long long> > light;
vector <long long> pos;
int n;
int gdzie (long long a)
{
	rep(i,0,(int)pos.size()) if (pos[i]==a) return i;
	return -1;
}
int main ()
{
	cin>>n;
	light.resize(n);
	rep(i,0,n)
	{
		cin>>light[i].fi >>light[i].se;
		wor.insert(light[i].fi+light[i].se);
		wor.insert(light[i].fi-light[i].se);
		wor.insert(light[i].fi);
	}
	sort(light.begin(), light.end());
	for (set <long long>::iterator it=wor.begin(); it!=wor.end(); it++) pos.pb(*it);
	rep(i,0,n) rep(j,0,n) rep(l,0,(int)pos.size()) lewy[i][j][l]=l;
	int a, b;
	rep(i,0,n) 
	{
		a=gdzie(light[i].fi+light[i].se);
		b=gdzie(light[i].fi);
		lewy[i][i][a]=min(lewy[i][i][a], b);
		a=gdzie(light[i].fi-light[i].se);
		lewy[i][i][b]=min(lewy[i][i][b], a);
	}
	rep(l,0,n) rep(r,l+1,n) rep(x,0,(int)pos.size())
	{
		lewy[l][r][x]=min(lewy[l][r][x], lewy[r][r][x]);
		rep(t,lewy[r][r][x], x+1) lewy[l][r][x]=min(lewy[l][r][x],lewy[l][r-1][t]);
		lewy[l][r][x]=min(lewy[l][r][x], lewy[l][r-1][x]);
		rep(t,lewy[l][r-1][x], x+1) lewy[l][r][x]=min(lewy[l][r][x], lewy[r][r][t]);
	}
	rep(r,0,n) rep(x,0,(int)pos.size())
	{
		rep(l,0,r+1) //dajemy lewego od l do r
		{
			best[r][x]=max(best[r][x], pos[x]-pos[lewy[l][r][x]]); //sam lewy
			if (l>0) rep(t,0,(int)pos.size()) 
			{
				best[r][x]=max(best[r][x], best[l-1][t]+pos[x]-pos[max(lewy[l][r][x],t)]);
			}
		}
	}
	long long maks=0;
	rep(i,0,(int)pos.size()) maks=max(maks, best[n-1][i]);
	cout <<maks <<"\n";
}
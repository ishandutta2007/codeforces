#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define debug //
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 1e6;
string tab[N];
vector <int> dist[N], stan[N]; //zapalony, czy nie
int n, m; 

bool check (int mid)
{
	queue <pair <int, int> > kol;
	rep(i,0,n)
		{
			stan[i].clear();
			stan[i].resize(m, -1);
		}
		rep(x,0,n) rep(y,0,m) if (dist[x][y]-1 >= mid)
		{
			stan[x][y] = mid;
			if (mid>0) kol.push(mp(x,y));
		}
		
		while (!kol.empty())
		{
			auto p = kol.front();
			kol.pop();
			int x = p.fi, y = p.se;
			rep(xp, x-1, x+2) rep(yp, y-1, y+2)
			{
				if (xp < 0 || xp>=n || yp<0 || yp>=m)
				{
					return false;
				}
				if (stan[xp][yp]==-1)
				{
					stan[xp][yp] = stan[x][y]-1;
					if (stan[xp][yp]>0) kol.push(mp(xp, yp));
				}
			}
		}
		
		rep(i,0,n) rep(j,0,m)
		{
			if (stan[i][j]==-1 && tab[i][j]!='.') return false;
			if (stan[i][j]>=0 && tab[i][j]!='X') return false;
		}
		
		return true;
}

int main ()
{
	cin>>n >>m;
	rep(i,0,n) cin>>tab[i];
	
	rep(i,0,n) dist[i].resize(m, 0);
	
	queue <pair <int, int> > kol;
	
	rep(x,0,n) rep(y,0,m) if (tab[x][y]=='X')
	{
		bool adj = false;
		rep(xp, max(0, x-1), min(n,x+2)) rep(yp, max(0, y-1), min(m, y+2)) if (tab[xp][yp]=='.') adj = true;
		
		if (x==0 || x==n-1 || y==0 || y==m-1) adj = true;
		if (adj) 
		{
			kol.push(mp(x, y));
			dist[x][y] = 1;
		} 
	}
	
	while (!kol.empty())
	{
		auto p = kol.front();
		kol.pop();
		int x = p.fi, y = p.se;
		rep(xp, max(0, x-1), min(n,x+2)) rep(yp, max(0, y-1), min(m, y+2)) if (tab[xp][yp]=='X' && dist[xp][yp]==0)
		{
			dist[xp][yp] = dist[x][y]+1;
			kol.push(mp(xp, yp));
		}
	}
	
	
	int l = 0, r = n;
	while (l<r)
	{
		int mid = (l+r)/2;
		
		if (check(mid+1)) l = mid+1;
		else r = mid;
	}
	assert(check(l));
	printf ("%d\n", l);
	rep(i,0,n)
	{
		rep(j,0,m) 
		{
			if (dist[i][j]-1>=l) cout<<"X";
			else cout<<".";
		}
		cout<<"\n";
	}
	
}
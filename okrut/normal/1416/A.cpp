#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;


int main ()
{
	int t;
	scanf ("%d", &t);	
	rep(q,0,t)
	{
		int n;
		scanf ("%d", &n);
		vector <vector <int> > pos(n);
		rep(i,0,n) pos[i].pb(-1);
		rep(i,0,n)
		{
			int a;
			scanf ("%d", &a);
			a--;
			pos[a].pb(i);
		}
		rep(i,0,n) pos[i].pb(n);
		
		vector <pair <int, int> > maks(n, {0,0}); /* maximal break */
		
		rep(i,0,n)
		{
			maks[i].se = i;
			rep(j,1,(int)pos[i].size()) maks[i].fi = max(maks[i].fi, pos[i][j] - pos[i][j-1]);
			maks[i].fi--;
		}
		
		sort(maks.begin(), maks.end());
		
		int res = n;
		auto it = maks.begin();
		
		rep(i,0,n)
		{
			while (it!=maks.end() and it->fi==i)
			{
				res = min(res, it->se);
				it++;
			}
			printf ("%d ", (res<n ? res+1 : -1));
		}
		printf ("\n");
	}
}
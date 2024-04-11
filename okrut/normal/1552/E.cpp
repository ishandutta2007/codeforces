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
	//ios_base::sync_with_stdio(false);
	int n, k;
	scanf ("%d %d", &n, &k);
	vector <vector <int> > kols(n);
	
	rep(i,1,n*k+1) {
		int c;
		scanf ("%d", &c);
		kols[c-1].pb(i);
	}
	
	
	int left = 0;
	int right;
	vector <pair <int, int> > ans(n);
	
	while (left < n) {  
		right = min(n, left + k - 1);
		
		rep(i,0,right - left) {
			
			int best = n*k+10;
			int ind;
			
			rep(j,left,right) if (!kols[j].empty()) if (best > kols[j][i+1]) {
				ind = j;
				best = kols[j][i+1];
			}
			
			
			ans[ind] = {kols[ind][i], kols[ind][i+1]};
			kols[ind].clear();
		}
		left = right;
	}
	
	for (auto p: ans) printf ("%d %d\n", p.fi, p.se);
}
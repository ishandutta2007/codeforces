#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) //fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;


int main ()
{
	//ios_base::sync_with_stdio(false);
	int t;
	scanf ("%d", &t);
	rep(q,0,t) {
		int n, k;
		scanf ("%d %d", &n, &k);
		
		vector <pair <int, int> > chords(k);
		for (auto &p: chords) {
			scanf ("%d %d", &p.fi, &p.se);
			p.fi--;
			p.se--;
		}
		
		vector <int> nums(n*2);
		rep(i,0,n*2) nums[i] = i;
		for (auto p: chords) {
			nums[p.fi] = 1e6;
			nums[p.se] = 1e6;
		}
		sort(nums.begin(), nums.end());
		
		rep(i,0,n - k) {
			chords.pb({nums[i], nums[n - k + i]});
			debug ("%d %d\n", chords.back().fi, chords.back().se);
		}
		
		int x = 0;
		rep(a,0,n) rep(b,a+1,n) {
		
			int a2 = chords[a].se - chords[a].fi;
			int b1 = chords[b].fi - chords[a].fi;
			int b2 = chords[b].se - chords[a].fi;
			if (a2 < 0) a2 += 2*n;
			if (b1 < 0) b1 += 2*n;
			if (b2 < 0) b2 += 2*n;
			
			if (b1 > b2) swap(b1, b2);
			
			if (b1 < a2 and b2 > a2) {
				x++;
			}
		}
		
		printf ("%d\n", x);
	}
}
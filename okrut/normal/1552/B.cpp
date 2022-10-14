#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 5e4+10;

int Rnk[N][5];

static inline bool better (int a, int b)
{
	int cnt = 0;
	rep(i,0,5) cnt += (Rnk[a][i] < Rnk[b][i]);
	return cnt > 2;
}

int main ()
{
	//ios_base::sync_with_stdio(false);
	int t;
	scanf ("%d", &t);
	
	rep(q,0,t) {
		int n;
		scanf ("%d", &n);
		rep(i,0,n) rep(j,0,5) scanf ("%d", &Rnk[i][j]);
		
		int best = 0;
		rep(i,1,n) {
			if (better(i, best)) best = i;
		}
		
		rep(i,0,n) if (better(i, best)) {
			best = -2;
			break;
		}
		printf ("%d\n", best+1);
	}
}
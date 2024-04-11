#include <bits/stdc++.h>
#define pb push_back
#define rep(i,a,b) for (int i = a; i < b; i++)
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 5e5;
const int L = 18;

pair <int, int> MX[L][N], MN[L][N];
int Lvl[N];

int getmin(int l, int r)
{
	int lvl = Lvl[r - l + 1];
	return min(MN[lvl][l], MN[lvl][r - (1<<lvl) + 1]).se;
}

int getmax(int l, int r)
{
	int lvl = Lvl[r - l + 1];
	return max(MX[lvl][l], MX[lvl][r - (1<<lvl) + 1]).se;
}

int calc(int l, int r)
{
	if (r == l) return 0;
	if (r == l+1) return 1;
	
	int a = getmin(l,r);
	int b = getmax(l,r);
	if (a > b ) swap(a,b);
	
	return calc(l,a) + 1 + calc(b,r);
}

int main()
{
	{
		int lvl = 0;
		for (int i = 0; i < N; i++) {
			if (i == 2 * (1<< lvl)) {
				lvl++;
			}
			Lvl[i] = lvl;
		}
	
	}
	
	int t;
	scanf ("%d", &t);
	rep(q,0,t) {
		int n;
		scanf ("%d", &n);
		rep(i,0,n) {
			scanf ("%d", &MX[0][i].fi);
			MX[0][i].se = i;
			MN[0][i] = MX[0][i];
		}
		
		rep(lvl,0,L-1) rep(i,0,n) {
			MX[lvl+1][i] = max(MX[lvl][i], MX[lvl][i + (1<<lvl)]);
			MN[lvl+1][i] = min(MN[lvl][i], MN[lvl][i + (1<<lvl)]);
		}
		
		
		int ans = calc(0, n-1);
		printf ("%d\n", ans);
	}
}
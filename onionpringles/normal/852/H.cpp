#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long lint;
const int MAXN = 205;

lint ccw(pi a, pi b, pi c){
	int dx1 = b.first - a.first;
	int dy1 = b.second - a.second;
	int dx2 = c.first - a.first;
	int dy2 = c.second - a.second;
	return 1ll * dx1 * dy2 - 1ll * dy1 * dx2;
}

int n, k;
pi a[MAXN];
lint dp[MAXN][MAXN];
bool has[MAXN][MAXN];
int lo[MAXN][MAXN], ls[MAXN];
int hi[MAXN][MAXN], hs[MAXN];

double solve(int s){
	sort(a, a + s, [&](const pi &p, const pi &q){
		return ccw(a[s], p, q) > 0;
	});
	memset(has, 0, sizeof(has));
	for(int i=0; i<s-1; i++){
		pi w = a[i+1];
		for(int j=i+2; j<s; j++){
			if(ccw(a[i], a[j], w) < 0){
				w = a[j];
			}
			else has[i][j] = 1;
		}
	}
	for(int i=0; i<s; i++){
		ls[i] = hs[i] = 0;
		for(int j=0; j<i; j++){
			lo[i][ls[i]] = j;
			ls[i]++;
		}
		for(int j=i+1; j<s; j++){
			hi[i][hs[i]] = j;
			hs[i]++;
		}
		sort(lo[i], lo[i] + ls[i], [&](const int &p, const int &q){
			return ccw(a[i], a[p], a[q]) < 0;
		});
		sort(hi[i], hi[i] + hs[i], [&](const int &p, const int &q){
			return ccw(a[i], a[p], a[q]) < 0;
		});
	}
	for(int i=0; i<s; i++){
		for(int j=i+1; j<s; j++){
			if(has[i][j]) dp[i][j] = -1e18;
			else dp[i][j] = ccw(a[s], a[i], a[j]);
		}
	}
	for(int i=1; i<=k-3; i++){
		lint nxt[MAXN][MAXN];
		for(int j=s-1; j>=0; j--){
			lint curmx = -1e18;
			int pos = 0;
			for(int k=0; k<ls[j]; k++){
				int cur = lo[j][k];
				while(pos < hs[j] && ccw(a[cur], a[j], a[hi[j][pos]]) > 0){
					curmx = max(curmx, dp[j][hi[j][pos]]);
					pos++;
				}
				nxt[cur][j] = curmx;
			}
			// sweep from left, sweep from right
		}
		for(int j=0; j<s; j++){
			for(int k=j+1; k<s; k++){
				if(has[j][k]) nxt[j][k] = -1e18;
				else nxt[j][k] += ccw(a[s], a[j], a[k]);
				dp[j][k] = nxt[j][k];
			}
		}
	}
	lint ret = -1e18;
	for(int i=0; i<s; i++){
		for(int j=i+1; j<s; j++){
			ret = max(ret, dp[i][j]);
		}
	}
	return ret;
}

int main(){
	cin >> n >> k;
	for(int i=0; i<n; i++){
		cin >> a[i].first >> a[i].second;
	}
	sort(a, a+n);
	double ans = 0;
	for(int i=k-1; i<n; i++){
		ans = max(ans, 0.5 * solve(i));
	}
	printf("%.2f", ans);
}
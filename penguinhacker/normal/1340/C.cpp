#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int INF=1e9;
int n, m, g, r;
int dp[10000][1000];
int p[10000];
bool vis[10000][1000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		cin >> p[i];
		fill(dp[i], dp[i]+1000, INF);
	}
	sort(p, p+m);
	cin >> g >> r;
	dp[0][0]=0;
	deque<ar<int, 2>> q;
	q.push_back({0, 0});
	int ans=INF;
	while(!q.empty()) {
		ar<int, 2> temp=q[0]; q.pop_front();
		int a=temp[0], b=temp[1];
		int old=dp[a][b];
		if (vis[a][b]) {
			continue;
		}
		vis[a][b]=1;
		
		if (a==m-1) {
			int cur=old*(g+r)+(g-b);
			if (b==0) {
				cur-=g+r;
			}
			ans=min(ans, cur);
		}

		if (b==0) {
			b+=g;
		}
		if (a>0) {
			int need=p[a]-p[a-1];
			if (need==b&&old+1<dp[a-1][0]) {
				dp[a-1][0]=old+1;
				q.push_back({a-1, 0});
			}
			else if (need<b&&old<dp[a-1][b-need]) {
				dp[a-1][b-need]=old;
				q.push_front({a-1, b-need});
			}
		}
		if (a+1<m) {
			int need=p[a+1]-p[a];
			if (need==b&&old+1<dp[a+1][0]) {
				dp[a+1][0]=old+1;
				q.push_back({a+1, 0});
			}
			else if (need<b&&old<dp[a+1][b-need]) {
				dp[a+1][b-need]=old;
				q.push_front({a+1, b-need});
			}
		}
	}
	if (ans==INF) {
		ans=-1;
	}
	cout << ans;
	return 0;
}
//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 1.5e5 + 100, maxm = 300 + 10;
LL dp[2][maxn], a[maxm], b[maxm], t[maxm];
LL n, m, d, lasttime;

inline LL Abs(LL x){return x < 0 ? -x : x;};

int main(){
	scanf("%d%d%d", &n, &m, &d);
	for(int i = 0; i < m; i++){
		scanf("%d%d%d", a + i, b + i, t + i);
		a[i]--, t[i]--;
	}
	for(int i = 0; i < m; i++){
		int pre = i & 1;
		int cur = pre ^ 1;
		int r = 0;
		deque<int> deq;
		for(int j = 0; j < n; j++){
			while(r < n and r <= j + d * (t[i] - lasttime)){
				while(sz(deq) and dp[pre][deq.front()] < dp[pre][r]) deq.pop_front();
				deq.push_front(r);
				r++;
			}
			while(sz(deq) and deq.back() < j - d * (t[i] - lasttime)) deq.pop_back();
			dp[cur][j] = dp[pre][deq.back()] + b[i] - Abs(j - a[i]);
		}
		lasttime = t[i];
	}
	int cur = (m) & 1;
	printf("%I64d", *max_element(dp[cur], dp[cur] + n));
	return 0;
}
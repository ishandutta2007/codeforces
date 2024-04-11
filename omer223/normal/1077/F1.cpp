#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <bitset>
#include <queue>
#include <numeric>
#include <map>


using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

struct maxqueue {
	deque<pll> dq;
	queue<pll> q;
	int time = 0;
	maxqueue() {}
	void push(ll x) {
		q.push({ x,time });
		while (!dq.empty() and dq.back().first <= x)dq.pop_back();
		dq.push_back({ x,time });
		time++;
	}
	ll top() {
		return (q.empty() ? 0 : q.front().first);
	}
	void pop() {
		if (dq.front().second == q.front().second)dq.pop_front();
		q.pop();
	}
	ll getMax() {
		return (dq.empty() ? 0 : dq.front().first);
	}
	void clear() {
		while (!dq.empty())dq.pop_back();
		while (!q.empty())q.pop();
		time = 0;
	}
};

const int sz = 5e3 + 5;
int n, k, x;
ll a[sz], dp[sz][sz];//dp[i][j]==i pictures, until j

int main() {
	fast;
	cin >> n >> k >> x;
	foru(i, 0, n)cin >> a[i + 1];
	foru(i, 1, x + 1) {
		foru(j, 1, n + 1)dp[i][j] = -1;
	}
	foru(j, k, n + 1)dp[0][j] = -1;
	if (n / k > x) {
		cout << -1 << endl;
		return 0;
	}
	maxqueue mq;
	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= n; j++) {
			if (dp[i - 1][j - 1] != -1)dp[i][j] = dp[i - 1][j - 1] + a[j];
			else dp[i][j] = -1;
			ll myt = mq.getMax();
			if (myt != -1)dp[i][j] = max(dp[i][j], myt);
			if (dp[i - 1][j - 1] != -1)mq.push(a[j] + dp[i - 1][j - 1]);
			else mq.push(-1);
			if (j >= k)mq.pop();
		}
		mq.clear();
	}
	cout << dp[x][n] << endl;
	return 0;
}
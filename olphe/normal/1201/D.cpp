#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

//int N,M,K,L,R,H,W;
long long int N, M, K, L, R, H, W;

//constexpr long long int MOD=1000000007;
constexpr long long int MOD = 1000000007;
//constexpr int MOD=998244353;
//constexpr long long int MOD=998244353;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> H >> W >> N >> M;
	long  long int hei = 0;
	vector<vector<int>>place(H);
	for (int i = 0; i < N; i++) {
		cin >> L >> R;
		L--;
		R--;
		hei = max(hei, L);
		place[L].push_back(R);
	}
	for (int i = 0; i < H; i++) {
		if (place[i].empty())continue;
		sort(place[i].begin(), place[i].end());
	}
	vector<int>r(W, W);
	vector<int>l(W, -1);
	for (int i = 0; i < M; i++) {
		cin >> K;
		K--;
		r[K] = K;
		l[K] = K;
	}
	for (int i = 1; i < W; i++)l[i] = max(l[i], l[i - 1]);
	for (int i = W - 2; i >= 0; i--)r[i] = min(r[i], r[i + 1]);
	vector<long long int>dp(W * 3, MOD * MOD);
	vector<long long int>ndp(W * 3, MOD * MOD);
	vector<int>check;
	for (int i = 0; i < W; i++) {
		dp[i + W] = i;
	}
	if (place[0].empty()) {
		for (int i = 0; i < W; i++) {
			if (l[i] == i)check.push_back(i);
		}
	}
	else {
		check.push_back(0);
	}
	for (int i = 0; i < H; i++) {
		if (place[i].empty())continue;
		vector<int>box;
		box.push_back(l[place[i].front()]);
		box.push_back(r[place[i].front()]);
		box.push_back(l[place[i].back()]);
		box.push_back(r[place[i].back()]);
		if (i == hei) {
			box.push_back(place[i].front());
			box.push_back(place[i].back());
		}
		for (auto j : box)ndp[j + W] = MOD * MOD;
		for (auto j : check) {
			if (j < 0 || j >= W)continue;
			if (i == hei) {
				ndp[place[i].front() + W] = min(ndp[place[i].front() + W], dp[j + W] + abs(j - place[i].back()) + abs(place[i].back() - place[i].front()));
				ndp[place[i].back() + W] = min(ndp[place[i].back() + W], dp[j + W] + abs(j - place[i].front()) + abs(place[i].back() - place[i].front()));
			}
			ndp[l[place[i].back()] + W] = min(ndp[l[place[i].back()] + W], dp[j + W] + abs(j - place[i].front()) + abs(place[i].front() - place[i].back()) + abs(place[i].back() - l[place[i].back()]));
			ndp[r[place[i].back()] + W] = min(ndp[r[place[i].back()] + W], dp[j + W] + abs(j - place[i].front()) + abs(place[i].front() - place[i].back()) + abs(place[i].back() - r[place[i].back()]));
			ndp[l[place[i].front()] + W] = min(ndp[l[place[i].front()] + W], dp[j + W] + abs(j - place[i].back()) + abs(place[i].front() - place[i].back()) + abs(place[i].front() - l[place[i].front()]));
			ndp[r[place[i].front()] + W] = min(ndp[r[place[i].front()] + W], dp[j + W] + abs(j - place[i].back()) + abs(place[i].front() - place[i].back()) + abs(place[i].front() - r[place[i].front()]));
		}
		for (auto j : box) {
			if (j < 0 || j >= W)continue;
			dp[j + W] = ndp[j + W];
		}
		check = box;
	}
	long long int ans = MOD * MOD;
	for (auto i : check) {
		if (i < 0 || i >= W)continue;
		ans = min(ans, dp[i + W]);
	}
	cout << ans + hei << endl;
	return 0;
}
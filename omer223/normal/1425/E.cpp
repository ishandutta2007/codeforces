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

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 2e5;
int n, k;
ll add[sz], cost[sz], pre[sz], suf[sz], mnpre[sz], mnsuf[sz], bestSufTake[sz], bestSufTakeFromPre[sz];

void input() {
	cin >> n >> k;
	foru(i, 0, n)cin >> add[i];
	foru(i, 0, n)cin >> cost[i];
}

void initPreSuf() {
	foru(i, 0, n)pre[i] = add[i] + (i ? pre[i - 1] : 0);
	ford(i, n - 1, 0)suf[i] = add[i] + (i != n - 1 ? suf[i + 1] : 0);
	foru(i, 0, n) mnpre[i] = (i ? min(mnpre[i - 1], cost[i]) : cost[i]);
	ford(i, n - 1, 0)mnsuf[i] = (i != n - 1 ? min(mnsuf[i + 1], cost[i]) : cost[i]);
	ford(i, n - 1, 0) bestSufTake[i] = max(bestSufTake[i + 1], suf[i] - cost[i]);
	foru(i, 0, n) {
		if (!i)bestSufTakeFromPre[i] = suf[i] - cost[i];
		else bestSufTakeFromPre[i] = max(bestSufTakeFromPre[i - 1], suf[i] - cost[i]);
	}
	
}

void solveZero() {
	cout << max(0LL,bestSufTake[0]) << endl;
}

void solveEven() {
	ll bst = max(0LL,bestSufTake[0]);
	foru(i, 0, n - 1)bst = max(bst, pre[n - 1] - cost[i]);
	cout << bst << endl;
}

void solveOne() {
	ll bst = max(0LL, bestSufTake[1]);
	for (int i = 1; i < n - 1; i++) bst = max(bst, pre[i] - mnpre[i] + bestSufTake[i + 1]);
	for (int i = 1; i < n - 1; i++) bst = max(bst, max(bestSufTakeFromPre[i - 1] - add[i], bestSufTake[i + 1]) + max(0LL, add[i] - cost[i]));
	cout << bst << endl;
}

void solveOdd() {
	ll bst = max(0LL, bestSufTake[1]);
    ll best = add[0] - cost[0];
    /*for(int i = 1; i < n - 1; ++i)
    {
        bst = max(best + bestSufTake[i+1], bst);
        best = max(best + add[i], add[i] - cost[i]);
    }*/
	ford(i, n - 2, 0) {
		if (i == 1)continue;
		bst = max(bst, pre[n - 1] - cost[i]);
	}
	if (n == 4) {
		bst = max(bst, pre[n - 1] - cost[1]);
		bst = max(bst, pre[n - 1] - cost[0]);
	}
	else {
		bst = max(bst, pre[n - 1] - add[n - 1] - cost[1]);
		foru(i, 0, n) {
			if (i == 1 || i == 2)continue;
			bst = max(bst, pre[n - 1] - add[i] - cost[1]);
		}
	}
    cout << bst << endl;
}

int main() {
	fast;
	input();
	initPreSuf();
	if (k == 0) solveZero();
	else if (k == 1) solveOne();
	else if (k % 2 == 0) solveEven();
	else solveOdd();
	return 0;
}
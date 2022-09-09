#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;

int n, k;

int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);

	scanf("%d%d", &n, &k);

	vector<int> inp;
	for (int i = 0; i < n; ++i) {
	 	int num;
	 	scanf("%d", &num);
	 	inp.puba(num);
	}

	int l = 0, r = INF;

	while (r - l > 1) {
	 	int mid = (r + l) / 2;
	 	ll sum = 0;
	 	for (int val: inp) {
	 	 	sum += max(0, mid - val);
	 	}
	 	if (sum > k) {
	 	 	r = mid;
	 	} else {
	 	 	l = mid;
	 	}
	}

	int lg = l;

	l = 0, r = INF;

	while (r - l > 1) {
	 	int mid = (r + l) / 2;
	 	ll sum = 0;
	 	for (int val: inp) {
	 	 	sum += max(0, val - mid);
	 	}
	 	if (sum > k) {
	 	 	l = mid;
	 	} else {
	 	 	r = mid;
	 	}
	}

	int rg = r;

	if (lg < rg) {
     	cout << rg - lg << "\n";
    } else {
     	ll sum = 0;
     	for (int val: inp) {
     	 	sum += val;
     	}
     	if (sum % n == 0) {
     	 	cout << 0 << "\n";
     	} else {
			cout << 1 << "\n";
     	}
    }

	return 0;
}
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

int n, q;

int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);

	scanf("%d%d", &n, &q);
	int on0 = 0, on1 = 1;

	for (int i = 0; i < q; ++i) {
	 	int t;
	 	scanf("%d", &t);
	 	if (t == 1) {
	 	 	int x;
	 	 	scanf("%d", &x);
	 	 	x = (n + x) % n;
	 	 	if (x & 1) {
	 	 	 	int tmp0 = on0;
	 	 	 	int tmp1 = on1;
	 	 	 	on0 = (tmp1 - x - 1 + n * 2) % n;
	 	 	 	on1 = (tmp0 + 1 - x + n) % n;
	 	 	} else {
	 	 	 	on0 = (on0 - x + n) % n;
	 	 	 	on1 = (on1 - x + n) % n;
	 	 	}
	 	} else {
	 	 	swap(on0, on1);
	 	}
	}

	for (int i = 0; i < n / 2; ++i) {
	 	cout << on0 + 1 << " " << on1 + 1 << " ";
	 	on0 = (on0 + 2) % n;
	 	on1 = (on1 + 2) % n;
	}
	cout << "\n";

	return 0;
}
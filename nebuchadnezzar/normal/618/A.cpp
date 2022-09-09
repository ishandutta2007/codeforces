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
typedef pair <int, int> pii;

int n;

int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);

	scanf("%d", &n);

	vector<int> v;

	for (int i = 0; i < n; ++i) {
	 	v.puba(1);
	 	while (szof(v) > 1) {
	 	 	if (v[szof(v) - 2] == v.back()) {
	 	 		int tmp = v.back();
	 	 	 	v.pop_back();
	 	 	 	v.pop_back();
	 	 	 	v.puba(tmp + 1);
	 	 	} else {
	 	 	 	break;
	 	 	}
	 	}
	}

	//cout << szof(v) << endl;

	for (auto val: v) {
	 	cout << val << " ";
	}
	cout << endl;

	return 0;
}
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
const int MAXN = 1e6 + 5;

int n;
pii res[MAXN];

int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);

	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
	 	int num;
	 	scanf("%d", &num);
	 	res[num].ff++;
	 	res[num].ss = -i;
	}

	pii best = {-1, -1};
	int mem = 0;

	for (int i = 0; i < MAXN; ++i) {
	 	if (best < res[i]) {
	 	 	best = res[i];
	 	 	mem = i;
	 	}
	}

	cout << mem << "\n";

	return 0;
}
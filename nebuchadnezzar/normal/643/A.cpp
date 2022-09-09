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
const int MAXN = 5005;

int n;
int arr[MAXN];
int now[MAXN];
int ans[MAXN];

int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);

	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
	 	scanf("%d", arr + i);
	 	--arr[i];
	}

	for (int i = 0; i < n; ++i) {
	 	pii largest = {-1, 0};
	 	memset(now, 0, sizeof now);
	 	for (int j = i; j < n; ++j) {
	 	 	++now[arr[j]];
	 	 	largest = max(largest, {now[arr[j]], -arr[j]});
	 	 	ans[-largest.ss]++;
	 	}
	}

	for (int i = 0; i < n; ++i) {
	 	cout << ans[i] << " ";
	}
	cout << "\n";

	return 0;
}
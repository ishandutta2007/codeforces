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
const int MAXN = 55;

int n;
int arr[MAXN][MAXN];
int ans[MAXN];

bool used[MAXN];

int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);

	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
	 	int now = 0;
	 	for (int j = 0; j < n; ++j) {
	 	 	scanf("%d", &arr[i][j]);
	 	 	now = max(now, arr[i][j]);
	 	}
	 	ans[i] = now - 1;
	}

	
	for (int i = 0; i < n; ++i) {
	 	if (used[ans[i]]) {
	 	 	ans[i] = -1;
	 	} else {
	 	 	used[ans[i]] = 1;
	 	}
	}

	vector<int> unused;

	for (int i = 0; i < n; ++i) {
	 	if (!used[i]) {
	 	 	unused.puba(i);
	 	}
	}

	for (int i = 0; i < n; ++i) {
	 	if (ans[i] == -1) {
	 	 	ans[i] = unused.back();
	 	 	unused.pop_back();
	 	}
	}

	for (int i = 0; i < n; ++i) {
	 	cout << ans[i] + 1 << " ";
	}
	cout << endl;
    
    for (int i = 0; i < n; ++i) {
     	 for (int j = i + 1; j < n; ++j) {
     	 	//cerr << i << " " << j << endl;
     	  	assert(min(ans[i], ans[j]) + 1 == arr[i][j]);
     	 }
    }

   	return 0;
}
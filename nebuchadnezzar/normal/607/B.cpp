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
const int MAXN = 666;

int n;
int arr[MAXN];
int d[2][MAXN][MAXN];

int rec(int l, int r, int flag) {
 	if (d[flag][l][r] != -1) {
 	 	return d[flag][l][r];
 	}
 	
 	if (l == r) {
 	 	if (flag) {
 	 	 	d[flag][l][r] = 0;
 	 	} else {
 	 	 	d[flag][l][r] = 1;
 	 	}
 	 	return d[flag][l][r];
 	}

 	if (l > r) {
 	 	return d[flag][l][r] = 0;
 	}

 	d[flag][l][r] = r - l + 1;

 	if (flag && arr[l] == arr[r]) {
 	 	d[flag][l][r] = rec(l + 1, r - 1, flag);
 	}

 	if (flag) {
 	 	d[flag][l][r] = min(d[flag][l][r], rec(l + 1, r, 0));
 	 	d[flag][l][r] = min(d[flag][l][r], rec(l + 1, r, 1) + 1);
 	} else {
 		d[flag][l][r] = min(rec(l + 1, r, 0) + 1, d[flag][l][r]);
 	}

 	for (int i = l + 1; i <= r; ++i) {
 	 	if (arr[l] == arr[i]) { 	 		
 	 		if (flag) {
 	 		 	d[flag][l][r] = min(d[flag][l][r], rec(i + 1, r, 0) + rec(l + 1, i - 1, 1));
 	 		 	d[flag][l][r] = min(d[flag][l][r], rec(i + 1, r, 1) + rec(l + 1, i - 1, 1) + 1);
 	 		} else {
 	 		 	d[flag][l][r] = min(d[flag][l][r], rec(l + 1, i - 1, 1) + rec(i + 1, r, 0) + 1);
 	 		}
 	 	}
 	}
 	return d[flag][l][r];
}

int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);

	memset(d, -1, sizeof d);

	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
	 	int num;
	 	scanf("%d", &num);
	 	arr[i] = num;
	}

	cout << rec(0, n - 1, 0) << "\n";
	
	/*
	for (int i = 0; i < n; ++i) {
	 	for (int j = 0; j < n; ++j) {
	 	 	cerr << d[0][i][j] << ":" << d[1][i][j] << " ";
	 	}
	 	cerr << endl;
	}*/

	return 0;
}
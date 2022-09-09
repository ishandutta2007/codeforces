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
const int MAXN = 1e5 + 5;

int n;
char s[MAXN];
int arr[MAXN];

int used[MAXN];

int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);

	scanf("%d", &n);

	scanf("%s", s);
	
	for (int i = 0; i < n; ++i) {
	 	scanf("%d", arr + i);
	}

	int pos = 0;
	while (true) {
	 	if (used[pos]) {
	 	 	cout << "INFINITE\n";
	 	 	return 0;
	 	}
	 	used[pos] = true;
	 	if (s[pos] == '>') {
	 	 	pos += arr[pos];
	 	} else {
	 	 	pos -= arr[pos];
	 	}
	 	if (pos < 0 || pos >= n) {
	 	 	break;
	 	}
	}

	cout << "FINITE\n";

	return 0;
}
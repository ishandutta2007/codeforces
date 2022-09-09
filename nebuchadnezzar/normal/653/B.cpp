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
const int MAXN = 50;

int n, q;
char a[2][MAXN], b[MAXN];
int to[6][6];
int s[10];
int ans = 0;

int rec(int pos) {
	if (pos == n) {
		int last = s[0];
		for (int i = 1; i < n; ++i) {
		 	if (to[last][s[i]] == -1) {
		 	 	return 0;
		 	}
		 	last = to[last][s[i]];
		}
		if (last != 0) {
		 	return 0;
		}
		/*
		for (int i = 0; i < n; ++i) {
		 	cerr << (char) (s[i] + 'a');
		}
		cerr << endl;*/
		ans++;
	 	return 0;
	}
 	for (int i = 0; i < 6; ++i) {
 	 	s[pos] = i;
 	 	rec(pos + 1);
 	}
 	return 0;
}

int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);

	scanf("%d%d", &n, &q);
	memset(to, -1, sizeof to);

	for (int i = 0; i < q; ++i) {
	 	scanf("\n%c%c %c", &a[0][i], &a[1][i], &b[i]);
	 	to[a[0][i] - 'a'][a[1][i] - 'a'] = b[i] - 'a';
	}

	rec(0);

	cout << ans << "\n";

	return 0;
}
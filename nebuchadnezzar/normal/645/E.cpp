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
const ll MOD = 1e9 + 7;

int n, k;
ll end_with[26];
int last[26];
char s[MAXN];
ll d[2][2];

int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);

	scanf("%d%d", &n, &k);
	scanf("%s", s);
	int m = strlen(s);

	memset(last, -1, sizeof last);

	d[1][0] = 1;
	for (int i = 0; i < m; ++i) {
	 	d[0][1] = (d[1][0] - end_with[s[i] - 'a'] + MOD) % MOD;
	 	end_with[s[i] - 'a'] = (end_with[s[i] - 'a'] + d[0][1]) % MOD;
	 	d[1][1] = (d[1][0] + d[0][1]) % MOD;
	 	last[s[i] - 'a'] = i;
	 	//cerr << s[i] - 'a' << endl;

	 	d[0][0] = d[0][1];
	 	d[1][0] = d[1][1];
	}

	for (int i = m; i < n + m; ++i) {
		int mem = -1;
		int best = 1e9; 
	 	for (int j = 0; j < k; ++j) {
	 	 	if (last[j] < best) {
	 	 	 	best = last[j];
	 	 	 	mem = j;
	 	 	}
	 	}

	 	//cerr << mem << endl;

		d[0][1] = (d[1][0] - end_with[mem] + MOD) % MOD;
	 	end_with[mem] = (end_with[mem] + d[0][1]) % MOD;
	 	d[1][1] = (d[1][0] + d[0][1]) % MOD;
	 	last[mem] = i;

	 	d[0][0] = d[0][1];
	 	d[1][0] = d[1][1];
	}

	cout << d[1][0] << "\n";

	return 0;
}
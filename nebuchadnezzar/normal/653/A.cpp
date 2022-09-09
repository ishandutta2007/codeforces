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

int n;

int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);

	scanf("%d", &n);

	vector<int> inp;

	for (int i = 0; i < n; ++i) {
	 	int num;
	 	scanf("%d", &num);
	 	inp.puba(num);
	}

	sort(bend(inp));

	inp.resize(unique(bend(inp)) - inp.begin());

	for (int i = 0; i < szof(inp) - 2; ++i) {
	 	if (inp[i] + 2 == inp[i + 2]) {
	 	 	cout << "YES\n";
	 	 	return 0;
	 	}
	}
	
	cout << "NO\n";

	return 0;
}
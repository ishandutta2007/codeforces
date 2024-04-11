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

int a, b, c;

int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);

	scanf("%d%d%d", &a, &b, &c);

	for (int i = 0; i * a <= c; ++i) {
	 	if ((c - i * a) % b == 0) {
	 	 	cout << "Yes\n";
	 	 	return 0;
	 	}
	}

	cout << "No\n";

	return 0;
}
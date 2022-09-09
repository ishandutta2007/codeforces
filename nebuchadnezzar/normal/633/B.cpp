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

int m;
vector<int> ans;

int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);

	scanf("%d", &m);

	int num2 = 0, num5 = 0;

	for (int i = 1; ; ++i) {
	 	if (min(num2, num5) > m) {
	 	 	break;
	 	}
	 	int tmp = i;
	 	while (tmp % 2 == 0) {
	 	 	tmp /= 2;
	 	 	++num2;
	 	}
	 	while (tmp % 5 == 0) {
	 	 	tmp /= 5;
	 	 	++num5;
	 	}
	 	if (min(num2, num5) == m) {
	 	 	ans.puba(i);
	 	}
	}

	cout << szof(ans) << endl;

	for (int num: ans) {
	 	cout << num << " ";
	}
	cout << endl;

	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long

int N, tc, zs, A[100005];
vector<int> p;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		if (A[i] == 0) tc++, zs++;
		else if (A[i] > 0) tc += abs(A[i] - 1);
		else p.push_back(A[i]);
	}
	sort(p.begin(), p.end(), greater<int>());
	if (p.size() & 1) {
		if (!zs) {
			tc += 1 - p.front();
			for (int i = 1; i < p.size(); i++)
				tc += -1 - p[i];
		} else {
			for (int i : p) tc += -1 - i;
		}

	} else
		for (int i : p) tc += -1 - i;
	cout << tc << '\n';
}
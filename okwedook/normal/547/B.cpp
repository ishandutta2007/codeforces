#include <bits/stdc++.h>

using namespace std;
 
int main() {
	//freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	vector<int> h(n + 2);
	for (int i = 1; i <= n; ++i) cin >> h[i];

	vector<int> prefmin(n + 1, 0), suffmin(n + 2, n + 1);
	stack<int> st;
	st.push(n + 1);
	for (int i = 1; i <= n; ++i) {
		while (h[i] < h[st.top()]) {
			suffmin[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
	st = stack<int>();
	st.push(0);
	for (int i = n; i >= 1; --i) {
		while (h[i] < h[st.top()]) {
			prefmin[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}

	vector<int> maxans(n + 2, 0);
	for (int i = 1; i <= n; ++i)
		if (maxans[suffmin[i] - 1 - prefmin[i]] < h[i])
			maxans[suffmin[i] - 1 - prefmin[i]] = h[i];

	int m = h[1];
	for (int i = 1; i <= n; ++i)
		if (h[i] < m) m = h[i];
	maxans[n] = m;
	for (int i = n - 1; i >= 1; --i)
		if (maxans[i + 1] > maxans[i])
			maxans[i] = maxans[i + 1];
	for (int i = 1; i <= n; ++i) cout << maxans[i] << ' '; 
	//system("pause");
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {

    int strlen;
    cin >> strlen;

	int n;
    cin >> n;
	vector < vector<int> > g(n, vector<int> (n, 1));

	vector<int> deg (n);
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			deg[i] += g[i][j];

	int first = 0;
	stack<int> st;
	st.push (first);
	vector<int> res;
	while (!st.empty() && (int)res.size() < strlen + 10) {
		int v = st.top();
		int i;
		for (i=0; i<n; ++i)
			if (g[v][i])
				break;
		if (i == n)
		{
			res.push_back (v);
			st.pop();
		}
		else
		{
			--g[v][i];
			st.push (i);
		}
	}
    res.pop_back();

    for (int i = 0; i < strlen; i++) {
        cout << (char)('a' + res[i % (int)res.size()]);
    }
    cout << '\n';
    return 0;
}
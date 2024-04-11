#include<bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;
vector<int> g[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		for (int i = 0; i < N; i++){
            g[i].clear();
		}
		for (int i = 0; i < n - 1; i++) {
			int a, b;
			cin >> a >> b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		if (g[x].size() <= 1) {
			cout << "Ayush" << endl;
			continue;
		}
		if (n % 2 == 1){
            cout << "Ashish" << endl;
		}
		else{
            cout << "Ayush" << endl;
		}
	}
	return 0;
}
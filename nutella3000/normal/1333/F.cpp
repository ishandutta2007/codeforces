#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
  
using namespace std;
const int inf = 2e9 + 7;
const int max_n = 5e5 + 3;
int del[max_n];

void build() {
	for(int i = 2;i < max_n;i++) {
		if (del[i] != 0) continue;
		del[i] = i;
		for(int j = i * i;j < max_n;j += i) if (del[j] == 0) del[j] = i;
	}
}

void solve() {
	int n;
	cin >> n;
	build();
	//cout << "aaa" << endl;

	vector<int> a;
	for(int i = 2;i <= n;i++) a.emplace_back(i / del[i]);
	sort(a.begin(), a.end());
	
	//cout << a[0] << " ";

	for(int i = 0;i < a.size();i++) cout << a[i] << " "; 
}




signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cin.tie(0);
    cout.tie(0);
   	ios_base::sync_with_stdio(0);

   	solve();
}
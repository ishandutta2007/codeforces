#include <bits/stdc++.h>

using namespace std;

#define PB push_back

int main(){
	ios_base::sync_with_stdio(false);
	vector<int> v, cnt;
	int n, m, d;
	cin >> n >> m >> d;
	int a[n][m];
	for(int i = 0; i < n * m; i++){
		int x;
		cin >> x;
		v.PB(x);
		a[i / m][i % m] = x;
	}
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	cnt.resize(v.size());
	for(int i = 1; i < v.size(); i++)
		if(v[i] % d != v[i - 1] % d){
			cout << -1 << endl;
			return 0;
		}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cnt[lower_bound(v.begin(), v.end(), a[i][j]) - v.begin()]++;
	int ans = 1e9;
	for(int i = v[0]; i < v.back(); i += d){
		int x = 0;
		for(int j = 0; j < v.size(); j++)
			x += abs((v[j] - i) / d) * cnt[j];
		if(x < ans)
			ans = x;
	}
	cout << (ans == 1e9 ? 0 : ans) << endl;
	return 0;
}
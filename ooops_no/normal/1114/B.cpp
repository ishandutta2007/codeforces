#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#define ll long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.precision(20);
	int n, m, k;
	cin >> n >> m >> k;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v[i] = make_pair(a, i);
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	ll cnt = 0;
	vector<int> ind;
	for (int i = 0; i < m*k; i++) {
		cnt += v[i].first;
		ind.push_back(v[i].second);
	}
	sort(ind.begin(), ind.end());
	int need = ind.size() / k;
	cout << cnt << endl;
	for (int i = need; i < ind.size(); i += need) {
		cout << ind[i - 1] + 1 << " ";
	}
}
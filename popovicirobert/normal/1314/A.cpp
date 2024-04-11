#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & (-x))

using namespace std;



int main() {
#ifdef HOME
	ifstream cin("C.in");
	ofstream cout("C.out");
#endif
	//ifstream cin(".in");
	//ofstream cout(".out");
	int i, n;
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n;
	vector <pair <int, int>> arr(n);
	for(i = 0; i < n; i++) {
		cin >> arr[i].first;
	}
	for(i = 0; i < n; i++) {
		cin >> arr[i].second;
	}

	sort(arr.begin(), arr.end());
	arr.push_back({2e9, 0});

	multiset <pair <int, int>> mst;
	ll ans = 0;
	int val = 0;
	i = 0;
	while(i < n) {
		int j = i;
		while(j < n && arr[i].first == arr[j].first) {
			mst.insert({arr[j].second, arr[j].first});
			j++;
		}
		val = max(val, arr[i].first);
		while(val < arr[j].first && mst.size()) {
			auto it = prev(mst.end());
			ans += 1LL * (val - it -> second) * it -> first;
			//cerr << val << " " << it -> second << " " << it -> first << "\n";
			mst.erase(it);
			val++;
		}
		i = j;
	}
	cout << ans;

	return 0;
}
/*
_NUUUUUUU_
*/

#include<iostream>
#include<algorithm>
#include<vector>;
#include<map>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.precision(20);
	ll n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int r = n - 1;
	int l = 0;
	ll cnt = 0;
	sort(v.begin(),v.end());
	if (v.size() % 2 == 0) {
		while (l < r) {
			cnt += (v[l] + v[r])*(v[l] + v[r]);
			l++;
			r--;
		}
		cout << cnt;
	}
}
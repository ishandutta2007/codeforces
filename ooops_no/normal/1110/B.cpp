#include<vector>
#include<iostream>
#include<algorithm>

#define ll long long

using namespace std;


int main() {
	ll n, m, k;
	cin >> n >> m >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	vector<int> nw;
	for (int i = 1; i < n; i++) {
		nw.push_back(v[i] - v[i - 1]);
	}
	sort(nw.begin(), nw.end());
	int cnt = n, i = 0;
	while (n != k) {
		cnt += nw[i] - 1;
		n--;
		i++;
	}
	cout << cnt;
}
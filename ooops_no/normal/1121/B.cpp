/*
_NUUUUUUU_
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<iterator>
#include<map>
using namespace std;

#define pb push_back
typedef long long ll;



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> v(n + 1), c(2e5 + 1);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			c[v[i] + v[j]]++;
		}
	}
	int mx = 0;
	for (int i = 2; i <= 2e5; i++) {
		mx = max(mx, c[i]);
	}
	cout << mx;
}
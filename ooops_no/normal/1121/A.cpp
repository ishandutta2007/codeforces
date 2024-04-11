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
	int n, b, c;
	cin >> n >> b >> c;
	vector<int> v(b + 1);
	vector<pair<int,int>> v1(n);
	vector<bool> u(b + 1);
	for (int i = 0; i < n; i++) {
		cin >> v1[i].first;
	}
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v1[i].second = a;
		v[a] = max(v[a], v1[i].first);
	}
	int cnt = 0;
	for (int i = 0; i < c; i++) {
		int a;
		cin >> a;
		if (v1[a-1].first < v[v1[a - 1].second]) {
			cnt++;
		}
		else {
			if (!u[v1[a - 1].second]) {
				u[v1[a - 1].second] = 1;
			}
		}
	}
	cout << cnt;
}
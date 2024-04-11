#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <numeric>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;
	ll ans=0;
	int last=0;
	int cur=0;
	for (int i : a) {
		if (i!=last) {
			last=i;
			cur=0;
		}
		ans+=++cur;
	}
	cout << ans;
	return 0;
}
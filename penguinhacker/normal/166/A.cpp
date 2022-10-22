#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

struct custSort {
	bool operator()(pair<int,int> a, pair<int,int> b) {
		return a.first!=b.first?a.first>b.first:a.second<b.second;
	}
};

int n, k;
map<pair<int, int>, int, custSort> mp;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	for (int i=0; i<n; ++i) {
		pair<int, int> temp;
		cin >> temp.first >> temp.second;
		mp[temp]++;
	}
	for (auto x : mp) {
		k-=x.second;
		if (k<=0) {
			cout << x.second;
			break;
		}
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int n, m, bestcandidate, best=0; //best is maximum polls kept
vector<pair<int,int>> candidates[100]; //index second

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		int a[100];
		for (int j=0; j<n; ++j)
			cin >> a[j];
		for (int j=0; j<n-1; ++j)
			candidates[j].push_back({a[j]-a[n-1],i});
	}

	for (int i=0; i<n-1; ++i)
		sort(candidates[i].rbegin(), candidates[i].rend());

	for (int i=0; i<n-1; ++i) {
		int current = 0;
		for (int j=0; j<m; ++j) {
			current += candidates[i][j].first;
			if (current<0)
				break;
			if (j+1>best) {
				best = j+1;
				bestcandidate=i;
			}
		}
	}

	if (best==0) {
		cout << m << '\n';
		for (int i=1; i<=m; ++i)
			cout << i << ' ';
	}
	else {
		cout << m-best << '\n';;
		set<int> remain;
		for (int i=1; i<=m; ++i)
			remain.insert(i);
		for (int i=0; i<best; ++i) {
			int value = candidates[bestcandidate][i].second;	
			remain.erase(value+1);
		}
		for (const int& i : remain)
			cout << i << ' ';
		cout << '\n';
	}
	return 0;
}
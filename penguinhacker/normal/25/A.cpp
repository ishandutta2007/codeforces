#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int n;
vector<int> odd, even;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0, x; i<n; ++i) {
		cin >> x;
		if (x&1)
			odd.push_back(i+1);
		else
			even.push_back(i+1);
	}

	if (odd.size() == 1)
		cout << odd[0];
	else
		cout << even[0];
	return 0;
}
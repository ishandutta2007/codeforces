#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>
const int MOD=1e9+7;

int n, k, ansl, ansr, a[100000]; //ans for left bound
map<int, int> num;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		num[a[i]]++;
	}
	if (num.size()<k) {
		cout << "-1 -1";
		return 0;
	}

	int x=num.size();
	for (int i=0; i<=n; ++i) {
		if (x<k) {
			ansl=i;
			x++;
			num[a[i-1]]++;
			break;
		}
		num[a[i]]--;
		if (num[a[i]]==0)
			x--;
	}
	for (int i=n-1; i>=0; --i) {
		num[a[i]]--;
		if (num[a[i]]==0) {
			ansr=i+1;
			break;
		}
	}
	cout << ansl << ' ' << ansr;
	return 0;
}
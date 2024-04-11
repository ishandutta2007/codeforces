#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>
const int MOD=1e9+7;

int n, a[100000], ans=INT_MAX;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	sort(a, a+n);
	
	int rb=0;
	for (int i=0; i<n; ++i) {
		for (int j=rb+1; j<n; ++j) {
			rb=j;
			if (a[j]>2*a[i]) {
				rb--;
				break;
			}
			ans = min(ans, n-(rb-i+1));
		}
	}
	cout << ans;
	return 0;
}
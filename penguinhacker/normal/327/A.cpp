#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, a[100];

int main() {
	cin >> n;
    int ans = 0;
    for (int i=0; i<n; ++i) {
        cin >> a[i];
        if (a[i]==1) {
			ans++;
			a[i]=-1;
		}
		else a[i]=1;
    }
	
	int sum=0, best=-1;
	for (int i=0; i<n; ++i) {
		sum = max(sum+a[i], a[i]);
		best = max(best, sum);
	}
    cout << ans+best << '\n';
	return 0;
}
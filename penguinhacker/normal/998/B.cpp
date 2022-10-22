#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n, B, a[100];
	cin >> n >> B;
	for (int i=0; i<n; ++i) cin >> a[i];

    vector<int> costs;
    int count = 0;
    for (int i=0; i<n-1; ++i) {
        if (a[i]%2==0) count++;
        else count--;
        if (count == 0) costs.push_back(abs(a[i]-a[i+1]));
    }
    sort(costs.begin(), costs.end());

    int ans = 0;
    for (int i : costs) {
        if (B < i) break;
        else {
            ans++;
            B -= i;
        }
    }

    cout << ans << '\n';
	return 0;
}
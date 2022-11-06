#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
    int n; cin >> n;
    int k; cin >> k;
    vector<int> a(n); for (int o = 0; o < n; o++) { cin >> a[o]; }
    sort(a.rbegin(), a.rend());
    if (k > n || (k < n && a[k - 1] == a[k])) {
        cout << -1; return 0;
    } 
    cout << a[k - 1] << " " << a[k - 1];
}
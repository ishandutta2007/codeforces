#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    int pt1 = 0;
    int pt2 = 0;
    ll file1 = a[0];
    ll file2 = b[0];
    int ans = 0;
    while (pt1 < n && pt2 < m) {
        if (file1 == file2) {
            file1 = 0;
            file2 = 0;
            ans++;
            pt1++;
            pt2++;
            file1 += a[pt1];
            file2 += b[pt2];
            continue;
        }
        if (file1 > file2) {
            pt2++;
            file2 += b[pt2];
            continue;
        }
        if (file1 < file2) {
            pt1++;
            file1 += a[pt1];
            continue;
        }
    }
    cout << ans;
    


	return 0;
}
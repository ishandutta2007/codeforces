#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 1e5;

int arr[2 * MAXN + 1];

inline int get(int l, int r) {
    int mx = 0, mn = 1e9;
    for(int i = l; i <= r; i++) {
        mn = min(mn, arr[i]);
        mx = max(mx, arr[i]);
    }
    return mx - mn;
}

multiset <int> mst;

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= 2 * n; i++) {
        cin >> arr[i];
    }
    if(n == 1) {
        cout << 0;
        return 0;
    }
    sort(arr + 1, arr + 2 * n + 1);
    ll ans = 1e18;
    for(i = n; i < 2 * n; i++) {
        if(i == n) {
            ans = min(ans, 1LL * (arr[i] - arr[1]) * (arr[2 * n] - arr[n + 1]));
        }
        else {
            ans = min(ans, 1LL * (arr[i] - arr[1]) * (arr[2 * n] - arr[n]));
        }
    }
    for(i = 2; i < 2 * n; i++) {
        mst.insert(arr[i]);
        if(i >= n + 2) {
            mst.erase(mst.find(arr[i - n]));
        }
        if(i >= n + 1) {
            ans = min(ans, 1LL * (arr[2 * n] - arr[1]) * (*prev(mst.end()) - *mst.begin()));
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}
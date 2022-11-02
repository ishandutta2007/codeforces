#include<bits/stdc++.h>

using namespace std;

mt19937 rnd(51);

#define ll long long
#define pb push_back
#define ld long double

vector<int> upd(vector<int> a, bool need) {
    vector<int> arr;
    for (int i = 0; i + 1 < a.size(); i++) {
        if (a[i + 1] != a[i]) {
            arr.pb(a[i + 1] - a[i]);
        }
    }
    if (need) {
        arr.pb(a[0]);
    }
    sort(arr.begin(), arr.end());
    return arr;
}

int solve(int n, vector<int> a) {
    int cnt_zero = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a.size() == 0) {
            return 0;
        }
        if (cnt_zero > 0) {
            a = upd(a, 1);
        } else {
            a = upd(a, 0);
        }
        cnt_zero = n - i - 1 - (int)(a.size());
    }
    if (cnt_zero > 0) {
        return 0;
    } else {
        return a[0];
    }
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << solve(n, a) << endl;
    }
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll long long

mt19937 rnd(51);

int n, k;

int rev(int a) {
    return n - 1 - a;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        if (k == n - 1 && n == 4) {
            cout << -1 << endl;
            continue;
        } else if (k == 0) {
            for (int i = 0; i < n; i++) {
                if (i < rev(i)) {
                    cout << i << ' ' << rev(i) << endl;
                }
            }
        } else {
            vector<int> arr;
            for (int j = 0; j < 16; j++) {
                if ((1 << j) & k) {
                    arr.pb(rev(1 << j));
                }
            }
            arr.pb(n - 1);
            bool was = 0;
            map<int,int> used;
            for (int j = 15; j >= 0; j--) {
                if ((1 << j) & k) {
                    if (!was) {
                        used[(1 << j)] = used[arr.back()] = 1;
                        cout << (1 << j) << ' ' << arr.back() << endl;
                        arr.pop_back();
                    }
                }
            }
            used[0] = used[arr[0]] = 1;
            cout << 0 << ' ' << arr[0] << endl;
            for (int i = 0; i < n; i++) {
                if (!used[i] && i < rev(i)) {
                    cout << i << ' ' << rev(i) << endl;
                }
            }
        }
    }
    return 0;
}
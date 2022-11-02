#include<bits/stdc++.h>

using namespace std;

mt19937 rnd(51);

#define ll long long
#define pb push_back
#define ld long double

bool prime(int v) {
    for (int i = 2; i * i <= v; i++) {
        if (v % i == 0) {
            return 0;
        }
    }
    return 1;
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
        int n, q;
        cin >> n >> q;
        vector<int> a(n), div;
        int val = n;
        for (int i = 2; i <= val; i++) {
            if (prime(i) && val % i == 0) {
                while (val % i == 0) {
                    val /= i;
                }
                div.pb(n / i);
            }
        }
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<vector<ll>> arr;
        multiset<ll> st{0};
        for (int i = 0; i < div.size(); i++) {
            vector<ll> sum;
            for (int j = 0; j < div[i]; j++) {
                ll ans = 0;
                for (int k = 0; k < n / div[i]; k++) {
                    ans += a[j + k * div[i]];
                }
                sum.pb(ans);
                st.insert(ans * div[i]);
            }
            arr.pb(sum);
        }
        cout << *st.rbegin() << endl;
        for (int i = 0; i < q; i++) {
            int pos, val;
            cin >> pos >> val;
            pos--;
            for (int j = 0; j < div.size(); j++) {
                int ind = pos % div[j];
                st.erase(st.find(arr[j][ind] * div[j]));
                arr[j][ind] = arr[j][ind] - a[pos] + val;
                st.insert(arr[j][ind] * div[j]);
            }
            a[pos] = val;
            cout << *st.rbegin() << endl;
        }
    }
    return 0;
}
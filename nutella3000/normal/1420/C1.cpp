#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
typedef long double ld;

const int inf = 1e15;
const int max_n = 3e5 + 1;

int n;
int a[max_n];
int res = 0;

int f(int id) {
    if (id < 0 || id >= n) return 0;
    if ((id == 0 || a[id - 1] < a[id]) && (id == n - 1 || a[id + 1] < a[id])) return a[id];
    if ((id != 0 && a[id - 1] > a[id]) && (id != n - 1 && a[id + 1] > a[id])) return -a[id];
    return 0;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--) {
        res = 0;
        int q;
        cin >> n >> q;

        for(int i = 0;i < n;i++) {
            cin >> a[i];
        }

        for(int i = 0;i < n;i++) {
            res += f(i);
            //cout << res << " ";
        }

        cout << res << endl;

        while(q--) {
            int l, r;
            cin >> l >> r;
            l--; r--;
            set<int> b;
            for(int i = -1;i <= 1;i++) {
                b.emplace(l + i);
                b.emplace(r + i);
            }

            for(int i : b)
                res -= f(i);

            swap(a[l], a[r]);
            
            for(int i : b)
                res += f(i);

            cout << res << endl;
        }
    }
}
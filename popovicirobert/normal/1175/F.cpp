#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int B = 41;

vector <int> arr;
vector <ull> pw, hsh;

vector <int> vis;

inline void clr(int l, int r) {
    for(int i = l; i <= r; i++) {
        vis[arr[i]] = 0;
    }
}

ll divide(int l, int r) {
    if(l == r) {
        return arr[l] == 1;
    }

    int mid = (l + r) / 2, i;
    ll ans = 0;

    unordered_map <ull, bool> mpl, mpr;

    ull s = 0;
    for(i = mid; i >= l; i--) {
        if(vis[arr[i]]) {
            break;
        }
        s += pw[arr[i]];
        vis[arr[i]] = 1;
        mpl[s] = 1;
    }

    clr(l, mid);

    s = 0;
    for(i = mid + 1; i <= r; i++) {
        if(vis[arr[i]]) {
            break;
        }
        s += pw[arr[i]];
        vis[arr[i]] = 1;
        mpr[s] = 1;
    }

    clr(mid + 1, r);

    int mx = 0;
    s = 0;
    for(i = mid; i >= l; i--) {
        if(vis[arr[i]]) {
            break;
        }
        mx = max(mx, arr[i]);

        s += pw[arr[i]];
        vis[arr[i]] = 1;

        ans += mpr[hsh[mx] - s];
    }

    clr(l, mid);

    mx = 0;
    s = 0;
    for(i = mid + 1; i <= r; i++) {
        if(vis[arr[i]]) {
            break;
        }
        mx = max(mx, arr[i]);

        s += pw[arr[i]];
        vis[arr[i]] = 1;

        ans += mpl[hsh[mx] - s];
    }

    clr(mid + 1, r);

    ans += divide(l, mid) + divide(mid + 1, r);

    return ans;

}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;

    arr.resize(n + 1);
    for(i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    pw.resize(n + 1), hsh.resize(n + 1);
    pw[0] = 1;

    for(i = 1; i <= n; i++) {
        pw[i] = pw[i - 1] * B;
        hsh[i] = hsh[i - 1] + pw[i];
    }

    vis.resize(n + 1);

    cout << divide(1, n);

    //cin.close();
    //cout.close();
    return 0;
}
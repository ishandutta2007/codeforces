#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44


/*const int MOD = 998244353;

inline int lgput(int a, int b) {
    int ans = 1;
    while(b > 0) {
        if(b & 1) ans = (1LL * ans * a) % MOD;
        b >>= 1;
        a = (1LL * a * a) % MOD;
    }
    return ans;
}

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
}

inline void add(int &x, int y) {
    x += y;
    mod(x);
}

inline void sub(int &x, int y) {
    x += MOD - y;
    mod(x);
}

inline void mul(int &x, int y) {
    x = (1LL * x * y) % MOD;
}*/

using namespace std;

struct Move {
    int id1, id2;
    int d;
};

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;

    vector < pair <int, int> > a(n), b(n);
    ll s = 0;
    for(i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
        s += a[i].first;
    }
    for(i = 0; i < n; i++) {
        cin >> b[i].first;
        b[i].second = i;
        s -= b[i].first;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if(s != 0) {
        cout << "NO";
        return 0;
    }

    vector <int> l, r;

    for(i = 0; i < n; i++) {
        if(a[i].first < b[i].first) {
            l.push_back(i);
        }
        else if(a[i].first > b[i].first) {
            r.push_back(i);
        }
    }

    vector <Move> sol;
    i = 0;

    for(auto it : l) {
        while(i < r.size() && a[it].first < b[it].first) {
            int mn = min(b[it].first - a[it].first, a[r[i]].first - b[r[i]].first);

            a[it].first += mn;
            a[r[i]].first -= mn;

            if(a[it].first > a[r[i]].first) {
                cout << "NO";
                return 0;
            }

            sol.push_back({a[it].second, a[r[i]].second, mn});
            if(a[r[i]].first == b[r[i]].first) {
                i++;
            }
        }
    }

    cout << "YES\n";
    cout << sol.size() << "\n";
    for(auto it : sol) {
        cout << it.id1 + 1 << " " << it.id2 + 1 << " " << it.d << "\n";
    }

    return 0;
}
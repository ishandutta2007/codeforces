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

vector <int> p, pos;
vector < pair <int, int> > sol;

inline void myswap(int x, int y) {
    swap(p[x], p[y]);
    swap(pos[p[x]], pos[p[y]]);
    sol.push_back({x, y});
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;

    p.resize(n + 1), pos.resize(n + 1);
    for(i = 1; i <= n; i++) {
        cin >> p[i];
        pos[p[i]] = i;
    }

    for(i = 1; i <= n / 2; i++) {
        if(pos[i] <= n / 2) {
            myswap(pos[i], n);
            myswap(n, i);
        }
        else {
            myswap(pos[i], 1);
            myswap(1, n);
            myswap(n, i);
        }
    }

    for(i = n / 2 + 1; i <= n; i++) {
        if(pos[i] > n / 2) {
            myswap(pos[i], 1);
            myswap(1, i);
        }
        else {
            myswap(pos[i], n);
            myswap(n, 1);
            myswap(1, i);
        }
    }

    cout << sol.size() << "\n";
    for(auto it : sol) {
        cout << it.first << " " << it.second << "\n";
    }

    return 0;
}
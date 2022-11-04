#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44


/*const int MOD = (int) 1e9 + 7;

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
}

inline void add(int &x, int y) {
    x += y;
    mod(x);
}

inline void mul(int &x, int y) {
    x = (1LL * x * y) % MOD;
}*/

using namespace std;

inline int ask(vector <int> a, vector <int> b) {
    cout << a.size() << " " << b.size() << " ";
    for(auto it : a) {
        cout << it << " ";
    }
    for(auto it : b) {
        cout << it << " ";
    }
    cout << endl;

    int ans;
    cin >> ans;

    return ans;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, t;
    //ios::sync_with_stdio(false);
    //cin.tie(0), cout.tie(0);

    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector <int> a, b;
        for(i = 2; i <= n; i++) {
            b.push_back(i);
        }

        int res = 1, mx = ask({1}, b);

        for(int step = 1 << 7; step; step >>= 1) {
            b.clear();
            for(i = 2; i <= res + step; i++) {
                b.push_back(i);
            }
            if(res + step < n && ask({1}, b) < mx) {
                res += step;
            }
        }

        int nod = res + 1;

        b.clear();
        for(i = 1; i <= n; i++) {
            if(i != nod) {
                b.push_back(i);
            }
        }
        mx = ask({nod}, b);

        cout << -1 << " " << mx << "\n";
    }

    return 0;
}
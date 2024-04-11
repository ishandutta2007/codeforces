#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;

const int MAXN = (int) 1e6;

int aib[MAXN + 1];

inline void update(int pos) {
    for(int i = pos; i > 0; i -= lsb(i)) {
        aib[i]++;
    }
}

inline int query(int pos, int n) {
    int ans = 0;
    for(int i = pos; i <= n; i += lsb(i)) {
        ans += aib[i];
    }
    return ans;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, x;
    ios::sync_with_stdio(false);
    cin >> n;
    ll ans = 0;
    for(i = 1; i <= n; i++) {
        cin >> x;
        ans += query(x, n);
        update(x);
    }
    if(ans % 2 == n % 2) {
        cout << "Petr";
    }
    else {
        cout << "Um_nik";
    }
    //cin.close();
    //cout.close();
    return 0;
}
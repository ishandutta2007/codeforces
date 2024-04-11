#include <bits/stdc++.h>
#define ll long long
#define lsb(x) (x & (-x))


using namespace std;

const int MAXN = (int) (1 << 18);

int v[36];

int r1[MAXN + 1];

inline void mod(int &x, int m) {
    if(x >= m)
        x -= m;
}


int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m, conf;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(i = 1; i <= n; i++) {
        cin >> v[i];
        v[i] %= m;
    }
    int sz1 = n / 2, sz2 = (n + 1) / 2;
    int ans = 0;
    for(conf = 0; conf < (1 << sz1); conf++) {
        for(i = 0; i < sz1; i++)
            if(conf & (1 << i)) {
                r1[conf] += v[i + 1];
                mod(r1[conf], m);
            }
        ans = max(ans, r1[conf]);
    }
    std::sort(r1, r1 + (1 << sz1));
    for(conf = 0; conf < (1 << sz2); conf++) {
        int val = 0;
        for(i = 0; i < sz2; i++)
            if(conf & (1 << i)) {
                val += v[i + 1 + sz1];
                mod(val, m);
            }
        ans = max(ans, val);
        int rez = -1;
        for(int pas = 1 << sz1; pas; pas >>= 1)
            if(rez + pas < (1 << sz1) && r1[rez + pas] < m - val)
                rez += pas;
        if(rez >= 0)
            ans = max(ans, val + r1[rez]);
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}
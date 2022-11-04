#include <bits/stdc++.h>
#define ll long long
#define lsb(x) (x & (-x))

using namespace std;


map < pair < pair <int, int>, pair <int, int> >, int> mp;

const int MAXQ = (int) 1e5;
const int MAXN = 2500;
const int B = 666013;

unsigned ll pw[MAXQ + 1];

int n, m;

unsigned ll aib[MAXN + 1][MAXN + 1];


inline void update(int l, int c, unsigned ll val) {
    for(int i = l; i <= n; i += lsb(i))
        for(int j = c; j <= m; j += lsb(j))
            aib[i][j] += val;
}

inline unsigned ll query(int l, int c) {
    unsigned ll ans = 0;
    for(int i = l; i > 0; i -= lsb(i))
        for(int j = c; j > 0; j -= lsb(j))
            ans += aib[i][j];
    return ans;
}


int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, q;
    ios::sync_with_stdio(false);
    cin >> n >> m >> q;

    pw[0] = 1;
    for(i = 1; i <= q; i++)
        pw[i] = pw[i - 1] * B;

    int cnt = 0;
    while(q > 0) {
        q--;

        int t;
        int l1, c1, l2, c2;
        cin >> t >> l1 >> c1 >> l2 >> c2;

        unsigned ll val;

        if(t == 1) {

            mp[{{l1, c1}, {l2, c2}}] = cnt;
            val = pw[cnt];
            cnt++;

            update(l1, c1, val);
            update(l1, c2 + 1, -val);
            update(l2 + 1, c1, -val);
            update(l2 + 1, c2 + 1, val);

        }
        else if(t == 2) {

            val = -pw[mp[{{l1, c1}, {l2, c2}}]];


            update(l1, c1, val);
            update(l1, c2 + 1, -val);
            update(l2 + 1, c1, -val);
            update(l2 + 1, c2 + 1, val);

        }
        else {

            if(query(l1, c1) == query(l2, c2))
                cout << "Yes";
            else
                cout << "No";
            cout << "\n";

        }
    }
    //cin.close();
    //cout.close();
    return 0;
}
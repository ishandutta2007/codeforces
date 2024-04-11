#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

const int MAXVAL = 7000;

bool bad[MAXVAL + 1];

bitset <MAXVAL + 1> a[MAXVAL + 1], b[MAXVAL + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n, q;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    for(i = 2; i <= MAXVAL; i++) {
        for(j = 2; j * j <= i; j++) {
            if(i % (j * j) == 0) {
                bad[i] = 1;
                break;
            }
        }
    }
    for(i = 1; i <= MAXVAL; i++) {
        b[i][i] = 1;
        for(j = 1; i * j <= MAXVAL; j++) {
            if(bad[j] == 0) {
                b[i][i * j] = 1;
            }
        }
        for(j = i; j <= MAXVAL; j += i) {
            a[j][i] = 1;
        }
    }
    cin >> n >> q;
    vector < bitset <MAXVAL + 1> > c(n + 1);
    while(q > 0) {
        q--;
        int type, x, y, z, v;
        cin >> type;
        if(type == 1) {
            cin >> x >> v;
            c[x] = a[v];
        }
        if(type == 2) {
            cin >> x >> y >> z;
            c[x] = (c[y] ^ c[z]);
        }
        if(type == 3) {
            cin >> x >> y >> z;
            c[x] = (c[y] & c[z]);
        }
        if(type == 4) {
            cin >> x >> v;
            cout << (c[x] & b[v]).count() % 2;
        }
    }
    //cin.close();
    //cout.close();
    return 0;
}
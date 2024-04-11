#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;

const int MOD = (int) 1e9 + 7;

struct Data {
    int lin;
    ll col1, col2;
    bool type;
    bool operator <(const Data &other) const {
        if((1 - type) * col1 + type * col2 == (1 - other.type) * other.col1 + other.type * other.col2)
            return type < other.type;
        return (1 - type) * col1 + type * col2 < (1 - other.type) * other.col1 + other.type * other.col2;
    }
};

vector <Data> obst;

int a[4][4];
int ans[4][4];

inline void multiply(int a[4][4], int b[4][4]) {
    int c[4][4];
    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= 3; j++) {
            c[i][j] = 0;
            for(int k = 1; k <= 3; k++) {
                c[i][j] = (c[i][j] + 1LL * a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= 3; j++) {
            a[i][j] = c[i][j];
        }
    }
}

inline void lgput(ll step, int mask) {
    memset(ans, 0, sizeof(ans));
    for(int i = 1; i <= 3; i++) {
        ans[i][i] = 1;
    }
    memset(a, 0, sizeof(a));
    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= 3; j++) {
            if((mask & (1 << j)) == 0 && abs(i - j) <= 1) {
                a[i][j] = 1;
            }
        }
    }
    while(step > 0) {
        if(step & 1)
            multiply(ans, a);
        step >>= 1;
        multiply(a, a);
    }
}

ll lim[4];
int coef[4], aux[4];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n;
    ll m;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(i = 1; i <= n; i++) {
        int lin;
        ll l, r;
        cin >> lin >> l >> r;
        obst.push_back({lin, l, r, 0});
        obst.push_back({lin, l, r, 1});
    }
    sort(obst.begin(), obst.end());
    ll last = 1;
    int p = 0;
    coef[2] = 1;
    while(p < 2 * n) {
        //printf("%d " ,mask);
        int mask = 0;
        for(i = 1; i <= 3; i++) {
            mask |= ((1 << i) * (last + 1 <= lim[i]));
        }
        //printf("%d %d %d %d\n" ,obst[p].lin,obst[p].col1 * (1 - obst[p].type) + obst[p].col2 * obst[p].type,mask,last);
        bool type = obst[p].type;
        ll col;
        if(type == 0) {
            col = obst[p].col1;
            lim[obst[p].lin] = max(lim[obst[p].lin], obst[p].col2);
        }
        else {
            col = obst[p].col2;
        }
        if(type == 0) {
            lgput(col - last - 1, mask);
        }
        else {
            lgput(col - last, mask);
        }
        if(type == 0) {
            last = col - 1;
        }
        if(type == 1) {
            last = col;
        }
        memset(aux, 0, sizeof(aux));
        for(i = 1; i <= 3; i++) {
            for(j = 1; j <= 3; j++) {
                aux[i] = (aux[i] + 1LL * coef[j] * ans[j][i]) % MOD;
            }
        }
        memcpy(coef, aux, sizeof(aux));
        /*for(i = 1; i <= 3; i++) {
            printf("%d " ,coef[i]);
        }
        printf("\n\n");*/
        p++;
    }
    lgput(m - last, 0);
    memset(aux, 0, sizeof(aux));
    for(i = 1; i <= 3; i++) {
        for(j = 1; j <= 3; j++) {
            aux[i] = (aux[i] + 1LL * coef[j] * ans[j][i]) % MOD;
        }
    }
    memcpy(coef, aux, sizeof(aux));
    cout << coef[2];
    //cin.close();
    //cout.close();
    return 0;
}
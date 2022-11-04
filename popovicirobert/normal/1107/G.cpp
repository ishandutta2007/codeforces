#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

const int MAXN = (int) 3e5;

int d[MAXN + 1], c[MAXN + 1];

int l[MAXN + 1], r[MAXN + 1];
int stk[MAXN + 1];

struct RMQ {
    vector < vector <int> > rmq;
    vector <ll> arr;
    vector <int> lg;
    int n;
    RMQ(int _n) {
        n = _n;
        lg.resize(n + 1);
        for(int i = 2; i <= n; i++) {
            lg[i] = lg[i >> 1] + 1;
        }
        rmq.resize(n + 1, vector <int>(lg[n] + 1));
        arr.resize(n + 1);
    }
    inline void compute(vector <ll> &_arr) {
        for(int i = 1; i <= n; i++) {
            arr[i] = _arr[i];
            rmq[i][0] = i;
        }
        for(int bit = 1; (1 << bit) <= n; bit++) {
            for(int i = 1; i + (1 << bit) <= n + 1; i++) {
                int a = rmq[i][bit - 1], b = rmq[i + (1 << (bit - 1))][bit - 1];
                if(arr[a] < arr[b]) {
                    rmq[i][bit] = b;
                }
                else {
                    rmq[i][bit] = a;
                }
            }
        }
    }
    inline int get(int l, int r) {
        int bit = lg[r - l + 1];
        int a = rmq[l][bit], b = rmq[r - (1 << bit) + 1][bit];
        if(arr[a] > arr[b]) return a;
        return b;
    }
};

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, a;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> a;
    ll ans = 0;
    for(i = 1; i <= n; i++) {
        cin >> d[i] >> c[i];
        ans = max(ans, 1LL * a - c[i]);
    }
    int sz = 0;
    for(i = 1; i < n; i++) {
        while(sz > 0 && d[stk[sz] + 1] - d[stk[sz]] <= d[i + 1] - d[i]) {
            sz--;
        }
        l[i] = stk[sz];
        stk[++sz] = i;
    }
    sz = 0;
    for(i = n - 1; i >= 1; i--) {
        while(sz > 0 && d[stk[sz] + 1] - d[stk[sz]] <= d[i + 1] - d[i]) {
            sz--;
        }
        r[i] = stk[sz];
        stk[++sz] = i;
    }
    RMQ rmq_l(n), rmq_r(n);
    vector <ll> spl(n + 2), spr(n + 2);
    for(i = 1; i <= n; i++) {
        spl[i] = spl[i - 1] + a - c[i];
    }
    rmq_l.compute(spl);
    for(i = n; i >= 1; i--) {
        spr[i] = spr[i + 1] + a - c[i];
    }
    rmq_r.compute(spr);
    for(i = 1; i < n; i++) {
        int a = l[i] + 1, b = r[i];
        if(b == 0) {
            b = n;
        }
        ans = max(ans, spl[rmq_l.get(i + 1, b)] - spl[i] + spr[rmq_r.get(a, i)] - spr[i + 1] - 1LL * (d[i] - d[i + 1]) * (d[i] - d[i + 1]));
        //cerr << rmq_r.get(a, i) << " " << rmq_l.get(i + 1, b) << "\n";
        //cerr << spl[rmq_l.get(i + 1, b)] - spl[i] + spr[rmq_r.get(a, i)] - spr[i + 1] - 1LL * (d[i] - d[i + 1]) * (d[i] - d[i + 1]) << "\n";
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}
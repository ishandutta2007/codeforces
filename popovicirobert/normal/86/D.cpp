#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

const int MAXN = (int) 2e5;
const int MAXVAL = (int) 1e6;
const int BUCKET = 500;

int arr[MAXN + 1];
int fr[MAXVAL + 1];

struct Query {
    int l, r;
    int pos;
    bool operator <(const Query &other) const {
        if(l / BUCKET == other.l / BUCKET)
            return r < other.r;
        return l < other.l;
    }
}qry[MAXN + 1];

ll sol[MAXN + 1], cur;

inline void add(int x) {
    cur -= 1LL * x * fr[x] * fr[x];
    fr[x]++;
    cur += 1LL * x * fr[x] * fr[x];
}

inline void del(int x) {
    cur -= 1LL * x * fr[x] * fr[x];
    fr[x]--;
    cur += 1LL * x * fr[x] * fr[x];
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, t;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> t;
    for(i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for(i = 1; i <= t; i++) {
        cin >> qry[i].l >> qry[i].r;
        qry[i].pos = i;
    }
    sort(qry + 1, qry + t + 1);
    int l = 0, r = 0;
    for(i = 1; i <= t; i++) {
        while(r < qry[i].r) {
            r++;
            add(arr[r]);
        }
        while(l > qry[i].l) {
            l--;
            add(arr[l]);
        }
        while(r > qry[i].r) {
            del(arr[r]);
            r--;
        }
        while(l < qry[i].l) {
            del(arr[l]);
            l++;
        }
        sol[qry[i].pos] = cur;
    }
    for(i = 1; i <= t; i++) {
        cout << sol[i] << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}
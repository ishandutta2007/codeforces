#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

const int MAXN = (int) 2e5;

ll a[MAXN + 1], b[MAXN + 1];

struct Data {
    int pos, start;
    ll val;
};

vector <Data> arr[MAXN + 1];


inline bool check(ll lim, int n, int k) {
    for(int i = 1; i <= k; i++) {
        arr[i].clear();
    }
    for(int i = 1; i <= n; i++) {
        ll cur = a[i] / b[i] + 1;
        if(cur <= k) {
            arr[cur].push_back({i, 0, a[i]});
        }
    }
    int pos = 1;
    for(int i = 1; i < k; i++) {
        while(pos <= k && arr[pos].size() == 0) {
            pos++;
        }
        if(pos <= k) {
            auto cur = arr[pos].back();
            arr[pos].pop_back();
            ll val = cur.val - 1LL * b[cur.pos] * (i - cur.start) + lim;
            if(val < 0) {
                return 0;
            }
            ll day = i + val / b[cur.pos] + 1;
            if(day < k) {
                arr[day].push_back({cur.pos, i, val});
            }
        }
        if(arr[pos].size() && pos == i) {
            return 0;
        }
    }
    return 1;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, k;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for(i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(i = 1; i <= n; i++) {
        cin >> b[i];
    }
    ll res = -1;
    for(ll step = 1LL << 45; step; step >>= 1) {
        if(check(res + step, n, k) == 0) {
            res += step;
        }
    }
    res++;
    if(check(res, n, k) == 0) {
        res = -1;
    }
    cout << res;
    //cin.close();
    //cout.close();
    return 0;
}
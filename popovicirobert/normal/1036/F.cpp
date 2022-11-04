#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const ll INF = 1e18;
const int MAXT = (int) 1e5;

pair <ll, int> vals[MAXT + 1];
ll sol[MAXT + 1];

vector <int> arr;
bool ok[100];
int low[100], cnt[100];

inline void prec() {
    int i, j;
    for(i = 2; i <= 63; i++) {
        ok[i] = 1;
    }
    for(i = 2; i <= 63; i++) {
        if(low[i] == 0) {
            for(j = i; j <= 63; j += i) {
                low[j] = i;
            }
            for(j = i * i; j <= 63; j += i * i) {
                ok[j] = 0;
            }
        }
    }
    for(i = 2; i <= 63; i++) {
        cnt[i] = cnt[i / low[i]] + 1;
        if(ok[i] == 1) {
            arr.push_back(i);
        }
    }
}

inline bool check(int x, int pw, ll lim) {
    ll ans = 1;
    while(pw > 0 && ans <= lim / x) {
        ans *= x;
        pw--;
    }
    return pw == 0;
}

inline ll lgput(ll a, int b) {
    ll ans = 1;
    while(b > 0) {
        if(b & 1)
            ans = 1LL * ans * a;
        b >>= 1;
        a = 1LL * a * a;
    }
    return ans;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int t, i, j;
    ios::sync_with_stdio(false);
    cin >> t;
    for(i = 1; i <= t; i++) {
        cin >> vals[i].first;
        vals[i].second = i;
    }
    sort(vals + 1, vals + t + 1);
    prec();
    vector <int> rad;
    rad.resize(arr.size());
    for(i = 1; i < arr.size(); i++) {
        int res = 0;
        for(int step = 1 << 30; step; step >>= 1) {
            if(check(res + step, arr[i], INF)) {
                res += step;
            }
        }
        rad[i] = res;
    }
    for(i = t; i >= 1; i--) {
        ll cur = sqrt(vals[i].first) - 1;
        for(j = 1; j < arr.size(); j++) {
            while(lgput(rad[j], arr[j]) > vals[i].first) {
                rad[j]--;
            }
            if(cnt[arr[j]] % 2) {
                cur += rad[j] - 1;
            }
            else {
                cur -= (rad[j] - 1);
            }
        }
        sol[vals[i].second] = vals[i].first - cur - 1;
    }
    for(i = 1; i <= t; i++) {
        cout << sol[i] << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}
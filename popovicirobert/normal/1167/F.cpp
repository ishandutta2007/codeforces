#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MOD = (int) 1e9 + 7;

struct Fenwick {
    vector <ll> sum;
    vector <int> cnt;
    int n;

    inline void init(int _n) {
        n = _n;
        sum.resize(n + 1), cnt.resize(n + 1);
    }

    inline void update(int pos, int val) {
        for(int i = pos; i <= n; i += lsb(i)) {
            cnt[i]++;
            sum[i] += val;
        }
    }

    inline pair <ll, int> query(int pos) {
        pair <ll, int> ans = {0, 0};
        for(int i = pos; i > 0; i -= lsb(i)) {
            ans.first += sum[i];
            ans.second += cnt[i];
        }
        return ans;
    }

    inline pair <ll, int> sum_segm(int l, int r) {
        pair <ll, int> b = query(r);
        pair <ll, int> a = query(l - 1);

        return {b.first - a.first, b.second - a.second};
    }

};

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;

    vector < pair <int, int> > arr(n + 1);
    vector <int> aux(n + 1);

    for(i = 1; i <= n; i++) {
        cin >> arr[i].first;
        arr[i].second = i;

        aux[i] = arr[i].first;
    }

    sort(arr.begin(), arr.end());

    Fenwick fen; fen.init(n);
    ll ans = 0;

    for(i = 1; i <= n; i++) {
        int pos = arr[i].second;

        pair <ll, int> a = fen.sum_segm(1, pos - 1);
        pair <ll, int> b = fen.sum_segm(pos + 1, n);

        int cur = (1LL * pos * ((1LL * b.second * (n + 1) - b.first) % MOD)) % MOD;
        cur = (cur + 1LL * (n - pos + 1) * a.first) % MOD;

        ans = (ans + 1LL * cur * arr[i].first) % MOD;

        fen.update(pos, pos);
    }

    for(i = 1; i <= n; i++) {
        ans = (ans + 1LL * (1LL * i * (n - i + 1) % MOD) * aux[i]) % MOD;
    }

    cout << ans;

    //cin.close();
    //cout.close();
    return 0;
}
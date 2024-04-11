#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;

const int N = 1e5 + 5;

int n, m, a[N << 1], gap[N], pre[N];
pair<int, int> c[N];
bool vis[N << 1];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    rep(i, 1, n) cin >> a[i], gap[i] = ~a[i] ? gap[i - 1] : i;
    cin >> m;
    rep(i, 1, m) cin >> a[i + n];
    sort(a + n + 1, a + n + m + 1);
    int tp = 0;
    rep(i, 1, n) {
        if(~a[i]) {
            auto t = lower_bound(c + 1, c + tp + 1, pair(a[i], 0));
            *t-- = {a[i], i}, pre[i] = t->second;
        }
        else {
            int j = n + 1, ls = 0;
            rep(k, 1, tp + 1) {
                if(j > n + m) break;
                auto [v, b] = c[k];
                if(k > tp || a[j] < v) c[k] = {a[j], ls};
                ls = b;
                while(j <= n + m && a[j] <= v) j++;
            }
        }
        if(c[tp + 1].first) tp++;
    }
    int j = n + m;
    for(int k = gap[n]; j > n && k > c[tp].second && a[j] > a[c[tp].second]; k = gap[k - 1]) {
        a[k] = a[j], vis[j] = 1;
        while(a[j] == a[k]) j--;
    }
    for(int i = c[tp].second; i; i = pre[i]) {
        while(a[j] >= a[i]) j--;
        for(int k = gap[i]; j > n && k > pre[i] && a[j] > a[pre[i]]; k = gap[k - 1]) {
            a[k] = a[j], vis[j] = 1;
            while(a[j] == a[k]) j--;
        }
    }
    j = n + 1;
    rep(i, 1, n) {
        if(!~a[i]) {
            while(vis[j]) j++;
            assert(j <= n + m);
            a[i] = a[j++];
        }
        cout << a[i] << ' ';
    }
}
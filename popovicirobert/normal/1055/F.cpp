#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 1e6;

inline ll get(ll x, int nr) {
    return x >> (62 - nr);
}

ll arr[MAXN + 1];
int l[MAXN + 1], r[MAXN + 1];
int st[MAXN + 1], dr[MAXN + 1];
pair <int, int> segm[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n, i;
    ll k;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for(i = 2; i <= n; i++) {
        int par;
        cin >> par >> arr[i];
        arr[i] ^= arr[par];
    }
    sort(arr + 1, arr + n + 1);
    for(i = 1; i <= n; i++) {
        l[i] = 1;
        r[i] = n;
    }
    ll tot = 0, ans = 0;
    for(int bit = 61; bit >= 0; bit--) {
        i = 1;
        while(i <= n) {
            int j = i;
            while(j < n && (arr[j] ^ arr[j + 1]) < (1LL << bit)) {
                j++;
            }
            st[i] = j;
            dr[j] = i;
            i = j + 1;
        }
        ll cnt = 0;
        for(i = 1; i <= n; i++) {
            if(l[i] > r[i]) {
                continue;
            }
            if(arr[i] & (1LL << bit)) {
                if((arr[r[i]] & (1LL << bit))) {
                    cnt += r[i] - dr[r[i]] + 1;
                }
            }
            else {
                if((arr[l[i]] & (1LL << bit)) == 0) {
                    cnt += st[l[i]] - l[i] + 1;
                }
            }
        }
        bool b = 0;
        if(cnt + tot < k) {
            ans += (1LL << bit);
            tot += cnt;
            b = 1;
        }
        for(i = 1; i <= n; i++) {
            if(l[i] > r[i]) {
                continue;
            }
            if((b ^ ((arr[i] & (1LL << bit)) > 0)) == 0) {
                if(arr[l[i]] & (1LL << bit)) {
                    r[i] = -1;
                }
                else {
                    r[i] = st[l[i]];
                }
            }
            else {
                if((arr[r[i]] & (1LL << bit)) == 0) {
                    r[i] = -1;
                }
                else {
                    l[i] = dr[r[i]];
                }
            }
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}
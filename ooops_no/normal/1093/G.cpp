#include<iostream>
#include<algorithm>
#include<vector>
#include<random>
#include<map>
#include<set>
#include<deque>
#include<assert.h>
using namespace std;

#define pb push_back
#define ld long double
//#define int long long
#define ll long long

mt19937 rnd(51);

const int INF = 2e9, N = 2e5 + 10;

struct st{
    vector<int> t;
    void make(int n){
        t.resize(4 * n);
        fill(t.begin(), t.end(), -INF);
    }
    void update(int v, int l, int r, int pos, int val){
        if (l == r){
            t[v] = val;
            return;
        }
        int m = (l + r) / 2;
        if (pos <= m) update(2 * v, l, m, pos, val);
        else update(2 * v + 1, m + 1, r, pos, val);
        t[v] = max(t[v * 2], t[v * 2 + 1]);
    }
    int get(int v, int tl, int tr, int l, int r){
        if (l > r) return -INF;
        if (tl == l && tr == r){
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return max(get(2 * v, tl, tm, l, min(r, tm)), get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
    }
} t[34];

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 34; i++){
        t[i].make(N);
    }
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n, vector<int>(k));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < k; j++){
            cin >> a[i][j];
        }
        for (int j = 0; j < (1 << k); j++){
            int sum = 0;
            for (int f = 0; f < k; f++){
                if (j & (1 << f)){
                    sum += a[i][f];
                }
                else{
                    sum -= a[i][f];
                }
            }
            t[j].update(1, 0, N - 1, i, sum);
        }
    }
    int q;
    cin >> q;
    while(q--){
        int type;
        cin >> type;
        if (type == 1){
            int i;
            cin >> i;
            i--;
            for (int j = 0; j < k; j++){
                cin >> a[i][j];
            }
            for (int j = 0; j < (1 << k); j++){
                int sum = 0;
                for (int f = 0; f < k; f++){
                    if (j & (1 << f)){
                        sum += a[i][f];
                    }
                    else{
                        sum -= a[i][f];
                    }
                }
                t[j].update(1, 0, N - 1, i, sum);
            }
        }
        else{
            int l, r;
            cin >> l >> r;
            l--, r--;
            int ans = -INF;
            for (int i = 0; i < (1 << k); i++){
                ans = max(ans, t[i].get(1, 0, N - 1, l, r) + t[(1 << k) - i - 1].get(1, 0, N - 1, l, r));
            }
            cout << ans << endl;
        }
    }
    return 0;
}
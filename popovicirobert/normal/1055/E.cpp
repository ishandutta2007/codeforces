#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int INF = 1e9;
const int MAXN = 1505;

vector <int> segm[MAXN + 1];

int arr[MAXN + 1];
int dp[MAXN + 1][MAXN + 1], cnt[MAXN + 1][MAXN + 1];
int n, m, s, k;

int stk[MAXN + 1], sp[MAXN + 1];
char lg[MAXN + 1];

inline bool check(int val) {
    int i, j;
    for(i = 1; i <= n; i++) {
        sp[i] = sp[i - 1] + (arr[i] <= val);
    }
    for(i = 1; i <= n; i++) {
        dp[i][1] = dp[i - 1][1];
        for(auto it : segm[i]) {
            dp[i][1] = max(dp[i][1], sp[i] - sp[it - 1]);
        }
    }
    for(j = 2; j <= m; j++) {
        int sz = 0;
        for(i = 1; i <= n; i++) {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            for(auto it : segm[i]) {
                int res = 0;
                for(int step = 1 << lg[sz]; step; step >>= 1) {
                    if(res + step <= sz && stk[res + step] < it) {
                        res += step;
                    }
                }
                res++;
                if(res <= sz) {
                    dp[i][j] = max(dp[i][j], dp[stk[res]][j - 1] - sp[stk[res]] + sp[i]);
                }
                dp[i][j] = max(dp[i][j], dp[it - 1][j - 1] + sp[i] - sp[it - 1]);
            }
            while(sz > 0 && dp[stk[sz]][j - 1] - sp[stk[sz]] <= dp[i][j - 1] - sp[i]) {
                sz--;
            }
            stk[++sz] = i;
        }
    }
    return dp[n][m] < k;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> s >> m >> k;
    vector <int> aux;
    for(i = 1; i <= n; i++) {
        cin >> arr[i];
        aux.push_back(arr[i]);
    }
    sort(aux.begin(), aux.end());
    for(i = 1; i <= s; i++) {
        int l, r;
        cin >> l >> r;
        cnt[l][r]++;
        segm[r].push_back(l);
    }
    for(i = 2; i <= MAXN; i++) {
        lg[i] = lg[i >> 1] + 1;
    }
    int res = -1;
    for(int step = 1 << 15; step; step >>= 1) {
        if(res + step < n && check(aux[res + step]) == 1) {
            res += step;
        }
    }
    res++;
    if(res == n) {
        cout << -1;
        return 0;
    }
    cout << aux[res];
    //cin.close();
    //cout.close();
    return 0;
}
#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "

using namespace std;

const int MAXN = (int) 1e5;
 
int sp[MAXN + 1][2];
int cnt[MAXN + 1];
 
int dp[MAXN + 1];
int mn[MAXN + 1];
 
inline int get(int l, int r, int ch) {
    if(l > r)
        return 0;
    if((l - 1) % 2 == r % 2)
       return sp[r][ch] - sp[l - 1][ch];
    if(l == 1)
       return sp[r][ch];
    return sp[r][ch] - sp[l - 2][ch];
}
 
inline int check(int l, int r) {
    return cnt[r] - cnt[l - 1];
}
 
string str;

int main() {
#ifdef HOME
    ifstream cin("E.in");
    ofstream cout("E.out");
#endif
    int i, n, m;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
	
	cin >> n;
    cin >> str;
    str = " " + str;
    for(i = 1; i <= n; i++) {
        if(i > 1) {
           sp[i][0] = sp[i - 2][0] + (str[i] == 'a');
           sp[i][1] = sp[i - 2][1] + (str[i] == 'b');
        }
        else {
           sp[i][0] = (str[i] == 'a');
           sp[i][1] = (str[i] == 'b');
        }
        cnt[i] = cnt[i - 1] + (str[i] == '?');
    }
    cin >> m;
    for(i = m; i <= n; i++) {
        mn[i] = n + 1;
        if(m % 2 == 1) {
            if(get(i - m + 1, i, 1) == 0 && get(i - m + 1, i - 1, 0) == 0) {
                if(dp[i] < dp[i - m] + 1) {
                    dp[i] = dp[i - m] + 1;
                    mn[i] = mn[i - m] + check(i - m + 1, i);
                }
                else if(dp[i] == dp[i - m + 1] + 1 && mn[i] > mn[i - m] + check(i - m + 1, i)) {
                    mn[i] = mn[i - m] + check(i - m + 1, i);
                }
            }
        }
        else {
            if(get(i - m + 1, i, 0) == 0 && get(i - m + 1, i - 1, 1) == 0) {
                if(dp[i] < dp[i - m] + 1) {
                    dp[i] = dp[i - m] + 1;
                    mn[i] = mn[i - m] + check(i - m + 1, i);
                }
                else if(dp[i] == dp[i - m + 1] + 1 && mn[i] > mn[i - m] + check(i - m + 1, i)) {
                    mn[i] = mn[i - m] + check(i - m + 1, i);
                }
            }
        }
        if(dp[i] < dp[i - 1] || (dp[i] == dp[i - 1] && mn[i] > mn[i - 1])) {
            dp[i] = dp[i - 1];
            mn[i] = mn[i - 1];
        }
        if(mn[i] == n + 1)
            mn[i] = 0;
    }
    cout << mn[n] << "\n";		

    return 0;
}
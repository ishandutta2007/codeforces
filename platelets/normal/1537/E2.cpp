#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;

const int N = 5e5 + 5;

char s[N];
int n, m;
int main() {
#ifdef local
    freopen(".in", "r", stdin);
#endif
    scanf("%d%d%s", &n, &m, s);
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r && z[i - l] < r - i + 1) {
            z[i] = z[i - l];
        } else {
            z[i] = max(0, r - i + 1);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        }
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    int as = n;
    per(i, n - 1, 1) {
        if(z[i] < as - i) {
            if(s[z[i]] < s[i + z[i]]) as = i;
        } else if(z[as - i] < i) {
            if(s[as - i + z[as - i]] < s[z[as - i]]) as = i;
        }
    }
    For(i, 0, m) putchar(s[i % as]);
    return 0;
}
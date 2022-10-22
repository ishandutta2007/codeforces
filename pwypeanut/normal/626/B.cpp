#include <bits/stdc++.h>
using namespace std;

int N, cnta, cntb, cntc, dp[205][205][205];
char c[205];

int f(int r, int g, int b) {
    if (r < 0 || g < 0 || b < 0) return 0;
    if (r + g + b == 1) {
        if (r == 1) return 4;
        else if (g == 1) return 2;
        else return 1;
    }
    if (dp[r][g][b] != -1) return dp[r][g][b];
    int ans = 0;
    if (r >= 1 && g >= 1) ans |= (f(r - 1, g - 1, b + 1));
    if (g >= 1 && b >= 1) ans |= (f(r + 1, g - 1, b - 1));
    if (r >= 1 && b >= 1) ans |= (f(r - 1, g + 1, b - 1));
    if (r >= 2) ans |= f(r - 1, g, b);
    if (g >= 2) ans |= f(r, g - 1, b);
    if (b >= 2) ans |= f(r, g, b - 1);
   // printf("%d %d %d = %d\n", r, g, b, ans);
    return dp[r][g][b] = ans;
}

int main() {
    scanf("%d", &N);
    scanf("%s", &c);
    for (int i = 0; i < N; i++) {
        if (c[i] == 'R') cnta++;
        else if (c[i] == 'G') cntb++;
        else cntc++;
    }
    memset(dp, -1, sizeof(dp));
    int ans = f(cnta, cntb, cntc);
    string s = "";
    if (ans & 4) s += "R";
    if (ans & 2) s += "G";
    if (ans & 1) s += "B";
    reverse(s.begin(), s.end());
    printf("%s\n", s.c_str());
}
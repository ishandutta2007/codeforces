#include <bits/stdc++.h>
using namespace std;

int t;
int n, k;
int dp[3][111];

char s[3][111];

int f(int x, int y) {
    if (y >= n) return 1;
    if (dp[x][y] != -1) return dp[x][y];
    
    int ret = 0;
    if (s[x][y+1] == '.') {
        if (s[x][y+2] == '.' && s[x][y+3] == '.') ret |= f(x, y+3);
        if (x > 0 && s[x-1][y+1] == '.' && s[x-1][y+2] == '.' && s[x-1][y+3] == '.') ret |= f(x-1, y+3);
        if (x < 2 && s[x+1][y+1] == '.' && s[x+1][y+2] == '.' && s[x+1][y+3] == '.') ret |= f(x+1, y+3);
    }
    
    return dp[x][y] = ret;
}

int main () {
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &k);
        
        memset(s, 0, sizeof s);
        gets(s[0]);
        
        for (int i=0; i<3; i++) gets(s[i]);
        for (int i=0; i<3; i++) for (int j=0; j<3; j++) s[i][n+j] = '.';    
        
        int start;
        if (s[0][0] == 's') start = 0;
        if (s[1][0] == 's') start = 1;
        if (s[2][0] == 's') start = 2;
        
        memset(dp, -1, sizeof dp);
        if (f(start, 0)) puts("YES");
        else puts("NO");
    }
    return 0;   
}
#include <bits/stdc++.h>

using namespace std;
const int c=122;
long long dp[c][c];
bool solve() {
    long long t, x, y;
    cin >> t >> x >> y;
    if (x+y>t) return false;
    for (int i=0; i<c; i++) for (int j=0; j<c; j++) dp[i][j]=0;
    dp[1][1]=t-x-y;
    x++, y++;
    for (int i=1; i<=120; i++) {
        for (int j=1; j<=120; j++) {
            dp[i][j+1]+=(dp[i][j]+1)/2;
            dp[i+1][j]+=(dp[i][j])/2;
        }
    }
    int a=1, b=1;
    while (a+b<x+y) {
        if (dp[a][b]%2) a++;
        else b++;
    }
    return (a==x);
}
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        cout << (solve() ? "YES" : "NO") << "\n";
    }
    return 0;
}
/*
1
1 1 0
*/
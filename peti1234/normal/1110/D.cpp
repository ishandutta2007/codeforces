#include <bits/stdc++.h>

using namespace std;
int n, m;
int t[1000002];
int dp[1000002][3][6];
int ans(int a, int e, int k)
{
    if (a>m) {
        return 0;
    }
    if (t[a]-e<0){
        return -1000;
    }
    if (dp[a][e][k]!=0) {
        return dp[a][e][k];
    }
    int re=0;
    int p=min(t[a]-e, k);
    int x=t[a+1];
    if (p>0 && x>0) {
        re=max(re, 1+(t[a]-e-1)/3+ans(a+1, 1, (t[a]-e-1)%3));
        if (t[a]-e-1>=3) {
            re=max(re, (t[a]-e-1)/3+ans(a+1, 1, (t[a]-e-1)%3+3));
        }
    }
    if (p>1 && x>1) {
        re=max(re, (t[a]-e-2)/3+2+ans(a+1, 2, (t[a]-e-2)%3));
        if (t[a]-e-2>=3) {
            re=max(re, (t[a]-e-2)/3+1+ans(a+1, 2, (t[a]-e-2)%3+3));
        }
    }
    re=max(re, (t[a]-e)/3+ans(a+1, 0, (t[a]-e)%3));
    if (t[a]-e>=3) {
        re=max(re, (t[a]-e)/3-1+ans(a+1, 0, (t[a]-e)%3+3));
    }
    dp[a][e][k]=re;
    return re;
}
int main()
{
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        t[x]++;
    }
    cout << ans(1, 0, 0);
    return 0;
}
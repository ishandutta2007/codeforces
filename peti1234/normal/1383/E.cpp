#include <bits/stdc++.h>

using namespace std;
const int c=1000002;
string s;
long long n, dp[c], k[c], lp[c], p, x=1, e, db=1, d, m=1000000007;
int main()
{
    cin >> s, n=s.size();
    while(s[p]=='0') p++, dp[p]=1, x++;
    if (p==n) {cout << n; return 0;}
    while(p<n) {
        p++, dp[p]=x, k[p]=dp[p]+k[p-1], d=0;
        while(p<n && s[p]=='0') d++, p++, k[p]=k[p-1], dp[p]=(k[p]-k[lp[d]]+m)%m, x+=dp[p], x%=m, lp[d]=p;
    }
    x=0;
    while(p>0) {
        if (s[p-1]=='1') e++, x+=dp[p];
        if (!e) db++;
        p--;
    }
    cout << x*db%m << "\n";
    return 0;
}
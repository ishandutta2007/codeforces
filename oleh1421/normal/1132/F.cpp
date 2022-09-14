#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
//#define int long long
#define endl '\n'
typedef long long ll;
using namespace std;
int n,k;
int a[666];
int dp[666][666];
int solve(int l,int r){
    if (l>r) return 0;
    if (l==r) return 1;
    if (dp[l][r]) return dp[l][r];
    int res=1+solve(l+1,r);
    for (int i=l+1;i<=r;i++){
        if (a[l]==a[i]) res=min(res,solve(l+1,i-1)+solve(i,r));
    }
    return dp[l][r]=res;
}
int32_t main() {
    int n;cin>>n;
    string t;cin>>t;
    a[1]=(t[0]-'a');
    int cnt=1;
    for (int i=1;i<n;i++) a[++cnt]+=t[i]-'a';
    cout<<solve(1,cnt);

    return 0;
}
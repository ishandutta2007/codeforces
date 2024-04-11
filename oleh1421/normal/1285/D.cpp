//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
///use char if you want a naive algorithm to pass
#include <bits/stdc++.h>
//#include <vector>
#define endl '\n'
typedef long long ll;
using namespace std;
int a[300001];
int solve(int l,int r,int j){
    if (l==r || j==-1) return 0;
    int cnt=0;
    for (int i=l;i<=r;i++){
        cnt+=((a[i]>>j)&1);
    }
    if (cnt==0) return solve(l,r,j-1);
    if (cnt==r-l+1){
        for (int i=l;i<=r;i++){
            a[i]^=(1<<j);
        }
        return solve(l,r,j-1);
    }
    for (int i=r-cnt+1;i<=r;i++){
        a[i]^=(1<<j);
    }
    return min(solve(l,r-cnt,j-1),solve(r-cnt+1,r,j-1))+(1<<j);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    cout<<solve(1,n,29);

    return 0;
}
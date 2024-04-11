#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=2010;
int a[N][N];
int l[N],r[N];
void solve(){
    int n,m,k;cin>>n>>m>>k;
    for (int i=1;i<=m;i++) cin>>l[i]>>r[i];
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            a[i][j]=min(r[j],i+k-1)-max(l[j],i)+1;
            a[i][j]=max(a[i][j],0);
        }
    }
    int res=0;
    for (int i=1;i<=n;i++){
        for (int j=i;j<=n;j++){
            int cur=0;
            for (int t=1;t<=m;t++) cur+=max(a[i][t],a[j][t]);
            res=max(res,cur);
        }
    }
    cout<<res<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }

    return 0;
}
/*
1 1 1
1 1
*/
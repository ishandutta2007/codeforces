#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define int long long
#define MINX(a,b) if (a>b) a=b;
#define MAXX(a,b) if (a<b) a=b;
#define endl '\n'
typedef long long ll;
using namespace std;
int a[400001];
ll s[400001];
ll s1[400001];
ll s2[400001];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,k;cin>>n>>m>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    if (m>=n){
        ll sum=0ll;
        ll res=0ll;
        for (int i=1;i<=n;i++){
            sum+=a[i];
            sum=max(sum,0ll);
            res=max(res,sum-k);
        }
        cout<<res;
        return 0;
    }
    s[0]=0;
    for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];

    s1[n-m+1]=max(s[n]-s[n-m]-k,0ll);
    for (int i=n-m;i>=1;i--){
        s1[i]=max(s[i+m-1]-s[i-1]-k+s1[i+m],0ll);
    }
    for (int i=1;i<=n+1;i++){
        for (int j=2;j<=m && i-j>=0;j++){
            s2[i]=max(s2[i],s[i-1]-s[i-j]-k);
        }
    }
    ll res=s2[n+1];
    for (int i=1;i<=n;i++) {
        res=max(res,s1[i]+s2[i]);
    }
    cout<<res;
    return 0;
}
/*
6 3
18 75 245 847 1859 26
*/
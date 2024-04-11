//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//#define int ll
#define endl '\n'
using namespace std;
const int N=2000010;
const ll mod=1000000007ll;
int a[N],b[N];
int l[N],r[N];
int n;
bool ok(int k){
    for (int i=1;i<=n;i++){
        r[i]=min(b[i]+1,k);
        l[i]=max(k-a[i],1);
    }
    int st=0;
    for (int i=1;i<=n;i++){
        if (st+1>=l[i] && st+1<=r[i]) st++;
    }
    return (st>=k);

}
void solve(){
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i]>>b[i];
    int ans=0;
    for (int i=20;i>=0;i--){
        if (ans+(1<<i)<=n && ok(ans+(1<<i))) ans+=(1<<i);
    }
    cout<<ans<<endl;


}
int32_t  main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}

/**
**/
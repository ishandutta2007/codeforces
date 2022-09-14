#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
#define int ll
const int N=300010;
int a[N],cnt[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i],cnt[i]=0;
    for (int i=1;i<=n;i++) cnt[a[i]]++;
    int mx=0;
    for (int i=1;i<=n;i++) mx=max(mx,cnt[i]);
    if (mx>(n+1)/2){
        cout<<"-1\n";
        return;
    }
    for (int i=0;i<=n;i++) cnt[i]=0;
    int res=0;
    cnt[a[1]]++,cnt[a[n]]++;
    int cn=1;
    for (int i=1;i<n;i++) if (a[i]==a[i+1]){
            cnt[a[i]]+=2;
            cn++;
    }
    mx=0;
    for (int i=1;i<=n;i++) mx=max(mx,cnt[i]);
    res=max(cn,mx-1)-1;
    cout<<res<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}
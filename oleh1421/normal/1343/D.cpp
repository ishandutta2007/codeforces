#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=500020;
int a[N];
bool same(int x,int y){
    if (x<0 && y<0) return true;
    if (x>0 && y>0) return true;
    return false;
}
int l[N];
int r[N];
int cnt[N];
void solve(){
    int n,k;cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n/2;i++){
        int mn=min(a[i],a[n-i+1]);
        int mx=max(a[i],a[n-i+1]);
        l[mn+1]++;
        r[k+mx]++;
        cnt[mn+mx]++;
    }
    for (int i=1;i<=k+k;i++){
        l[i]+=l[i-1];
        r[i]+=r[i-1];
//        cout<<i<<" "<<l[i]<<" "<<r[i]
    }
    int res=n;
    for (int x=2;x<=k+k;x++){
        int cur=(n/2)-cnt[x]+l[k+k]-l[x]+r[x-1];
//        if (x==4) cout<<cur<<endl;
        res=min(res,cur);
    }
    cout<<res<<endl;


    for (int i=1;i<=k+k;i++){
        l[i]=r[i]=cnt[i]=0;
    }

}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
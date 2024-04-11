#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=200010;
int n;
int x[N];
int y[N];
int pref[N];
int suf[N];
void solve(){
    int n,k;cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>x[i];
    for (int i=1;i<=n;i++) cin>>y[i];
    sort(x+1,x+n+1);
    pref[0]=0;
    for (int i=1;i<=n;i++){
        pref[i]=max(pref[i-1],i-(lower_bound(x+1,x+n+1,x[i]-k)-x-1));
    }
    suf[n+1]=0;
    for (int i=n;i>=1;i--){
        suf[i]=max(suf[i+1],(upper_bound(x+1,x+n+1,x[i]+k)-x)-i);
    }
    int res=0;
    for (int i=1;i<=n;i++){
        res=max(res,pref[i]+suf[i+1]);
    }
    cout<<res<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
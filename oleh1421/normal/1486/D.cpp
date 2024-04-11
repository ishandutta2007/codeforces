//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
#include <bits/stdc++.h>
typedef long long ll;
//#define endl '\n'
using namespace std;
const int N=200010;
const ll mod=1000000007ll;
const int A=1000100;
int a[N];
int pref[N];
int n,k;
int mn[N];
bool ok(int x){
    for (int i=1;i<=n;++i){
        pref[i]=(a[i]>=x)*2-1;
        pref[i]+=pref[i-1];
    }
    mn[0]=0;
    for (int i=1;i<=n;i++){
        mn[i]=min(mn[i-1],pref[i]);
    }
    for (int i=k;i<=n;i++){
        if (pref[i]-mn[i-k]>0) return true;
    }
    return false;
}
void solve(){
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    int L=0,R=n+1;
    while (R-L>1){
        int mid=(L+R)/2;
        if (ok(mid)) L=mid;
        else R=mid;
    }
    cout<<L<<endl;

}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
//#define int ll
using namespace std;
typedef long long ll;
const int N=100010;
const ll mod=998244353;
int l[N],r[N];
int a[N];
int D;
int n;
bool can(int mn,int mx){
    l[0]=r[0]=0;
    for (int i=1;i<=n;i++){
        l[i]=l[i-1]+mn;
        r[i]=r[i-1]+mx;
        l[i]=max(l[i],a[i]);
        r[i]=min(r[i],a[i+1]);
        if (l[i]>r[i]) return false;
    }
    if (l[n]<=D && D<=r[n]) return true;
    else return false;
}
void solve(){
    cin>>D>>n;
    a[n+1]=D;
    for (int i=1;i<=n;i++) cin>>a[i];
//    cout<<can(1,6)<<endl;
    int mx=0;
    for (int i=29;i>=0;i--){
        if (!can(1,mx+(1<<i))) mx+=(1<<i);
    }
    mx++;
//    cout<<mx<<endl;
    int mn=mx+1;
    for (int i=29;i>=0;i--){
        if (mn-(1<<i)>=1 && !can(mn-(1<<i),mx)) mn-=(1<<i);
    }
    mn--;
    can(mn,mx);
    vector<pair<int,int> >ans;
    for (int i=n-1;i>=0;i--){
        int len;
        if (D-mn<=r[i]) len=mn;
        else if (D-mx>=l[i]) len=mx;
        else len=D-l[i];
        ans.push_back({D-len,D});
        D-=len;
    }
    reverse(ans.begin(),ans.end());
//    cout<<mx-mn<<" "<<ans.size()<<endl;
    for (auto cur:ans) cout<<cur.first<<" "<<cur.second<<endl;

}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }

    return 0;
}
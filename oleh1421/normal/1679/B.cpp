//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
using namespace std;
typedef long double ld;
typedef long long ll;
//#define int ll
const int N=200105;
const ll inf=2e18;
const ll mod=998244353;
ll a[N];
bool used[N];
void solve(int Case){
    int n,q;cin>>n>>q;
    vector<int>good;
    ll sum=0ll;
    for (int i=1;i<=n;i++){
        used[i]=true;
        good.push_back(i);
        cin>>a[i];
        sum+=a[i];
    }
    ll w=0ll;
    for (int it=1;it<=q;it++){
        int type;cin>>type;
        if (type==1){
            int p,x;cin>>p>>x;
            if (used[p]){
                sum-=a[p];
                a[p]=x;
                sum+=a[p];
            } else {
                sum-=w;
                a[p]=x;
                sum+=a[p];
                used[p]=true;
                good.push_back(p);
            }
        } else {
            ll x;cin>>x;
            for (int i:good) used[i]=false;
            good.clear();
            w=x;
            sum=w*n;

        }
        cout<<sum<<endl;
    }


}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    for (int it=1;it<=tt;it++){
        solve(it);
    }
    return 0;
}

/**

**/
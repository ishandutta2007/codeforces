
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
#define int ll
const int N=500010;
const ll mod=1000000000000007ll;
int t[N],x[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>t[i]>>x[i];
    t[n+1]=mod*2;
    int X=0,ind=1;
    int res=0;
    while (ind<=n){
        int nx=x[ind];
        int nind=ind+1;
        while (t[nind]<abs(nx-X)+t[ind]) nind++;
        res+=(abs(nx-X)+t[ind]<=t[ind+1]);
        for (int i=ind+1;i<nind;i++){
            if (x[i]>=min(X,nx) && x[i]<=max(X,nx) && abs(X-x[i])+t[ind]>=t[i] && abs(X-x[i])+t[ind]<=t[i+1]) res++;
        }
        X=nx;
        ind=nind;
    }
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
/*
*/
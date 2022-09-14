//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse,avx,avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 rnd(time(NULL));
const int N=500100;
ll a[N];
ll pref[N];
ll sumL[N];
ll mxL[N];
int l[N];

ll sumR[N];
ll mxR[N];
int r[N];


void solve(int Case){
    int n;cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        sumL[i]=sumR[i]=mxL[i]=mxR[i]=0;
        l[i]=r[i]=0;
    }
    for (int i=1;i<=n;i++){
        l[i]=0;
        sumL[i]=a[i];
        mxL[i]=a[i];
        for (int j=i-1;j>=1;j=l[j]){
            if (a[j]>a[i]){
                l[i]=j;
                break;
            }
            mxL[i]=max(mxL[i],sumL[i]+mxL[j]);
            sumL[i]+=sumL[j];
        }
    }
    for (int i=n;i>=1;i--){
        r[i]=n+1;
        sumR[i]=a[i];
        mxR[i]=a[i];
        for (int j=i+1;j<=n;j=r[j]){

            if (a[j]>a[i]){
                r[i]=j;
                break;
            }
            mxR[i]=max(mxR[i],sumR[i]+mxR[j]);
//            if (i==1) cout<<j<<" "<<sumR[i]<<" "<<sumR[j]<<endl;
            sumR[i]+=sumR[j];
        }
    }
    for (int i=1;i<=n;i++){
//        cout<<i<<" "<<l[i]<<" "<<r[i]<<" "<<sumL[i]<<" "<<sumR[i]<<" "<<mxL[i]<<" "<<mxR[i]<<endl;
        if (a[i]*2<mxL[i]+mxR[i]){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";



}
int32_t main() {
//    freopen("seabattle.in","r",stdin);
//    freopen("seabattle.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tt=1;
    cin>>tt;
    for (int it=1;it<=tt;it++){
        solve(it);
    }
    return 0;
}
/**
1
3
1 -1 1
**/
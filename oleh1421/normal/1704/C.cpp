//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#define y2 y_2
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
//#define int ll
typedef long long ll;
typedef long double ld;
const ll inf=2e18;
const ll mod=1000000007;
const ll mod1=mod*mod;
const int N=2000100;
int a[N];
void solve(){
    int m,n;cin>>m>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    vector<int>v;
    for (int i=2;i<=n;i++){
        int d=a[i]-a[i-1]-1;
        if (d>0) v.push_back(d);
    }
    int d=a[1]+m-a[n]-1;
    if (d>0) v.push_back(d);
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    ll res=0ll;
//    5
//    1+4+1
    for (int i=0;i<v.size();i++){
//        cout<<v[i]<<endl;
        if (v[i]-i*4<=0) break;
        if (v[i]-i*4<=2){
            res++;
            break;
        }
        res++;
        v[i]-=2;
        res+=v[i]-i*4;
    }
    cout<<m-res<<'\n';
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    cin>>tt;
    while (tt--){
        solve();
    }
    return 0;

}
//CRES
/**
2 3
1 2
2 1
0 0

**/
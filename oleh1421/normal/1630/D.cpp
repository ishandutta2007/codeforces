//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long ll;
typedef long double ld;
///#define int ll
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
const int N=1000010;
ll a[N];
int b[N];
vector<int>el[N];
void solve(){
//    int n;cin>>n;
//    vector<int>v;
//    for (int i=0;i<n-3;i++){
//        v.push_back((1<<i)+(1<<(i+1))+(1<<(i+2)));
//    }
//    vector<int>basis;
//    for (int x:v){
//
//        for (int y:basis){
//            x=min(x,x^y);
//        }
//        if (x) basis.push_back(x);
//    }
//    int i=5;
//    int x=(1<<i)+(1<<(i+1));
//    cout<<x<<endl;
//    for (int y:basis){
//        x=min(x,x^y);
//    }
//    cout<<x<<endl;

    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    int g=0;
    for (int i=1;i<=m;i++){
        cin>>b[i];
        g=__gcd(g,b[i]);

    }
    for (int i=0;i<g;i++) el[i].clear();

    for (int i=1;i<=n;i++){
        el[i%g].push_back(a[i]);
    }

    for (int i=0;i<g;i++){
        sort(el[i].begin(),el[i].end());
    }
    ll res=-1e18;
    for (int rem=0;rem<2;rem++){
        ll cur=0ll;
        for (int i=0;i<g;i++){
            ll sum=0ll;
            for (auto x:el[i]) sum+=x;
//            cout<<"A "<<sum<<endl;

            if (rem) sum-=2ll*el[i][0];
            ll mx=sum;
            for (int j=rem+1;j<el[i].size();j+=2){
                sum-=2ll*(el[i][j-1]+el[i][j]);
                mx=max(mx,sum);
//                cout<<sum<<endl;
            }
            cur+=mx;
        }
        res=max(res,cur);
    }
    cout<<res<<endl;





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
6
1 2 3 1 2 3

**/
/**
13
1 2 3 2 1 3 3 4 5 5 5 4 7
0 1 1 1 1 1 0 0 1 1 1 0 0
**/
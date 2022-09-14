//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> line;
//#define endl '\n'
const int N = 1500010;
const int K=500;
const ll mod=998244353;
const ll inf=1e18;

void solve(){
    int n,m;cin>>n>>m;
    ld x=0,y=0;
    if (n>1){
        vector<pair<int,int> >v;
        v.push_back({0,0});
        for (int i=1;i<=m;i++){
            v.push_back({n,i-1});
            v.push_back({1,i});
        }
        v.push_back({0,m});
        cout<<"? "<<v.size()<<endl;
        for (auto cur:v) cout<<cur.first<<" "<<cur.second<<endl;
        ld S;cin>>S;

        if (S>1.0-1.0/((ld)(n-1)*2.0)){
            x=sqrtl((ld)(n-1)*(1-S)*2.0);
        } else {
            x=((1.0-S)*2.0*(n-1.0)+1.0)/2.0;
        }
    }
    if (m>1){
        vector<pair<int,int> >v;
        v.push_back({0,0});
        for (int i=1;i<=n;i++){
            v.push_back({i-1,m});
            v.push_back({i,1});
        }
        v.push_back({n,0});
        cout<<"? "<<v.size()<<endl;
        for (auto cur:v) cout<<cur.first<<" "<<cur.second<<endl;
        ld S;cin>>S;

        if (S>1.0-1.0/((ld)(m-1)*2.0)){
            y=sqrtl((ld)(m-1)*(1-S)*2.0);
        } else {
            y=((1.0-S)*2.0*(m-1.0)+1.0)/2.0;
        }
    }
    cout<<"! ";
    cout<<setprecision(10)<<fixed<<x<<" "<<y<<endl;

}
int main()
{


    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tt=1;
//    cin>>tt;

    while (tt--){
        solve();
    }
    return 0;
}
/**
1
8 86

**/
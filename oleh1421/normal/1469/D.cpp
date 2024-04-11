//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=500010;
const ll mod=1000000007;
int a[N];
vector<pair<int,int> >ans;
void go(int i,int j){
    a[i]=(a[i]+a[j]-1)/a[j];
    ans.push_back({i,j});
}
//int cnt(ll x,ll y){
//    int res=0;
//    while (x>1 && y>1){
//        if (x>y) swap(x,y);
//        y=(y+x-1)/
//
//    }
//}
void solve(){
    ans.clear();
    ll n;cin>>n;
        for (int i=1;i<=n;i++) a[i]=i;

    if (n==3){
        go(3,2);
        go(3,2);
    } else {
        ll k=min(n-1,16ll);
        for (int i=3;i<n;i++){
            if (i!=k){
                go(i,n);
            }
        }
        int cnt=0;
        while (a[n]>1 && a[k]>1){
            if (a[k]>a[n]) go(k,n);
            else go(n,k);
            cnt++;
        }
        while (a[n]>1){
            go(n,2);
        }
        while (a[k]>1){
            go(k,2);
        }
        for (int i=3;i<=n;i++){
            if (a[i]!=1) exit(1);
        }
        if (a[1]!=1) exit(1);
        if (a[2]!=2) exit(1);
    }
    cout<<ans.size()<<endl;
    for (auto cur:ans) cout<<cur.first<<" "<<cur.second<<endl;

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
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
    multiset<int>R,C;
    map<int,int>mpR,mpC;
    for (int i=0;i<=n+1;i++){
        R.insert(i);
        C.insert(i);
    }

    for (int it=1;it<=q;it++){
        int type;cin>>type;
        if (type==1){
            int x,y;cin>>x>>y;
            if (R.find(x)!=R.end()) R.erase(R.find(x));
            if (C.find(y)!=C.end()) C.erase(C.find(y));
            mpR[x]++;
            mpC[y]++;
        } else if (type==2){
            int x,y;cin>>x>>y;
            if ((--mpR[x])==0) R.insert(x);
            if ((--mpC[y])==0) C.insert(y);
        } else {
            int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
            auto r=R.lower_bound(x1);
            auto c=C.lower_bound(y1);
            if ((*r)<=x2 && (*c)<=y2){
                cout<<"No\n";
            } else {
                cout<<"Yes\n";
            }
        }
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
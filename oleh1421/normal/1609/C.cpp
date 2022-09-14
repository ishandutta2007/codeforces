#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
using namespace std;
typedef long double ld;
typedef long long ll;
//#define int ll
const int N=1200010;
const ll inf=1e18;
const ll mod=998244353;
bool prime[N];
int l[N],r[N];
int a[N];
void solve(int Case){

    int n,e;cin>>n>>e;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++){
        if (a[i]==1){
            if (i>e) l[i]=1+l[i-e];
            else l[i]=1;
        } else {
            l[i]=0;
        }
    }
    for (int i=n;i>=1;i--){
        if (a[i]==1){
            if (i+e<=n) r[i]=1+r[i+e];
            else r[i]=1;
        } else {
            r[i]=0;
        }
    }
    ll res=0ll;
    for (int i=1;i<=n;i++){
        if (prime[a[i]]){
            int L=1;
            if (i>e) L=l[i-e]+1;
            int R=1;
            if (i+e<=n) R=r[i+e]+1;
            res+=1ll*L*R-1ll;
        }
    }
    cout<<res<<endl;


}
int32_t main() {
    for (int i=2;i<N;i++) prime[i]=true;
    for (int i=2;i*i<N;i++){
        if (prime[i]){
            for (int j=i*i;j<N;j+=i) prime[j]=false;
        }
    }
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;cin>>tt;
    for (int it=1;it<=tt;it++){
        solve(it);
    }
    return 0;
}

/**
problem B with higher constrains


3
1 R
5 R
10 R
100 G
3 G
7 G


1
4
2 3 1 4

8 1
1 3 5 2 4 7 6 8
1 8


1
5 2
-1 1 2 0 0


4 11

3 6
2 3
1 1

2 3
999999999 1000000000
**/
//#pragma GCC optimize ("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int N=300010;
const ll mod=998244353;
int cnt[N];
ll f[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    f[0]=1ll;
    for (int i=1;i<=n;i++){
        f[i]=(f[i-1]*(i*1ll))%mod;
    }
    for (int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        cnt[a]++;
        cnt[b]++;
    }
    ll res=n*1ll;
    for (int i=1;i<=n;i++){
        res*=f[cnt[i]];
        res%=mod;
    }
    cout<<res;

    return 0;
}

/*
7 5
4 5 6 1 2 3 7
1 3
1 2
2 2
3 4
6 6
*/
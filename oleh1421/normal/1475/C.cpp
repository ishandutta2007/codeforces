//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=300050;
mt19937 rnd(time(NULL));
const ll mod=1000000007;
int a[N],b[N];
int cntA[N],cntB[N];
void solve(){
    int n,m,k;cin>>n>>m>>k;
    for (int i=1;i<=k;i++) cin>>a[i];
    for (int i=1;i<=k;i++) cin>>b[i];
    for (int i=1;i<=max(n,m);i++) cntA[i]=cntB[i]=0;
    for (int i=1;i<=k;i++){
        cntA[a[i]]++;
        cntB[b[i]]++;
    }
    ll res=0ll;
    for (int i=1;i<=k;i++){
        res+=k-cntA[a[i]]-cntB[b[i]]+1;
    }
    cout<<res/2<<endl;
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
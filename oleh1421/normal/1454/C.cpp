//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=200010;
int cnt[N];
int a[N];
int val[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    for (int i=1;i<=n;i++){
        if (i>1 && a[i-1]!=a[i]){
            val[a[i]]++;
        }
    }
    for (int i=1;i<=n;i++){
        if (i!=a[n]) val[i]++;
    }
    int res=1000000001;
    for (int i=1;i<=n;i++) res=min(res,val[a[i]]);
    for (int i=1;i<=n;i++) val[i]=0;
    cout<<res<<endl;




}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}
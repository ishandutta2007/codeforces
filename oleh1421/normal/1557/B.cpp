//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
#define double long double
using namespace std;
const int N=1000010;
const ll mod=1000000007;
pair<int,int> a[N];
int p[N];
void solve(){
    int n,k;cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i].first,a[i].second=i;
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++) p[a[i].second]=i;
    int need=n;
    for (int i=1;i<n;i++){
        if (p[i]+1==p[i+1]) need--;
    }
    if (need<=k) cout<<"YES\n";
    else cout<<"NO\n";

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
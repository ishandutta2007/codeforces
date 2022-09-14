#include <bits/stdc++.h>
#define endl '\n'
const long long mod=1000000007;
typedef long long ll;
using namespace std;
mt19937_64 rng(time(NULL));
int a[300001];
int b[300001];
int pos[300001];
void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i],pos[a[i]]=i;
    for (int i=1;i<=m;i++) cin>>b[i];
    ll sum=0ll;
    for (int i=1;i<=m;i++){
        int j=i;
        while (j+1<=m && pos[b[i]]>pos[b[j+1]]) j++;
        sum+=((pos[b[i]]-i)*2ll+(j-i+1ll))*1ll;
        i=j;
    }
    cout<<sum<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
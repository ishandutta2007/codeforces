//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=1000010;
const ll mod=1000000007;
vector<int>ans;
int dsu[N];
int get(int x){
    if (dsu[x]==x) return x;
    return dsu[x]=get(dsu[x]);
}
void solve(){
    int n,m;cin>>n>>m;
    for (int i=0;i<=m;i++) dsu[i]=i;
    vector<int>ans;
    for (int i=1;i<=n;i++){
        int k;cin>>k;
        if (k==1){
            int x;cin>>x;
            int y=0;
            x=get(x);
            y=get(y);
            if (x!=y){
                dsu[x]=y;
                ans.push_back(i);
            }
        } else {
            int a,b;cin>>a>>b;
            a=get(a);
            b=get(b);
            if (a!=b){
                dsu[a]=b;
                ans.push_back(i);
            }
        }
    }
    ll res=1ll;
    for (int i=1;i<=ans.size();i++) res=(res*2ll)%mod;
    cout<<res<<" "<<ans.size()<<endl;
    for (int i:ans) cout<<i<<" ";
    cout<<endl;

}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }

    return 0;
}
/*


*/
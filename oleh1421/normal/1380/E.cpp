//#pragma GCC optimize("trapv")
///SOLVE ACMP PROBLEM
#include <bits/stdc++.h>
#define y1 y_1
#define endl '\n'
typedef long long ll;
//#define int ll
using namespace std;
const int N=500010;
int dp[N];
int a[N];
int ind[N];
int get(int x){
    if (x==ind[x]) return x;
    return ind[x]=get(ind[x]);
}
int t[N];
vector<int>g[N];
void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>t[i];
        g[t[i]].push_back(i);
    }
    int res=0;
    for (int i=n-1;i>=1;i--){
        res+=(t[i]!=t[i+1]);
    }
    for (int i=1;i<=m;i++) ind[i]=i;
    cout<<res<<endl;
    for (int i=1;i<m;i++){
        int a,b;cin>>a>>b;
        a=get(a);
        b=get(b);
        if (g[a].size()<g[b].size()){
            ind[a]=b;
            swap(a,b);
        }

        for (auto j:g[b]){
            if (t[j-1]==a) res--;
            if (t[j+1]==a) res--;
        }
        for (auto j:g[b]){
            t[j]=a;
            g[a].push_back(j);
        }
        g[b].clear();
        cout<<res<<endl;
    }

}
int32_t main()
{
//    freopen("cosmo.in","r",stdin);
//    freopen("cosmo.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
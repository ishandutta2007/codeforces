//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef unsigned long long ll;
#define endl '\n'
typedef long double ld;
//#define double ld
using namespace std;
const int N=200010;
int a[N];
int b[N];
int n;
map<int,int>mp;
vector<int>g[N];
int len[N];
int p[N];
int pos[N];
void solve(){
    cin>>n;
    set<int>st;
    for (int i=1;i<=n;i++) cin>>a[i],st.insert(a[i]);
    int tot=0;
    for (auto i:st){
        mp[i]=++tot;
    }
    for (int i=1;i<=n;i++) a[i]=mp[a[i]],g[a[i]].push_back(i);
    int cur=0;
    for (int i=1;i<=n;i++){
        for (auto j:g[i]){
            p[j]=++cur;
            pos[p[j]]=j;
        }
    }
    for (int i=n;i>=1;i--){
        if (pos[p[i]+1]>i) len[i]=len[pos[p[i]+1]]+1;
        else len[i]=1;
    }
    sort(a+1,a+n+1);
    int mx=0;
    for (int i=1;i<=n;i++){
        int l=p[i];
        int r=l+len[i]-1;
//        cout<<l<<" "<<a[l]<<endl;
        if (i!=g[a[l]][0]) continue;
//        if (r!=g[a[])
        int cur=len[i];
        if (r+1<=n) cur+=g[a[r+1]].end()-upper_bound(g[a[r+1]].begin(),g[a[r+1]].end(),pos[r]);
        if (l-1>=1) cur+=lower_bound(g[a[l-1]].begin(),g[a[l-1]].end(),pos[l])-g[a[l-1]].begin();
        mx=max(mx,cur);
    }
    for (int i=1;i<tot;i++){
        int x=i;
        int y=i+1;
        for (int j=0;j<g[x].size();j++){
//            if (j+1+(g[y].end()-upper_bound(g[y].begin(),g[y].end(),g[x][j]))==3) cout<<x<<" "<<y<<endl;
            mx=max(mx,j+1+(g[y].end()-upper_bound(g[y].begin(),g[y].end(),g[x][j])));
        }
    }
//    int mx=0;
//    for (int i=1;i<=n;i++) cout<<a[i]<<" ";
//    cout<<endl;
//    for (int i=1;i<=n;i++){
//        mx=max(mx,dp[i][0]);
//        cout<<i<<" "<<dp[i][0]<<" "<<dp[i][1]<<endl;
////        cout<<i<<" "<<dp[i][1]<<" "<<dp[i][0]<<endl;
//    }
    mp.clear();
    for (int i=0;i<=n+1;i++){
        g[i].clear();
        p[i]=0;
        pos[i]=0;
    }
    cout<<n-mx<<endl;
//    sort(a+1,a+n+1);
//    for (int i=1;i<=n;i++) cout<<a[i]<<" ";
//    cout<<endl;

}
int main()
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
/*
1
4
0 3 3 1
*/
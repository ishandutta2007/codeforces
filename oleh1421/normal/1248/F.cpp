#include <bits/stdc++.h>
#define endl '\n'
#define inf 1000000000000000001ll
#define lcm my_lcm
#define gcd my_gcd
typedef long long ll;
using namespace std;
vector<int>g[1000001];
bool used1[1000001];
void dfs1(int v){
    used1[v]=true;
    for (auto to:g[v]){
        if (used1[to]) continue;
        dfs1(to);
    }
}
vector<int>r[1000001];
bool used2[1000001];
void dfs2(int v){
    used2[v]=true;
    for (auto to:r[v]){
        if (used2[to]) continue;
        dfs2(to);
    }
}

void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++) g[i].clear(),r[i].clear(),used1[i]=used2[i]=false;
    for (int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        if (a==b) continue;
        g[a].push_back(b);
        r[b].push_back(a);
    }
    dfs1(1);
    int cnt1=0;
    for (int i=1;i<=n;i++){
        if (!used1[i]) cnt1++;
    }
    if (cnt1>0){
        cout<<"Yes\n";
        cout<<n-cnt1<<" "<<cnt1<<endl;
        for (int i=1;i<=n;i++) if (used1[i]) cout<<i<<" ";
        cout<<endl;
        for (int i=1;i<=n;i++) if (!used1[i]) cout<<i<<" ";
        cout<<endl;
        return;
    }
    dfs2(1);
    int cnt2=0;
    for (int i=1;i<=n;i++){
        if (!used2[i]) cnt2++;
    }
    if (cnt2>0){
        cout<<"Yes\n";
        cout<<cnt2<<" "<<n-cnt2<<endl;
        for (int i=1;i<=n;i++) if (!used2[i]) cout<<i<<" ";
        cout<<endl;
        for (int i=1;i<=n;i++) if (used2[i]) cout<<i<<" ";
        cout<<endl;
        return;
    }
    cout<<"No\n";

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
5 12
1 1
2 2
3 3
4 4
5 5

5 3
1 5
3 4

4 1
2 3
3 1
1 2
*/
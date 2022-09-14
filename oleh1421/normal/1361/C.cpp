//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
typedef long double ld;
#define double ld
using namespace std;
const int N=500501;
int a[N];
int b[N];
int cnt[(1<<20)+10];
vector<pair<int,int> >g[(1<<20)+10];
bool used[(1<<20)+10];
void dfs(int v){
    used[v]=true;
    for (auto to:g[v]){
        if (!used[to.first]){
            dfs(to.first);
        }
    }
}
bool used1[(1<<20)+10];
vector<int>ans;
void F(int v,int num){
    while (!g[v].empty()){
        auto cur=g[v].back();
        g[v].pop_back();
        if (used1[abs(cur.second)]) continue;
        used1[abs(cur.second)]=true;
        F(cur.first,cur.second);
    }
    ans.push_back(num);

}
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    for (int i=20;i>=0;i--){
        memset(cnt,0,sizeof(cnt));
        for (int j=1;j<=n;j++){
            a[j]%=(1<<i);
            b[j]%=(1<<i);
            g[a[j]].push_back({b[j],-j});
            g[b[j]].push_back({a[j],j});
        }
        int sum=0;
        for (int j=0;j<(1<<i);j++){
            sum+=(g[j].size()%2);
        }
//        cout<<i<<" "<<sum<<endl;
        if (sum){
            for (int j=0;j<(1<<i);j++){
                g[j].clear();
            }
            continue;
        }
        dfs(a[1]);
        bool ok=true;
        for (int j=1;j<=n;j++){
            if (!used[a[j]] || !used[b[j]]){
                for (int t=0;t<(1<<i);t++){
                    used[t]=false;
                    g[t].clear();
                }
                ok=false;
                break;
            }
        }
        if (!ok) continue;
        cout<<i<<endl;
        F(a[1],-1);
        ans.pop_back();
        for (auto i:ans) {
            if (i>0) cout<<i*2-1<<" "<<i*2<<" ";
            else cout<<-i*2<<" "<<-i*2-1<<" ";
        }
        cout<<endl;
        return;

    }

}
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
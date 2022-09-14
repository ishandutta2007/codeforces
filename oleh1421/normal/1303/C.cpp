#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
bool a[30][30];
vector<int>g[30];
bool used[30];
vector<int>order;
bool ok=true;
void dfs(int v,int pr){
    used[v]=true;
    order.push_back(v);
    for (auto to:g[v]){
        if (to==pr) continue;
        if (used[to]){
//            cout<<v<<" "<<to<<endl;
            ok=false;
            return;
        }

        dfs(to,v);
    }
}
void solve(){
    string s;cin>>s;
    for (int i=0;i<26;i++) for (int j=0;j<26;j++) a[i][j]=0;
    for (int i=0;i<26;i++) used[i]=false;
    for (int i=1;i<s.size();i++){
        a[s[i]-'a'][s[i-1]-'a']=1;
        a[s[i-1]-'a'][s[i]-'a']=1;
    }
    vector<int>rt;
    for (int i=0;i<26;i++){
        g[i].clear();
        for (int j=0;j<26;j++){
            if (a[i][j]) {
                g[i].push_back(j);
            }
        }
        if (g[i].size()>2){
            cout<<"NO\n";
            return;
        }
        if (g[i].size()<=1) rt.push_back(i);
    }
    ok=true;
    order.clear();
    for (auto i:rt) if (!used[i]) dfs(i,-1);
    if (!ok || order.size()!=26) cout<<"NO\n";
    else {
        cout<<"YES\n";
        for (auto i:order) cout<<char(i+'a');
        cout<<endl;
    }
}

int32_t main()
{
//    freopen("repair.in","r",stdin);
//    freopen("repair.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;

}
#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
vector<int>g[200001];
char s[200001];
bool used[200001];
void dfs(int v){
     used[v]=true;
     for (auto to:g[v]){
        if (!used[to]) dfs(to);
     }
}
int p[200001];
int p1[200001];
int q[200001];
int q1[200001];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>p[i],p1[p[i]]=i;
    for (int i=1;i<=n;i++) cin>>q[i],q1[q[i]]=i;
    for (int i=2;i<=n;i++){
        g[p[i]].push_back(p[i-1]);
        g[q[i]].push_back(q[i-1]);
    }
    int cnt=int('a')-1;
    for (int i=1;i<=n;i++){
        if (used[p[i]]){
            s[p[i]]=char(cnt);
            continue;
        }
        cnt++;
        cnt=min(cnt,int('z'));
        s[p[i]]=char(cnt);
        dfs(p[i]);
    }
    if (cnt-int('a')+1>=k){
        cout<<"YES\n";
        for (int i=1;i<=n;i++) cout<<s[i];
        return 0;
    }
    cout<<"NO";
    return 0;
}


///2007521364118
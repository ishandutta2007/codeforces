//#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
typedef long double ld;
using namespace std;
const int N=200010;
vector<int>g[N];
int cnt[2];
void dfs(int v,int pr,int cur){
    cnt[cur]++;
    for (auto to:g[v]){
        if (to!=pr){
            dfs(to,v,(cur^1));
        }
    }
}
int main()
{
//    freopen("bluetube.in","r",stdin);
//    freopen("bluetube.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0,0);
    cout<<min(cnt[0],cnt[1])-1<<endl;

    return 0;
}
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
vector<int> adj[200002];
bool visited[200002]={0};
bool visited2[200002]={0};
vector<int> cycleq;
bool cycle[200002];
vector<ll> ans;

int dfs(int s, int parent){
    //printf("%d %d\n", s, parent);
    visited[s]=1;
    for (auto &y:adj[s]){
        if (y==parent) continue;
        if (visited[y]) return y;
        cycleq.push_back(y);
        int tmp=dfs(y, s);
        if (tmp==0) cycleq.pop_back();
        else return tmp;
    }
    return 0;
}

void find_cycle(){
    cycleq.push_back(1);
    int tmp=dfs(1, -1);
    bool test=0;
    for (auto &y:cycleq){
        //printf("%d ", y);
        if (!test){
            if (tmp==y){
                test=1;
                cycle[y]=1;
            }
        }
        else{
            cycle[y]=1;
        }
    }
    //printf("\n");
}

ll find_branch(int s){
    visited2[s]=1;
    ll ans=1;
    for (auto &y:adj[s]){
        if (visited2[y]) continue;
        if (cycle[y]) continue;
        ll tmp=find_branch(y);
        ans += tmp;
    }
    return ans;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        cycleq.clear();
        ans.clear();
        for (int i=0;i<=n;i++){
            visited[i]=0;
            visited2[i]=0;
            cycle[i]=0;
            adj[i].clear();
        }
        for (int i=0;i<n;i++){
            int tmp1, tmp2;
            scanf("%d %d", &tmp1, &tmp2);
            adj[tmp1].push_back(tmp2);
            adj[tmp2].push_back(tmp1);
        }
        find_cycle();
        for (int i=1;i<=n;i++){
            ll tmp;
            if (cycle[i]){
                tmp=find_branch(i);
                //printf("%d ", i);
                //printf("%lld ", ans.size());
                ans.push_back(tmp);
            }
        }
        //printf("\n");
        //printf("%lld\n", ans.size());
        ll real_ans=0;
        for (auto &y:ans){
            //printf("%lld\n", y);
            ll tmpp=y;
            real_ans += (tmpp*(tmpp-1))/2;
        }
        ll tmpx=n;
        ll fans=tmpx*(tmpx-1)-real_ans;
        printf("%lld\n", fans);
    }
    return 0;
}
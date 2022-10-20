#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
vector<int> adj1[300300], adj2[300300];
pair<int, int> euler[300300];
set<pair<int, int>> st;
int cnt = 1, ans = 1;

void dfs0(int s){
    euler[s].first = cnt++;
    for (auto &v:adj2[s]) dfs0(v);
    euler[s].second = cnt++;
}

void dfs(int s){
    bool flag = 0;
    pair<int, int> tmp;
    auto iter = st.lower_bound(euler[s]);
    if (iter==st.begin()) st.insert(euler[s]);
    else{
        --iter;
        auto p = *iter;
        if (p.first<euler[s].first && euler[s].second<p.second){
            st.erase(iter); st.insert(euler[s]);
            flag = 1;
            tmp = p;
        }
        else st.insert(euler[s]);
    }
    ans = max(ans, (int)st.size());
    for (auto &v:adj1[s]) dfs(v);
    st.erase(st.find(euler[s]));
    if (flag) st.insert(tmp);
}

void solve(){
    int n;
    scanf("%d", &n);
    for (int i=2;i<=n;i++){
        int x;
        scanf("%d", &x);
        adj1[x].push_back(i);
    }
    for (int i=2;i<=n;i++){
        int x;
        scanf("%d", &x);
        adj2[x].push_back(i);
    }
    dfs0(1);
    dfs(1);
    printf("%d\n", ans);
    ///init here
    for (int i=1;i<=n;i++){
        adj1[i].clear();
        adj2[i].clear();
        euler[i] = {0, 0};
    }
    cnt = 1, ans = 1;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}
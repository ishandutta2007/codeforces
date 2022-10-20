#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[300300];
vector<int> pos[300300];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i=0;i<n;i++){
        scanf("%d", a+i);
        pos[a[i]].push_back(i+1);
    }
    stack<pair<int, int>> st;
    st.push({n+1, n+1});
    for (int i=1;i<=n;i++) if (!pos[i].empty()){
        int d = pos[i][0];
        for (int j=0;j<(int)pos[i].size()-1;j++) d = max(d, pos[i][j+1]-pos[i][j]);
        d = max(n+1-pos[i].back(), d);
        if (st.top().second>d) st.push({i, d});
    }
    for (int i=1;i<st.top().second;i++) printf("-1 ");
    while(!st.empty()){
        auto cur = st.top();
        st.pop();
        if (st.empty()) break;
        auto nxt =  st.top();
        for (int i=cur.second;i<nxt.second;i++) printf("%d ", cur.first);
    }
    printf("\n");
    for (int i=1;i<=n;i++) pos[i].clear();
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}
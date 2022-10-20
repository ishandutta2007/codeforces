#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int col[100100], a[100100];

int query(int s){
    printf("? %d\n", s);
    fflush(stdout);

    int ret;
    scanf("%d", &ret);
    return ret;
}

void solve(){
    int n;
    scanf("%d", &n);
    fill(col, col+n+1, 0);
    set<pair<int, int>> st;
    for (int i=1;i<=n;i++){
        scanf("%d", a+i);
        st.emplace(a[i], i);
    }

    int cnt = 0;

    while(!st.empty()){
        //for (auto &[d, s]:st) printf("(%d %d) ", d, s);
        //printf("\n");
        auto [d, s] = *st.rbegin();
        vector<int> cur = {s};
        int idx = -1;
        for (int i=1;i<=d;i++){
            int v = query(s);
            if (col[v]){
                idx = v;
                break;
            }
            cur.push_back(v);
        }

        if (idx==-1){
            ++cnt;
            for (auto &v:cur) col[v] = cnt;
        }
        else{
            for (auto &v:cur) col[v] = col[idx];
        }

        for (auto &v:cur) st.erase(st.find(make_pair(a[v], v)));
    }

    printf("! ");
    for (int i=1;i<=n;i++) printf("%d ", col[i]);
    printf("\n");
    fflush(stdout);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}
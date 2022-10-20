#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
struct DSU{
    int path[1010], sz[1010];
    void init(int n){for (int i=1;i<=n;i++) path[i] = i, sz[i] = 1;}
    int find(int s){
        if (s==path[s]) return s;
        return path[s] = find(path[s]);
    }
    void merge(int s, int v){
        int x = find(s), y = find(v);
        path[x] = y;
        sz[y] += sz[x];
    }
    int size(int x){
        return sz[find(x)];
    }
}dsu;

int main(){
    int n, q;
    scanf("%d %d", &n, &q);

    int cnt = 0;
    multiset<int> st;
    dsu.init(n);
    for (int i=1;i<=n;i++) st.insert(1);
    for (int i=1;i<=q;i++){
        int x, y;
        scanf("%d %d", &x, &y);
        if (dsu.find(x)==dsu.find(y)) cnt++;
        else{
            st.erase(st.find(dsu.size(x)));
            st.erase(st.find(dsu.size(y)));
            dsu.merge(x, y);
            st.insert(dsu.size(x));
        }

        auto iter = st.rbegin();
        int ans = -1;
        for (int j=0;j<=cnt;j++){
            if (iter==st.rend()) {ans += cnt-j+1; break;}
            ans += *iter;
            iter++;
        }
        assert(ans<n && ans>=0);
        printf("%d\n", ans);
    }
    return 0;
}
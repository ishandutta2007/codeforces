#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
vector<int> adj[1010];
pair<int, int> dfn[2020];

int cur = 0;
void dfs(int s, int pa = -1){
    for (auto &v:adj[s]) if (v!=pa){
        dfn[cur++] = {s, v};
        dfs(v, s);
        dfn[cur++] = {s, v};
    }
}

int cnt = 0;
int query(vector<int> &v){
    cnt++;
    assert(cnt<=12);
    printf("? ");
    printf("%d ", (int)v.size());
    for (auto &x:v) printf("%d ", x);
    printf("\n");
    fflush(stdout);
    int ret;
    scanf("%d", &ret);
    return ret;
}

int ans, val;
void dnc(int l, int r){
    if (r-l==1) {ans = l; return;}
    int m = (l+r)>>1;
    vector<int> Q;
    for (int i=l;i<m;i++){
        Q.push_back(dfn[i].first);
        Q.push_back(dfn[i].second);
    }
    sort(Q.begin(), Q.end()); Q.erase(unique(Q.begin(), Q.end()), Q.end());
    if (val==query(Q)) dnc(l, m);
    else dnc(m, r);

}

int main(){
    int n;
    scanf("%d", &n);
    for (int i=0;i<n-1;i++){
        int x, y;
        scanf("%d %d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1);
    vector<int> tmp;
    for (int i=1;i<=n;i++) tmp.push_back(i);
    val = query(tmp);
    dnc(0, (n-1)*2);
    printf("! %d %d\n", dfn[ans].first, dfn[ans].second);
    fflush(stdout);
    return 0;
}
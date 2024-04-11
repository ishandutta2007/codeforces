#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[505][505], n,  cur, r, val[5050];
vector<int> adj[5050];

void build(vector<int> &v, int root, int num = -1){
    if (v.empty()) return;
    vector<int> tmp;
    for (int i=1;i<=n;i++) if (i!=v[0]) tmp.push_back(a[i][v[0]]);
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    int prv = v[0];
    for (auto &x:tmp){
        if (x>=root) break;
        adj[cur].push_back(prv);
        val[cur] = x;
        vector<int> k;
        for (int i=1;i<=n;i++) if (a[i][v[0]]==x){
            k.push_back(i);
        }
        prv = cur;
        cur++;
        build(k, x, cur-1);
    }
    tmp.clear();
    for (auto &x:v) if (a[x][v[0]]==root) tmp.push_back(x);
    build(tmp, root, num);
    if (num!=-1) adj[num].push_back(prv);
    else r = prv;
}

int main(){
    scanf("%d", &n);
    cur = n+1;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++) scanf("%d", a[i]+j);
        val[i] = a[i][i];
    }
    vector<int> v;
    for (int i=1;i<=n;i++) v.push_back(i);
    build(v, 1e9);
    printf("%d\n", cur-1);
    for (int i=1;i<cur;i++) printf("%d ", val[i]);
    printf("\n");
    printf("%d\n", r);
    for (int i=1;i<cur;i++){
        for (auto &x:adj[i]) printf("%d %d\n", x, i);
    }
    return 0;
}
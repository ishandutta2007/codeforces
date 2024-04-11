#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
map<int, int> pattern;
set<pair<int, int>> chk;
int st[100100], deg[100100], k, ptval[100100];
vector<int> adj[100100];
char cur[5];

void make_graph(int v0, int val, int rm, int tx){
    if (rm==k){
        if (pattern.find(val)==pattern.end()) return;
        int tmp=pattern[val];
        //printf("FOUND: %d\n", tmp);
        if (tx==tmp) return;
        if (chk.find(make_pair(tx, tmp))!=chk.end()) return;
        deg[tmp]++;
        adj[tx].push_back(tmp);
        chk.insert(make_pair(tx, tmp));
        //printf("%d %d\n", tx, tmp);
        return;
    }
    make_graph(v0, val, rm+1, tx);
    int ex=1;
    for (int i=0;i<rm;i++) ex *= 27;
    make_graph(v0, val-(cur[rm]-'a'+1)*ex, rm+1, tx);
}

bool mt(int val, int str){
    bool ret=1;
    for (int i=0;i<k;i++, str /= 27, val /= 27){
        if (val%27==0) continue;
        if (val%27!=str%27) ret=0;
    }
    return ret;
}

int main(){
    int n, m;
    scanf("%d %d %d", &n, &m, &k);
    for (int i=0;i<n;i++){
        char tmp[5];
        scanf("%s", tmp);
        int val=0, ex=1;
        for (int j=0;j<k;j++, ex *= 27){
            if (tmp[j]=='_') continue;
            val += (tmp[j]-'a'+1)*ex;
        }
        pattern[val]=i+1;
        ptval[i+1]=val;
        //printf("%d %d\n", val, i+1);
    }
    for (int i=0;i<m;i++){
        int tx;
        scanf("%s", cur);
        scanf("%d", &tx);
        int val=0, ex=1;
        for (int j=0;j<k;j++){
            val += (cur[j]-'a'+1)*ex;
            ex *= 27;
        }
        if (!mt(ptval[tx], val)){
            printf("NO\n");
            return 0;
        }
        make_graph(val, val, 0, tx);
    }
    queue<int> q;
    for (int i=1;i<=n;i++) if (!deg[i]) q.push(i);
    vector<int> ans;
    while(!q.empty()){
        int tmp=q.front();
        q.pop();
        ans.push_back(tmp);
        for (int v:adj[tmp]){
            deg[v]--;
            if (!deg[v]) q.push(v);
        }
    }
    if ((int)ans.size()!=n){
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    for (int x:ans) printf("%d ", x);
    printf("\n");
    return 0;
}
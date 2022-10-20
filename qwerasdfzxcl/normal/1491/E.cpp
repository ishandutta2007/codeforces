#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
vector<int> adj[200100];
ll val[200200], fib[30], fibrev[200200];
int sz;
bool chk, ans=1;

void dfs2(int s, int pa){
    for (int v:adj[s]) if (v!=pa){
        if (val[v]!=val[s]) continue;
        dfs2(v, s);
    }
    val[s] *= 2;
}

int dfs(int s, int pa){
    int ret=0;
    for (int v:adj[s]) if (v!=pa){
        if (val[v]!=val[s]) continue;
        ret += dfs(v, s);
    }
    ret++;
    if (!chk && (fibrev[ret]==sz-1 || fibrev[ret]==sz-2)){
        dfs2(s, pa); chk=1;
    }
    return ret;
}

void dnc(vector<int> &v){
    if ((int)v.size()<=2) return;
    ll cur=val[v[0]];
    sz=fibrev[(int)v.size()];
    chk=0;
    dfs(v[0], -1);
    vector<int> tmp1, tmp2;
    for (int x:v){
        if (val[x]==cur*2) tmp1.push_back(x);
        else{
            tmp2.push_back(x);
            val[x]=cur*2+1;
        }
    }
    if (tmp1.empty()){
        ans=0; return;
    }
    dnc(tmp1); dnc(tmp2);
}

int main(){
    fib[0]=1, fib[1]=1, fibrev[1]=1;
    for (int i=2;i<30;i++){
        fib[i]=fib[i-1]+fib[i-2];
        if (fib[i]<200200) fibrev[fib[i]]=i;
    }
    int n;
    scanf("%d", &n);
    if (!fibrev[n]){
        printf("NO\n"); return 0;
    }
    for (int i=0;i<n-1;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> tmp;
    for (int i=1;i<=n;i++){
        val[i]=1;
        tmp.push_back(i);
    }
    dnc(tmp);
    if (ans) printf("YES\n");
    else printf("NO\n");
    return 0;
}
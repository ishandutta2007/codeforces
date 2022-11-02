#include <bits/stdc++.h>
#define maxn 300300
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

vector<int> L[maxn];
int ans[maxn];

int bad(int v){
    int t = 0;
    for(int i=0;i<(int)L[v].size();i++)
        if(ans[v] == ans[L[v][i]])
            t++;
    return (t > 1);
}

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b), a--, b--;
        L[a].pb(b);
        L[b].pb(a);
    }
    set<int> S;
    for(int i=0;i<n;i++)
        if(bad(i))
            S.insert(i);
    while(S.size()){
        int u = *(S.begin());
        S.erase(u);
        if(!bad(u))
            continue;
        ans[u] ^= 1;
        for(int i=0;i<(int)L[u].size();i++)
            if(bad(L[u][i])){
                S.insert(L[u][i]);
            }
    }
    for(int i=0;i<n;i++)
        printf("%d",ans[i]);
    printf("\n");
}
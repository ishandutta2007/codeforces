#include <bits/stdc++.h>
#define pii pair<int,int>
#define pb push_back
#define maxn 100100
using namespace std;

vector<int> L[maxn];
int ans;

int dfs(int v,int p=1){
    int f = L[v].size();
    if(v != 1) f--;
    if(f == 0){
        return 1;
    }
    int t = 1;
    for(int i=0;i<L[v].size();i++)
        if(L[v][i] != p)
            t += dfs(L[v][i],v);
    if(t%2 == 0 && v != 1) ans++;
    return t;
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        L[a].pb(b);
        L[b].pb(a);
    }
   dfs(1);
   if(n%2 == 1) ans = -1;
   printf("%d\n",ans);
}
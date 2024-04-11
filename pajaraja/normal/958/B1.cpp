#include <bits/stdc++.h>
using namespace std;
vector<int> g[1007];
int main(){
    int n, u, v;
    scanf("%d", &n);
    for(int i=1; i<n; ++i){
        scanf("%d%d", &u, &v);
        g[u].push_back(v); g[v].push_back(u);
    }
    int br=0;
    for(int i=1; i<=n; ++i) if(g[i].size()==1) br++;
    printf("%d", br);
    return 0;
}
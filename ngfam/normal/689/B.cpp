/* Riven is not just my life :) */

#include <bits/stdc++.h>
#define prob "test"
typedef long long llint;
using namespace std;
void MAIN();
int main(){
    #ifndef ONLINE_JUDGE
        freopen(prob".inp","r",stdin);
      //  freopen(prob".out","w",stdout);
    #endif
    MAIN();
    return 0;
}
const llint N = 1e6 + 1, mod = 1e9 + 7;

int a[N], n, path[N];
queue < int > q;

void MAIN(){
    scanf("%d", &n);
    memset(path, 60, sizeof path);
    path[1] = 0;
    for(int i = 1; i <= n; ++i){
        scanf("%d", a + i);
    }

    q.push(1);
    while(!q.empty()){
        int u = q.front(); q.pop();
        if(u > 1 && path[u - 1] > path[u] + 1){
            path[u - 1] = path[u] + 1;
            q.push(u - 1);
        }
        if(u < n && path[u + 1] > path[u] + 1){
            path[u + 1] = path[u] + 1;
            q.push(u + 1);
        }
        if(path[a[u]] > path[u] + 1){
            path[a[u]] = path[u] + 1;
            q.push(a[u]);
        }
    }
    for(int i = 1; i <= n; ++i){
        printf("%d ", path[i]);
    }
}
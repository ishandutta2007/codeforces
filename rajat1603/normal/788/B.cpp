#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
int n , m;
int deg[N];
long long ans;
int parent[N];
int find(int node){
    if(parent[node] == node){
        return node;
    }
    return parent[node] = find(parent[node]);
}
bool ok[N];
int main(){
    scanf("%d %d" , &n , &m);
    for(int i = 1 ; i <= n ; ++i){
        parent[i] = i;
        deg[i] = 0;
        ok[i] = 0;
    }
    int cnt = 0;
    int who = -1;
    for(int i = 1 ; i <= m ; ++i){
        int a , b;
        scanf("%d %d" , &a , &b);
        parent[find(b)] = find(a);
        ok[a] = 1;
        ok[b] = 1;
        who = a;
        if(a == b){
            ++cnt;
        }
        else{
            ++deg[a];
            ++deg[b];
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        if(ok[i]){
            if(find(i) != find(who)){
                cout << 0 << endl;
                return 0;
            }
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        ans += 1LL * deg[i] * (deg[i] - 1LL);
    }
    ans += 1LL * cnt * (cnt - 1LL);
    ans >>= 1;
    ans += 1LL * cnt * (m - cnt);
    cout << ans << endl;
}
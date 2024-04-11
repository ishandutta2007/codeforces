#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
vector < int > v[N];
int a , b;
int n , m;
bool color[N];
bool visited[N];
long long ans = 0;
int zero;
int one;
bool ok = 1;
void dfs(int node){
    for(int next : v[node]){
        if(visited[next]){
            if(color[next] == color[node]){
                ok = 0;
                return;
            }
        }
        else{
            visited[next] = 1;
            color[next] = color[node] ^ 1;
            one += color[next];
            zero += color[node];
            dfs(next);
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i = 1 ; i <= m ; ++i){
        cin >> a >> b;
        v[a].emplace_back(b);
        v[b].emplace_back(a);
    }
    if(m == 0){
        cout << "3 " << 1LL * n * (n - 1) * (n - 2) / 6;
    }
    else{
        int mx = 0;
        for(int i = 1 ; i <= n ; ++i){
            mx = max(mx , int(v[i].size()));
        }
        if(mx == 1){
            cout << "2 " << 1LL * m * (n - 2);
        }
        else{
            for(int i = 1 ; i <= n ; ++i){
                if(!visited[i]){
                    visited[i] = 1;
                    color[i] = 1;
                    one = 1;
                    zero = 0;
                    dfs(i);
                    ans += 1LL * one * (one - 1) / 2;
                    ans += 1LL * zero * (zero - 1) / 2;
                }
            }
            if(ok){
                cout << "1 " << ans;
            }
            else{
                cout << "0 1";
            }
        }
    }
}
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 6;
const int mod = 1e9 + 7;
int mult(int a , int b){
    long long res = a;
    res *= b;
    if(res >= mod){
        return res % mod;
    }
    return res;
}
bool visited[N];
int p , k;
int ans = 1;
int nxt[N];
void dfs(int node , int val){
    if(visited[node]){
        if(val == 1){
            ans = mult(ans , p);
        }
        return;
    }
    visited[node] = 1;
    dfs(nxt[node] , (1LL * val * k) % p);
}
int main(){
    cin >> p >> k;
    if(k == 0){
        for(int i = 1 ; i < p ; ++i){
            ans = mult(ans , p);
        }
        cout << ans;
        return 0;
    }
    for(int i = 0 ; i < p ; ++i){
        nxt[i] = (1LL * i * k) % p;
    }
    for(int i = 0; i < p; i++){
        if(!visited[i]){
            dfs(i , 1);
        }
    }
    cout << ans;
}
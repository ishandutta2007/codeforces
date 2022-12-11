#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 9;
vector<pii> T[N];



int n, k;

int col[N];
int opt;

void dfs(int u, int par, int cl){
    if(T[u].size() > opt){
        for(auto x : T[u]){
            if(x.fi != par){
                col[x.se] = 1;
                dfs(x.fi, u, 1);
            }
        }
    }
    else{
        int p = 1 + (cl == 1);
        for(auto x : T[u]){
            if(x.fi != par){
                col[x.se] = p;
                dfs(x.fi, u, p);
                p ++ ;
                if(p == cl) p ++ ;
            }
        }
    }
}

bool ok(int vl){
    int cnt = 0;
    for(int i = 1; i <= n; i ++ ){
        cnt += (T[i].size() > vl);
    }
    return cnt <= k;
}
int main(){
    fastIO;
    cin >> n >> k;
    int u, v;
    for(int i = 1; i < n; i ++ ){
        cin >> u >> v;
        T[u].push_back(mp(v,i));
        T[v].push_back(mp(u,i));
    }
    int L = 1, R = n - 1;
    int M;
    while(L<R){
        M = (L+R)/2;
        if(ok(M))
            R = M;
        else
            L = M + 1;
    }
    opt = L;
    cout << opt << "\n";
    dfs(1,-1,-1);
    for(int i = 1; i < n; i ++ ){
        cout << col[i] << " ";
    }
    return 0;
}
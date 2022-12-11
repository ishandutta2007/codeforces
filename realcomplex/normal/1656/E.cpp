#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 10;
vector<int> f[2];
int A[N];
vector<int> T[N];

void dfs(int u, int pa, int bit){
    f[bit].push_back(u);
    for(auto x : T[u]){
        if(x == pa) continue;
        dfs(x, u, bit ^ 1);
    }
}

int main(){
    fastIO;
    //freopen("in.txt","r",stdin);
    int tc;
    cin >> tc;
    int n;
    int u, v;
    for(int iq = 1; iq <= tc; iq ++ ){
        cin >> n;
        f[0].clear();
        f[1].clear();
        for(int i = 1; i <= n; i ++ ){
            T[i].clear();
        }
        for(int i = 1; i < n; i ++ ){
            cin >> u >> v;
            T[u].push_back(v);
            T[v].push_back(u);
        }
        dfs(1, -1, 0);
        for(auto x : f[0]){
            A[x] = T[x].size();
        }
        for(auto x : f[1]){
            A[x] = -(int)T[x].size();
        }
        for(int i = 1; i <= n; i ++ ){
            cout << A[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
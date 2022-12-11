#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
vector<int> T[N];
ll A[N];
ll leaf[N];
ll ans = 0ll;

void dfs(int u){
    for(auto x : T[u]){
        dfs(x);
        A[u] += A[x];
        leaf[u] += leaf[x];
    }
    if(T[u].empty())
        leaf[u]=1;
    ans = max(ans, (A[u] + leaf[u] - 1) / leaf[u]);
}

int main(){
    fastIO;
    int n;
    cin >> n;
    int p;
    for(int i = 2; i <= n; i ++ ){
        cin >> p;
        T[p].push_back(i);
    }
    for(int i = 1; i <= n; i ++ ){
        cin >> A[i];
    }
    dfs(1);
    cout << ans << "\n";
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 100, inf = 1e9 + 100, mod = 1e9 + 993;

int n;

int e[maxn], in[maxn];

bool vis[maxn];

int dfs(int v){
    vis[v] = 1;
    if (vis[e[v]])
        return 1;
    return 1 + dfs(e[v]);
}

int main(){
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> e[i];
        e[i]--;
        in[e[i]]++;
    }
    for (int i = 0; i < n; i++)
    if (in[i] == 0){
        cout << -1;
        return 0;
    }
    ll answer = 1;
    for (int i = 0; i < n; i++)
    if (!vis[i]){
        ll x = dfs(i);
        if (x % 2 == 0)
            x /= 2;
        answer = answer * x / __gcd(answer, x);
    }
    cout << answer;
}
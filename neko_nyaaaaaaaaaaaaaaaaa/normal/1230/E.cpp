#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll n, b[100005], res;
vector<ll> a[100005];
map<ll, int> m[100005];
bool fre[100005];
const ll Modulo = 1e9 + 7;

void join(ll u, ll v){
    map<ll,int>::iterator iv;
    for(iv = m[v].begin(); iv != m[v].end();iv++){
        ll val = iv->first, sl = iv->second;
        if(val == 0) val = b[u];
        else if(b[u] != 0) val = __gcd(val, b[u]);
        res = (res + (val * sl) % Modulo) % Modulo;
        m[u][val] += sl;
    }
}
void dfs(ll u, ll prev){
    m[u][b[u]]++;
    if (prev != 0) join(u, prev);
    
    fre[u] = false;
    bool isLeaf = true;
    for(int i = 0;i < a[u].size();i++){
        ll v = a[u][i];
        if(fre[v]) {
            isLeaf = false;
            dfs(v, u);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> b[i], res = (res + b[i]) % Modulo;
    for(int i = 1;i < n;i++){
        ll u, v; cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    memset(fre, true, sizeof fre);
    dfs(1, 0);
    cout << res;
    return 0;
}
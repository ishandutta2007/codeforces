#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll (i) = 0; (i) < (ll)(t); (i)++)
#define reu(i, s, e) for(ll (i) = (ll)(s); (i) <= (ll)(e); (i)++)
#define rer(i, s, e) for(ll (i) = (ll)(s); (i) < (ll)(e); (i)++)
#define For(i, v) for(__typeof((v).begin()) (i) = (v).begin(); (i) != (v).end(); (i) ++)
#define mset(arr, val) memset(arr, (val), sizeof arr)
#define pb push_back
#define mp make_pair
#define p1 first
#define p2 second

typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<int, int> pie;

const int maxn = 3e4 + 10;
bool mark[maxn];
int v[maxn];

void dfs(int x){
    mark[x] = true;
    if(!mark[v[x] + x])
        dfs(v[x] + x);
}

int main(){
    ios_base::sync_with_stdio(false);
    int n, t;
    cin >> n >> t;
    rer(i, 1, n)
        cin >> v[i];
    dfs(1);
    if(mark[t])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
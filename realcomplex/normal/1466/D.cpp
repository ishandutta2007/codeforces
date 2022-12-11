#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 100;
int w[N];
int d[N];

void solve(){
    int n;
    cin >> n;
    ll sol = 0;
    for(int i = 1; i <= n; i ++ ){
        cin >> w[i];
        d[i]=0;
        sol += w[i];
    }
    int u, v;
    for(int i = 1; i < n; i ++ ){
        cin >> u >> v;
        d[u] ++ ;
        d[v] ++ ;
    }
    vector<int> add;
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j < d[i]; j ++ ){
            add.push_back(w[i]);
        }
    }
    sort(add.begin(), add.end());
    reverse(add.begin(),add.end());
    for(int i = 0 ; i < n - 1; i ++ ){
        cout << sol << " ";
        if(i + 1 < n - 1)
            sol += add[i];
    }
    cout << "\n";
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t ++ ){
        solve();
    }
    return 0;
}
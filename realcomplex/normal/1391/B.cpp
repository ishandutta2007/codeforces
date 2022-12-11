#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 105;
pii par[N][N];

int n, m;

bool valid(int i, int j){
    return (i >= 1 && j >= 1 && i <= n && j <= m);
}

pii fin(pii a){
    if(a == par[a.fi][a.se]) return a;
    return par[a.fi][a.se]=fin(par[a.fi][a.se]);
}

int cnt;

void unite(pii a, pii b){
    a=fin(a);
    b=fin(b);
    if(a==b)
        return;
    cnt--;
    par[a.fi][a.se]=b;
}

void solve(){
    cin >> n >> m;
    char f;
    int ni, nj;
    cnt = n * m;
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j <= m ; j ++ ){
            par[i][j] = mp(i,j);
            cin >> f;
            if(f == 'L'){
                if(valid(i,j-1))unite(mp(i,j),mp(i,j-1));
            }
            else if(f == 'R'){
                if(valid(i, j+1)) unite(mp(i,j), mp(i,j+1));
            }
            else if(f == 'D'){
                if(valid(i+1, j)) unite(mp(i,j), mp(i+1,j));
            }
            else if(f == 'U'){
                if(valid(i-1, j)) unite(mp(i,j), mp(i-1,j));
            }
        }
    }
    cout << cnt - 1 << "\n";
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t ++ )
        solve();
    return 0;
}
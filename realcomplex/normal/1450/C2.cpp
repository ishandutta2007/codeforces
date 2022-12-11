#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 310;
char f[N][N];

void solve(){
    int n;
    cin >> n;
    vector<pii> g[3][2];
    int p;
    for(int i = 0 ; i < n; i ++ ){
        for(int j = 0 ; j < n; j ++ ){
            cin >> f[i][j];
            p = (i+j)%3;
            if(f[i][j] == 'X') g[p][0].push_back(mp(i,j));
            else if(f[i][j] == 'O') g[p][1].push_back(mp(i,j));
        }
    }
    int low = (int)1e9;
    int ii = -1, jj = -1;
    int cur;
    for(int i = 0 ; i < 3; i ++ ){
        for(int j = 0 ; j < 3; j ++ ){
            if(i == j) continue;
            cur = g[i][0].size() + g[j][1].size(); // this works right?
            if(cur < low){
                low = cur;
                ii = i;
                jj = j;
            }
        }
    }
    for(auto x : g[ii][0]) f[x.fi][x.se] = 'O';
    for(auto x : g[jj][1]) f[x.fi][x.se] = 'X';
    for(int i = 0 ; i < n; i ++ ){
        for(int j = 0 ; j < n; j ++ ){
            cout << f[i][j];
        }
        cout << "\n";
    }
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t ++ )
        solve();
    return 0;
}
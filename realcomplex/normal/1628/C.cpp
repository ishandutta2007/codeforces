#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int dir[4][2] = {{-1,0},{+1,0},{0,-1},{0,+1}};

const int N = 1005;
bool pp[N][N];
int xr[N][N];

void place(int ii, int jj, int ui, int uj){
    vector<pii> Q;
    Q.push_back(mp(ii, jj));
    Q.push_back(mp(ui, uj));
    for(int d = 0; d < 4; d ++ ){
        Q.push_back(mp(ii + dir[d][0], jj + dir[d][1]));
        Q.push_back(mp(ui + dir[d][0], uj + dir[d][1]));
    }
    for(auto x : Q){
        if(pp[x.fi][x.se]) return;
    }
    xr[ii][jj]=1;
    xr[ui][uj]=1;
    for(auto x : Q){
        pp[x.fi][x.se]=true;
    }
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        int n;
        cin >> n;
        for(int i = 0 ; i <= n + 1; i ++ ){
            for(int j = 0 ; j <= n + 1; j ++ ){
                xr[i][j] = 0;
                pp[i][j] = false;
            }
        }
        if(n % 4 == 2){
            for(int i = 1; i <= n; i += 4){
                place(1, i, 1, i + 1);
            }
        }
        else{
            for(int i = 2; i <= n; i += 4){
                place(1, i, 1, i + 1);
            }
        }
        for(int i = 1; i <= n; i ++ ){
            for(int j = 1; j <= n; j ++ ){
                if(j + 1 <= n){
                    place(i, j, i, j + 1);
                }
                if(i + 1 <= n){
                    place(i, j, i + 1, j);
                }
            }
        }
        int A;
        int res = 0;
        for(int i = 1; i <= n; i ++ ){
            for(int j = 1; j <= n; j ++ ){
                cin >> A;
                if(xr[i][j] == 1) res ^= A;
            }
        }
        cout << res << "\n";
    }
    return 0;
}
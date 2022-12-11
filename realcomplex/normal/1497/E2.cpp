#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
const int M = (int)1e7 + 10;
int red[M];

map<int, int> pos;

int dp[N][21];
int cut[N][21];

void upd(int i, int j, int val, int cc){
    if(dp[i][j] > val){
        dp[i][j] = val;
        cut[i][j] = cc;
    }
    else if(dp[i][j] == val){
        cut[i][j] = max(cut[i][j], cc);
    }
}

void solve(){
    int n, k;
    cin >> n >> k;
    int las = 0;
    pos.clear();
    int a;
    for(int i = 0; i <= n; i ++ ){
        for(int j = 0 ;j <= k ; j ++ ){
            dp[i][j]=(int)1e9;
            cut[i][j]=-1;
        }
    }
    dp[0][0]=1;
    cut[0][0]=0;
    for(int i = 1; i <= n; i ++ ){
        cin >> a;
        a = red[a];
        for(int j = 0; j <= k ; j ++ ){
            if(dp[i-1][j] == (int)1e9) continue;
            if(pos.count(a) && pos[a] > cut[i-1][j]){
                upd(i, j, dp[i-1][j] + 1, i-1);
                if(j + 1 <= k)
                    upd(i, j + 1, dp[i-1][j], cut[i-1][j]);
            }
            else{
                upd(i, j, dp[i-1][j], cut[i-1][j]);
            }
        }
        pos[a]=i;
    }
    int sol = (int)1e9;
    for(int j = 0; j <= k; j ++ )
        sol = min(sol, dp[n][j]);
    cout << sol << "\n";
}

int main(){
    fastIO;
    for(int i = 1; i < M ;i ++ ){
        red[i]=i;
    }
    for(int i = 2; i * i < M; i ++ ){
        if(red[i] == i){
            for(int j = 2 * i; j < M; j += i){
                while(red[j] % (i * i) == 0){
                    red[j] /= (i * i);
                }
            }
        }
    }
    int tc;
    cin >> tc;
    for(int it = 1; it <= tc; it ++ ){
        solve();
    }
    return 0;
}
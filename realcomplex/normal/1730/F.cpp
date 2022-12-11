#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 5010;
const int K = 8;
const int inf = (int)1e9;

int dp[N][(1 << K)];
int p[N];
int pos[N];
int V[N][N];



int main(){
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i ++ ){
        cin >> p[i];
        pos[p[i]] = i;
    }
    for(int i = 1 ; i <= n + 1; i ++ ){
        for(int j = 0 ; j < (1 << k); j ++ ){
            dp[i][j] = inf;
        }
    }
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j <= i ; j ++ ){
            V[i][pos[j]] ++ ;
        }
        for(int j = n; j >= 0; j -- ){
            V[i][j] += V[i][j+1];
        }
    }
    dp[1][0] = 0;
    int res;
    int cur;
    int ni;
    int nmask;
    for(int i = 1; i <= n; i ++ ){
        for(int mask = 0; mask < (1 << k); mask ++ ){
            if(dp[i][mask] == inf) continue;
            for(int j = -1 ; j < k ; j ++ ){
                if(j != -1 && (mask & (1 << j))) continue;
                if(i + (j + 1) > n) continue;
                cur = i + (j + 1);
                res = dp[i][mask];
                res += V[i - 1][pos[cur]];
                for(int jj = 0 ; jj < k ; jj ++ ){
                    if((mask & (1 << jj))){
                        if(pos[cur] < pos[i + (jj + 1)])
                            res ++ ;
                    }
                }
                ni = i;
                nmask = mask;
                if(j == -1){
                    for(int p = 0 ; p <= k ; p ++ ){
                        if(!(mask & (1 << p))){
                            ni = i + p + 1;
                            nmask = (mask >> (p + 1));
                            break;
                        }
                    }
                }
                else{
                    nmask |= (1 << j);
                }
                dp[ni][nmask] = min(dp[ni][nmask], res);
            }
        }
    }
    cout << dp[n + 1][0] << "\n";
    return 0;
}
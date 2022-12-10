#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll (i) = 0; (i) < (ll)(t); (i)++)
#define reu(i, s, e) for(ll (i) = (ll)(s); (i) <= (ll)(e); (i)++)
#define rer(i, s, e) for(ll (i) = (ll)(s); (i) < (ll)(e); (i)++)
#define For(i, v) for(__typeof((v).begin()) (i) = (v).begin(); (i) != (v).end(); (i) ++)
#define mset(arr, val) memset(arr, (val), sizeof arr)
#define PB push_back
#define MP make_pair
#define p1 first
#define p2 second

typedef long long int ll;
typedef pair<int, int> pie;

const int maxn = 5e5 + 10, maxk = 26;
int dp[maxn][maxk];
int par[maxn][maxk];

int main(){
    //ios_base::sync_with_stdio(false);
    int n, k;
    scanf("%d%d", &n, &k);
    char s[n];
    scanf("%s", s);
    rep(j, k)
        dp[0][j] = 1;
    dp[0][s[0] - 'A'] = 0;
    int min1 = 0, min2 = 1;
    int idmin1 = s[0] - 'A', idmin2 = 0;
    if(s[0] == 'A')
        idmin2 = 1;
    rer(i, 1, n){
        int tmin1 = 1e9, tmin2 = 1e9;
        int idtmin1, idtmin2;
        rep(j, k){
            if(j + 'A' == s[i]){
                if(dp[i - 1][j] == min1 and idmin1 == j){
                    dp[i][j] = min2;
                    par[i][j] = idmin2;
                }
                else{
                    dp[i][j] = min1;
                    par[i][j] = idmin1;
                }
            }
            else{
                if(dp[i - 1][j] == min1 and idmin1 == j){
                    dp[i][j] = min2 + 1;
                    par[i][j] = idmin2;
                }
                else{
                    dp[i][j] = min1 + 1;
                    par[i][j] = idmin1;
                }
            }
            if(dp[i][j] < tmin1){
                tmin2 = tmin1;
                idtmin2 = idtmin1;
                tmin1 = dp[i][j];
                idtmin1 = j;
            }
            else if(dp[i][j] < tmin2){
                tmin2 = dp[i][j];
                idtmin2 = j;
            }
        }
        min1 = tmin1;
        idmin1 = idtmin1;
        min2 = tmin2;
        idmin2 = idtmin2;
    }
    if(min1 == min2)
        swap(idmin1, idmin2);
    printf("%d\n", min1);
    int id = idmin1;
    for(int i = n - 1; i >= 0; i--){
        //cerr << "id = " << id << endl;
        s[i] = id + 'A';
        id = par[i][id];
    }
    printf("%s\n", s);
    return 0;
}
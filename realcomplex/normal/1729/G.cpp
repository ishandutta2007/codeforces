#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 510;
const int MOD = (int)1e9 + 7;
bool valid[N];
int dp[N][N];
bool one[N][N];
void solve(){
    string s;
    cin >> s;
    string t;
    cin >> t;
    int n = s.size();
    int m = t.size();
    for(int i = 0 ; i < n; i ++ ){
        valid[i]=false;
        if(i + m - 1 < n){
            valid[i]=true;
            for(int j = 0 ; j < m ; j ++ ){
                if(s[i + j] != t[j]){
                    valid[i]=false;
                }
            }
        }
    }
    for(int i = 0 ; i <= n; i ++ ){
        for(int j = 0 ; j <= n; j ++ ){
            one[i][j]=false;
            dp[i][j]=0;
        }
    }
    bool can;
    int emp = 0;
    int big;
    for(int i = 0 ; i < n; i ++ ){
        if(valid[i]){
            emp = 1;
            can = true;
            for(int j = 0 ; j + m - 1 < i ; j ++ ){
                if(valid[j]) can = false;
            }
            if(can){
                one[i][1]=true;
                dp[i][1]=1;
            }
            for(int k = 2; k <= i + 1; k ++ ){
                big = -1;
                for(int v = i - 1; v >= 0 ; v -- ){
                    if(v + m - 1 >= big && v + m - 1 < i){
                        one[i][k] |= one[v][k - 1];
                        dp[i][k] = (dp[i][k] + dp[v][k - 1]) % MOD;
                    }
                    if(valid[v] && v + m - 1 < i && big == -1) big = v;
                }
            }
        }
    }
    if(emp == 0){
        cout << "0 1\n";
        return;
    }
    int res;
    for(int p = 1; p <= n; p ++ ){
        big = -1;
        res = -1;
        for(int i = n - 1; i >= 0 ; i -- ){
            if(valid[i]){
                if(big == -1) big = i;
                if(one[i][p] && i + m - 1 >= big){
                    if(res == -1) res = 0;
                    res = (res + dp[i][p]) % MOD;
                }
            }
        }
        if(res >= 0){
            cout << p << " " << res << "\n";
            return;
        }
    }

}


int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}
#include "bits/stdc++.h"
using namespace std;
const int N = 5015;
const int mod = 1e9 + 7;
inline int add(int a , int b){
    int res = a + b;
    if(res >= mod){
        return res - mod;
    }
    return res;
}
int n;
string str;
int ans = 0;
int dp1[N][N];
int dp2[N][N];
int dp3[N][N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    cin >> str;
    str = " " + str;
    for(int i = n ; i >= 1 ; --i){
        for(int j = i + 1 ; j <= n + 1 ; ++j){
            if(j > n){
                dp1[i][j] = -1;
            }
            else if(str[i] != str[j]){
                dp1[i][j] = j;
            }
            else{
                dp1[i][j] = dp1[i + 1][j + 1];
            }
        }
    }
    for(int pos = n + 1 ; pos >= 1 ; --pos){
        for(int lst = 1 ; lst < pos ; ++lst){
            if(pos > n){
                dp2[pos][lst] = 1;
                continue;
            }
            if(str[pos] == '0'){
                continue;
            }
            int tmp = dp1[pos - lst][pos];
            if(tmp == -1 || tmp > pos + lst - 1 || str[tmp] < str[tmp - lst]){
                tmp = pos + lst;
            }
            else{
                tmp = pos + lst - 1;
            }
            int len = tmp - pos + 1;
            if(tmp <= n){
                dp2[pos][lst] = dp3[tmp + 1][len];
            }
        }
        for(int len = 1 ; len <= n ; ++len){
            if(pos > n){
                dp3[pos][len] = 1;
            }
            else{
                dp3[pos][len] = add(dp3[pos + 1][len + 1] , dp2[pos][len]);
            }
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        ans = add(ans , dp2[i + 1][i]);
    }
    cout << ans;
}
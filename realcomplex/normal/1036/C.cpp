#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair

string to_s(ll y){
    string ans;
    do{
        ans.push_back(char(y % 10 + '0'));
        y /= 10;
    }while(y > 0);
    reverse(ans.begin(), ans.end());
    return ans;
}

ll Calc(ll x){
    string check = to_s(x);
    int N = check.size();
    ll dp[N + 1][4][2];
    memset(dp, 0, sizeof dp);
    dp[0][0][0] = 1;
    int digit;
    int nx;
    for(int i = 1;i <= N; i ++ ){
        digit = check[i - 1] - '0';
        for(int x = 0; x < 10; x ++ ){
            for(int z = 0; z < 4; z ++ ){
                nx = (z + (x > 0));
                if(nx < 4){
                    nx = (z + (x > 0));
                    if(x < digit){
                        dp[i][nx][1] += dp[i - 1][z][0] + dp[i - 1][z][1];
                    }
                    else if(x == digit){
                        dp[i][nx][0] += dp[i - 1][z][0];
                        dp[i][nx][1] += dp[i - 1][z][1];
                    }
                    else{
                        dp[i][nx][1] += dp[i - 1][z][1];
                    }
                }
            }
        }
    }
    ll ans = 0ll;
    for(int z = 0; z < 4; z ++ )
        ans += dp[N][z][0] + dp[N][z][1];
    return ans;
}

int main(){
    int q;
    scanf("%d", &q);
    ll L, R;
    for(int i = 0; i < q;i ++ ){
        scanf("%lli %lli", &L, &R);
        printf("%lli\n", Calc(R) - Calc(L - 1));
    }
    return 0;
}
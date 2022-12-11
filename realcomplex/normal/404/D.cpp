#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define INF 1e18

void open(){
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
}

const ll M = 1e9+7;

ll dp[1000005][5];

/* dp states
    0 - mine
    1 - empty
    2 - left has mine
    3 - right has mine
    4 - both sides has mines
*/

int main(){
    //open();
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;
    cin >> s;
    int n = s.size()-1;
    if(s[0] == '?' || s[0] == '*') dp[0][0] = 1;
    if(s[0] == '?' || s[0] == '0') dp[0][1] = 1;
    if(s[0] == '?' || s[0] == '1') dp[0][3] = 1;
    for(int j = 1;j<s.size();j++){
        if(s[j] == '?' || s[j] == '*'){ // correct... said by a dumpling
            dp[j][0] = (dp[j-1][0]+dp[j-1][3])%M;
            dp[j][0] = (dp[j][0]+dp[j-1][4])%M;
        }
        if(s[j] == '?' || s[j] == '0'){ // seems correct
            dp[j][1] = (dp[j-1][2]+dp[j-1][1])%M;
        }
        if(s[j] == '?' || s[j] == '1'){
            dp[j][2] = dp[j-1][0];
            dp[j][3] = (dp[j-1][2]+dp[j-1][1])%M;
        }
        if(s[j] == '?' || s[j] == '2'){
            dp[j][4] = dp[j-1][0];
        }
    }
    ll rez = 0;
    rez += dp[n][0];
    rez %= M;
    rez += dp[n][1];
    rez %= M;
    rez += dp[n][2];
    rez %= M;
    cout << rez;
    return 0;
}
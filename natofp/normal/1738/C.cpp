#include <bits/stdc++.h>
#include <random>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>
#define ld long double
#define ull unsigned long long
#define mt make_tuple

using namespace std;

const int nax = 305;
bool dp[nax][nax][2];

void solve(){
    for(int i=0;i<nax;i++){
        for(int j=0;j<nax;j++){
            for(int k=0;k<2;k++){
                dp[i][j][k] = false;
            }
        }
    }
    dp[0][0][0] = true;
    for(int s=1;s<202;s++){
        for(int a=0;a<=s;a++){
            int b = s - a;
            for(int j=0;j<2;j++){
                int opp_want = j;
                if(a % 2 == 0) opp_want ^= 1;

                if(a > 0 && !dp[a - 1][b][opp_want]) dp[a][b][j] = true;
                if(b > 0 && !dp[a][b - 1][opp_want]) dp[a][b][j] = true;
            }
        }
    }
    int n; cin >> n;
    int c = 0;
    for(int i=1;i<=n;i++){
        int x; cin >> x;
        x = abs(x);
        if(x % 2 == 1) c++;
    }
    if(dp[c][n - c][0]) cout << "Alice" << "\n";
    else cout << "Bob" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}
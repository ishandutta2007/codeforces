#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 10000000
#define mp make_pair
#define fi first
#define se second

int main(){

    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,k;
    cin >> n >> k;
    int dp[n];
    cin >> dp[0];
    int t = 0;
    for(int j = 1;j<n;j++){
        cin >> dp[j];
        if(dp[j]+dp[j-1] < k){
            t += k-(dp[j]+dp[j-1]);
            dp[j] += k-(dp[j]+dp[j-1]);
        }
    }
    cout << t << "\n";
    for(int j = 0;j<n;j++){
        cout << dp[j] << " ";
    }
    return 0;
}
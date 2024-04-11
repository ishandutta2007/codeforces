#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);



int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t =0 ; t < tc; t ++ ){
        int n,q;
        cin >> n >> q;
        ll dp[2];
        ll nw[2];
        dp[0]=dp[1]=0;
        ll a;
        for(int i = 0 ; i < n; i ++ ){
            cin >> a;
            for(int j = 0 ; j < 2; j ++ )
                nw[j] = 0;
            nw[1]=max(dp[1],dp[0]+a);
            nw[0]=max(dp[0],dp[1]-a);
            for(int j = 0 ; j < 2; j ++ )
                dp[j]=nw[j];
        }
        cout << max(dp[0], dp[1]) << "\n";
    }
    return 0;
}
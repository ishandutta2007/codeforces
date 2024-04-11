#include<bits/stdc++.h>

using namespace std;

#define int long long

/*int eukli[1000010];
int li;
void init() {
    for( int i=2; i<=1000000; i++ ) {
        if( eukli[i] == 0 ) {
                //cout << i << " ";
            li++;
            for( int j=i+i; j<=1000000; j+=i ) {
                eukli[j] = i;
            }
        }
    }
}*/

pair<int, int> dp[2000010];

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n, x, y;
    vector<int> v;
    cin >> n >> x >> y;
    for( int a, i=1; i<=n; i++ ) {
        cin >> a;
        dp[a].second++;
    }
    for( int i=1; i<=2000000; i++ ) {
        dp[i].first = dp[i-1].first+dp[i-1].second;
        dp[i].second += dp[i-1].second;
    }
    int res = numeric_limits<int>::max();
    for( int i=2; i<=1000000; i++ ) {
        int wy=0;
        for( int j=i; j<=1000000+i; j+=i ) {
            int a = max( j-i, j-(x/y)-1 );
            if( dp[j].first-dp[a].first-dp[a].second*(j-a) > 1000000ll ) {
                wy = numeric_limits<int>::max();
                break;
            }
            wy += (dp[j].first-dp[a].first-dp[a].second*(j-a))*y;
            if( j-i < a ) {
                wy += (dp[a].second-dp[j-i].second)*x;
            }
            if( wy > 1000000000000000ll ) break;
        }
        res = min( res, wy );
    }
    cout << res;

    return 0;
}
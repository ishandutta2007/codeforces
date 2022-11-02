#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll11

int dp[1000010];
int  t[1000010];
int gdzie[1000010];

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n;
    cin >> n;
    for( int i=1; i<=n; i++ ) {
        cin >> t[i];
        gdzie[ t[i] ] = i;
    }
    for( int i=n; i>0; i-- ) {
        int a = gdzie[i];
        for( int j=a%i; j<=n; j+=i ) {
            if( t[j] > i && a!=j && !dp[j] ) dp[a] = 1;
        }
    }
    for( int i=1; i<=n; i++ ) {
        if( dp[i] ) cout << "A";
        else cout << "B";
    }

    return 0;
}
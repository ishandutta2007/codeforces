#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll

double a[1000010];
double b[1000010];
vector<double> v;
double dp[1000010];

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n, m;
    cin >> n >> m;
    for( int i=0; i<n; i++ ) cin >> a[i];
    cin >> b[n-1];
    for( int i=0; i<n-1; i++ ) cin >> b[i];
    for( int i=0; i<n; i++ ) {
        v.push_back( a[i] );
        v.push_back( b[i] );
    }

    dp[v.size()] = m;
    for( int i=(int)v.size()-1; i>=0; i-- ) {
        if( v[i] == 1 ) {
            cout << -1;
            return 0;
        }
        dp[i] = dp[i+1]/(v[i]-1)+dp[i+1];
        //cout << v[i] << ",";
        //cout << dp[i] << " ";
    }
    cout << fixed << setprecision( 10 ) << dp[0]-m;


    return 0;
}
#include<bits/stdc++.h>

using namespace std;

#define int long long
#define mod 1000000007ll

int sx, sy;
int ile=0;

int32_t main(){
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n, m;
    char c;
    cin >> n >> m;
    for( int i=1; i<=n; i++ ) {
        for( int j=1; j<=m; j++ ) {
            cin >> c;
            if( c=='B' ){
                sx += i;
                sy += j;
                ile++;
            }
        }
    }
    cout << sx/ile << " " << sy/ile;

    return 0;
}
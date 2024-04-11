#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double

int ile[1000010];
int czas[1000010];

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n;
    cin >> n;
    czas[1] = 1;
    for( int a, i=2; i<=n; i++ ) {
        cin >> a;
        czas[i] = czas[a]+1;
        ile[czas[i]]++;
    }

    int res=1;
    for( int i=1; i<=n; i++ ) {
        if( ile[i]%2 ) res++;
    }
    cout << res;

    return 0;
}
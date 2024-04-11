#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000

vector<int> v;

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n, xxx, yyy;
    cin >> n >> xxx >> yyy;
    int k = xxx+yyy;
    for( int a, i=0; i<n; i++ ) {
        cin >> a;
        v.push_back( a );
    }
    priority_queue<int> kol;
    for( int a, i=0; i<n; i++ ) {
        cin >> a;
        kol.push( abs(a-v[i]) );
    }
    int x;
    while( k-- ) {
        x = kol.top();
        kol.pop();
        kol.push( abs(x-1) );
    }

    int res=0;
    while( !kol.empty() ) {
        res += kol.top()*kol.top();
        kol.pop();
    }
    cout << res;

    return 0;
}
/*

*/
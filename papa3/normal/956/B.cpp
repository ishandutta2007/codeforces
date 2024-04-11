#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define MAX_N 300010

int tab[1000010];
int t[1000010];

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n, u;
    cin >> n >> u;
    for( int i=1; i<=n; i++ ) {
        cin >> tab[i];
        t[i] = tab[i]-tab[i-1];
    }

    pair<int, int> res = {0, 1};
    int kon=1;
    int suma=0;
    for( int pocz=2; pocz<n; pocz++ ) {
        while( kon<n && suma+t[kon+1] <= u ) {
            suma += t[kon+1];
            kon++;
        }
        if( pocz < kon ) {
            if( (double)res.first/(double)res.second < (double)(suma-t[pocz])/(double)suma ) {
                res = {suma-t[pocz], suma};
            }
        }
        suma -= t[pocz];
    }
    if( res.first == 0 ) {
        cout << -1;
    } else {
        cout << fixed << setprecision( 12 ) << (double)res.first/(double)res.second;
    }


    return 0;
}
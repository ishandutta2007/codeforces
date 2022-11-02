#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define INF 1000000000000000000ll
#define mod 1000000007

int ile[100010];
int wy[10000][200];
int suma[100000];
int n, m ,q;
int w[100000];

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    cin >> n >> m >> q;
    for( int i=n-1; i>=0; i-- ) {
        cin >> w[i];
    }
    for( int a, i=0; i<m; i++ ) {
        string s;
        cin >> s;
        a=0;
        for( char c : s ) {
            a*=2;
            if( c=='1' ) a++;
        }
        ile[a]++;
    }
    for( int i=0; i<(1<<n); i++ ) {
        for( int j=0; j<n; j++ ) {
            if( (1<<j)&i ) suma[i] += w[j];
        }
    }
    int x = (1<<n)-1;
    for( int p, i=0; i<(1<<n); i++ ) {
        for( int j=0; j<(1<<n); j++ ) {
            p = (i^j)^x;
            if( suma[p] > 100 ) continue;
            wy[j][ suma[p] ] += ile[i];
        }
    }
    for( int i=0; i<(1<<n); i++ ) {
        for( int j=1; j<=100; j++ ) {
            wy[i][j] += wy[i][j-1];
        }
    }
    for( int a, b, i=0; i<q; i++ ) {
        string s;
        cin >> s >> b;
        a=0;
        for( char c : s ) {
            a*=2;
            if( c=='1' ) a++;
        }
        cout << wy[a][b] << "\n";
    }


    return 0;
}
/*
for( int i=0; i<n; i++ ) {
        for( int mask=0; mask < (1<<n); mask++ ) {
            if( mask & (1<<i) )
                ile[mask] += ile[mask^(1<<i)];
        }
    }
    for( int suma, mask=0; mask<(1<<n); mask++ ) {
        suma = 0;
        for( int i=0; i<n; i++ ) {
            if( (1<<i) & mask ) suma += w[i];
        }
        cout << mask << " " << suma << endl;
        for( int i=suma; i<=100; i++ ) {
            dp[mask][i] = ile[mask^x];
        }
    }
    /*for( int j=0; j<=100; j++ ) {
        for( int i=0; i<n; i++ ) {
            for( int mask=0; mask < (1<<n); mask++ ) {
                if( mask & (1<<i) )
                    dp[mask][j] += dp[mask^(1<<i)][j];
            }
        }
    }
    for( int a, b, i=1; i<=q; i++ ) {
        string s;
        cin >> s;
        a=0;
        for( char c : s ) {
            a*=2;
            if( c=='1' ) a++;
        }
        cin >> b;
        cout << dp[a][b] << "\n";
    }*/
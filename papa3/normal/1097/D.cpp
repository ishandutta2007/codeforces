#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
const long long mod = 1000000007ll;
const long long INF = 1000000000000000000ll;

int32_t dp[55][10010][55];
int odw[10000];
vector<int> v;
int k;

int pot( int n, int k=mod-2 ) {
    int res=1;
    while( k ) {
        if( k%2 ) res = res*n%mod;
        k/=2;
        n = n*n%mod;
    }
    return res;
}

map<int, int> m;
int res;

void algo( int suma=1, int p=1, auto it = m.begin() ) {
    if( it==m.end() ) {
        res = (res+suma*p)%mod;
        return;
    }
    auto it2 = it;
    it2++;
    for( int i=0; i<=it->second; i++ ) {
        algo( suma, p*dp[it->second][k][i]%mod, it2 );
        suma = suma*it->first%mod;
    }
}

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n;
    cin >> n >> k;
    for( int i=2; i<40000000ll; i++ ) {
        while( n%i == 0 ) {
            v.push_back( i );
            m[i]++;
            n/=i;
        }
    }
    if( n>1 ) {
        v.push_back( n );
        m[n]++;
    }
    for( int i=0; i<=50; i++ ) {
        dp[i][0][i] = 1;
        odw[i+1] = pot( i+1 );
        for( int j=1; j<=k; j++ ) {
            for( int x=i; x>=0; x-- ) {
                dp[i][j][x] = (dp[i][j][x+1]+dp[i][j-1][x]*odw[x+1])%mod;
            }
        }
    }

    algo( 1, 1, m.begin() );
    cout << res;

    /*int pom = pot( pot( 2, k ) );
    int pom2 = (1+mod-pom)%mod;
    //cout << pom << " " << pom2 << endl;
    int res=0;
    int l = (int)v.size();
    for( int mask=0; mask<(1<<l); mask++ ) {
        int p=1;
        int suma=1;
        for( int i=0; i<l; i++ ) {
            if( mask & (1<<i) ) {
                p = pom*p%mod;
                suma *= v[i];
            } else {
                p = pom2*p%mod;
            }
        }
        //cout << suma << " " << p << "  " << suma*p%mod << endl;
        res = (res+p*suma)%mod;
    }
    cout << res;*/


    return 0;
}/*

*/
#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll

bool tab[1000010];
set<int> s;

map<pair<pair<int, int>, int>, int> res;

void zmien( int gdzie ) {
    tab[gdzie] ^= 1;
    if( tab[gdzie] ) s.insert( gdzie );
    else s.erase( gdzie );
}

void foo( int gdzie ) {
    res[ {{gdzie, gdzie+1}, gdzie+2} ]++;
}

void wypisz() {
    cout << "YES\n";
    int wy=0;
    for( auto i : res ) {
        if( i.second%2 )
        wy++;
    }
    cout << wy << "\n";
    for( auto i : res ) {
        if( i.second%2 )
        cout << i.first.first.first << " " << i.first.first.second << " " << i.first.second << "\n";
    }
}

int n;
pair<int, int> dp[1000010];

void odkoduj( int x, int n ) {
    for( int i=0; i<n; i++ ) {
        if( (1<<i) & x ) cout << i+1 << " ";
    }
    cout << "\n";
}

void bar() {
    for( int i=0; i<(1<<n); i++ ) {
        dp[i] = {INF, INF};
    }
    int s=0;
    for( int i=1; i<=n; i++ ) {
        if( tab[i] ) s += (1<<(i-1));
    }
    dp[s] = {0, -1};
    for( int sr=0; sr<n; sr++ ) {
        for( int i=1; i<n; i++ ) {
            if( sr-i < 0 || sr+i >= n ) continue;
            int pom = (1<<(sr-i)) + (1<<sr) + (1<<(sr+i));
            for( int mask=0; mask<(1<<n); mask++ ) {
                if( dp[mask^pom].first > dp[mask].first+1 ) {
                    dp[mask^pom].first = dp[mask].first+1;
                    dp[mask^pom].second = pom;
                }
            }
        }
    }
    if( dp[0].first != INF ) {
        cout << "YES\n";
        cout << dp[0].first << "\n";
        int gdzie = 0;
        while( dp[gdzie].first != 0 ) {
            odkoduj( dp[gdzie].second, n );
            gdzie = gdzie^dp[gdzie].second;
        }
    } else {
        cout << "NO\n";
    }
}

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );


    cin >> n;
    for( int i=1; i<=n; i++ ) {
        cin >> tab[i];
        if( tab[i] ) s.insert( i );
    }
    if( n<=18 ) {
        bar();
        return 0;
    }

    for( int i=1; i<=n; i++ ) {
        if( tab[i] == 0 ) continue;
        auto it = s.begin();
        it++;
        if( it == s.end() ) {
            break;
        }
        int b = *it;
        b = 2*b-i;
        if( b<=n ) {
            zmien( i );
            res[ {{i, *it}, b} ]++;
            zmien( *it );
            zmien( b );
        } else {
            int x = (n-i)/2;
            if( x==0 ) {
                break;
            }
            zmien( i );
            zmien( i+x );
            zmien( i+x+x );
            res[ {{i, i+x}, i+x+x} ]++;
        }
    }
    if( s.size() == 0 ) {
        wypisz();
        return 0;
    }
    if( s.size() == 2 ) {
        zmien( n-2 );
        zmien( n-1 );
        zmien( n );
        res[ {{n-2, n-1}, n} ]++;
    }
    int pom = *s.begin();
    while( pom-3 < 1 ) {
        pom += 3;
    }
    while( pom+3 > n ) {
        pom -= 3;
    }
    if( pom-3 >= 1 ) {
        int gdzie = *s.begin();
        s.erase( s.begin() );
        while( gdzie-3 < 1 ) {
            foo( gdzie );
            foo( gdzie+1 );
            gdzie += 3;
        }
        while( gdzie+3 > n ) {
            foo( gdzie-2 );
            foo( gdzie-3 );
            gdzie -= 3;
        }
        res[ {{gdzie-3, gdzie}, gdzie+3} ]++;
        foo( gdzie-3 );
        foo( gdzie-2 );
        foo( gdzie );
        foo( gdzie+1 );
        wypisz();
        return 0;
    }
    cout << "NO\n";

    return 0;
}/*

*/
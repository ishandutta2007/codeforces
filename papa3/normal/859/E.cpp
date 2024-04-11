#include<bits/stdc++.h>

using namespace std;

//#define int long long
#define mod 1000000007ll

vector<int> drogi[2000010];
vector<int> trans[2000010];
stack<int> stos;
bool visited[2000010];
int ojciec[2000010];

int f( int where ) {
    if( where == ojciec[where] ) return where;
    return ojciec[where] = f( ojciec[where] );
}
void u( int u, int v ) {
    ojciec[ f(u) ] = f(v);
}

void dfs( int where ) {
    visited[where] = true;
    for( int i : drogi[where] ) {
        if( !visited[i] ) dfs( i );
    }
    stos.push( where );
}

void dfs2( int where ) {
    visited[where] = false;
    for( int i : trans[where] ) {
        if( visited[i] ) {
            u( i, where );
            dfs2( i );
        }
    }
}

void odhacz( int where ) {
    visited[where] = true;
    for( int i : trans[where] ) {
        if( !visited[i] ) odhacz( i );
    }
}

int algo( int where ) {
    int x=1;
    for( int i : trans[where] ) {
        x+=algo( i );
    }
    return x;
}

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n;
    cin >> n;
    for( int i=1; i<=2*n; i++ ) {
        ojciec[i] = i;
    }
    for( int a, b, i=1; i<=n; i++ ) {
        cin >> a >> b;
        drogi[a].push_back( b );
        trans[b].push_back( a );
    }

    for( int i=1; i<=2*n; i++ ) {
        if( !visited[i] ) {
            dfs( i );
        }
    }
    while( !stos.empty() ) {
        if( visited[stos.top()] ) {
            dfs2( stos.top() );
        }
        stos.pop();
    }

    long long wy = 1;
    for( int i=1; i<=2*n; i++ ) {
        if( f( i ) != i && visited[i] == false ) {
            wy*=2;
            if( wy>mod ) wy-=mod;
            odhacz( i );
        }
    }
    for( int i=1; i<=2*n; i++ ) {
        if( drogi[i].size() == 0 && !visited[i] ) {
            wy = wy*algo( i )%mod;
        }
    }
    cout << wy;

    return 0;
}
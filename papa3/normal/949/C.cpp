#include<bits/stdc++.h>

using namespace std;

//#define int long long
#define double long double

vector<int> drogi[1000010];
vector<int> trans[1000010];
stack<int> stos;

int val[1000010];
bool czy[1000010];
int ojciec[1000010];

int f( int gdzie ) {
    if( ojciec[gdzie] == gdzie ) return gdzie;
    return ojciec[gdzie] = f( ojciec[gdzie] );
}

void u( int a, int b ) {
    ojciec[ f(a) ] = f(b);
}

void dfs( int gdzie ) {
    czy[gdzie] = true;
    for( int i : drogi[gdzie] ) {
        if( !czy[i] ) {
            dfs( i );
        }
    }
    stos.push( gdzie );
}

void dfs2( int gdzie ) {
    czy[gdzie] = false;
    for( int i : trans[gdzie] ) {
        if( czy[i] ) {
            u( gdzie, i );
            dfs2( i );
        }
    }
}

int wie[1000010];
bool kon[1000010];

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n, m, h;
    cin >> n >> m >> h;
    for( int i=1; i<=n; i++ ) {
        cin >> val[i];
        ojciec[i] = i;
    }
    for( int a, b, i=0; i<m; i++ ) {
        cin >> a >> b;
        if( (val[a]+1)%h == val[b] ) {
            drogi[a].push_back( b );
            trans[b].push_back( a );
            //cout << " " << a << " " << b << "\n";
        }
        swap( a, b );
        if( (val[a]+1)%h == val[b] ) {
            drogi[a].push_back( b );
            trans[b].push_back( a );
            //cout << " " << a << " " << b << "\n";
        }
    }

    for( int i=1; i<=n; i++ ) {
        if( !czy[i] ) dfs( i );
    }
    while( !stos.empty() ) {
        if( czy[stos.top()] ) dfs2( stos.top() );
        stos.pop();
    }

    for( int i=1; i<=n; i++ ) {
        wie[ f(i) ]++;
        for( int j : drogi[i] ) {
            if( f(j) != f(i) ) kon[ f(i) ] = true;
        }
    }

    int res = n+1;
    int id;

    for( int i=1; i<=n; i++ ) {
        if( f(i) != i ) continue;
        if( kon[i] ) continue;
        if( res > wie[i] ) {
            res = wie[i];
            id = i;
        }
    }

    cout << res << "\n";
    for( int i=1; i<=n; i++ ) {
        if( f(i) == id ) {
            cout << i << " ";
        }
    }

    return 0;
}
/*



*/
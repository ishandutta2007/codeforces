#include<bits/stdc++.h>

using namespace std;

#define int long long

vector<int> drogi[1000010];
vector<int> trans[1000010];

int czy[2][1000010];

stack<int> stos;

void dfs( int gdzie, bool jak=0, int gl=1 ) {

    for( int i : drogi[gdzie] ) {
        if( czy[jak^1][i] ) {

        } else {
            czy[jak^1][i] = gdzie;
            dfs( i, jak^1, gl+1 );
        }
    }
}

bool odw[1000010];

void alg( int gdzie ) {
    odw[gdzie] = 1;
    for( int i : drogi[gdzie] ) {
        if( !odw[i] ) alg( i );
    }
    stos.push( gdzie );
}

int ojciec[1000010];
int f( int x ) {
    if( ojciec[x] == x ) return x;
    return ojciec[x] = f( ojciec[x] );
}
void u( int a, int b ) {
    ojciec[ f(a) ] = f(b);
}

void algo( int gdzie ) {
    odw[gdzie] = 0;
    for( int i : trans[gdzie] ) {
        if( odw[i] ) {
            u( gdzie, i );
            algo( i );
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n, m;
    cin >> n >> m;
    for( int a, b, i=1; i<=n; i++ ) {
        cin >> a;
        for( int j=0; j<a; j++ ) {
            cin >> b;
            drogi[i].push_back( b );
            trans[b].push_back( i );
        }
        ojciec[i] = i;
    }

    int s;
    cin >> s;
    czy[0][s] = -1;
    dfs( s );
    for( int i=1; i<=n; i++ ) {
        if( !odw[i] ) alg( i );
    }
    while( !stos.empty() ) {
        if( odw[ stos.top() ] ) algo( stos.top() );
        stos.pop();
    }

    bool remis = 0;
    for( int i=1; i<=n; i++ ) {
        if( czy[1][i] && drogi[i].size()==0 ) {
            cout << "Win\n";
            stack<int> wy;
            pair<int, int> gdzie = {1, i};
            while( gdzie.second != -1 ) {
                wy.push( gdzie.second );
                gdzie.second = czy[gdzie.first][gdzie.second];
                gdzie.first ^= 1;
            }
            while( ! wy.empty() ) {
                cout << wy.top() << " ";
                wy.pop();
            }
            return 0;
        }
        if( f(i) != i && (czy[1][i] || czy[0][i]) ) remis = 1;
    }
    if( remis ) cout << "Draw";
    else cout << "Lose";

    return 0;
}

//muyhopstrepntesoee
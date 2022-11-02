#include<bits/stdc++.h>

using namespace std;

long long tab[200020];
vector<pair<long long, long long> > drogi[200020];
long long przodkowie[200020][20], glebia[200020];
long long dist[200020][20], wy[200020];

struct moj {
    long long war, dl;
    moj * lewy, * prawy;
    moj( long long w=0 ) {
        war=w;
        dl=0;
        lewy = nullptr;
        prawy = nullptr;
    }
};

moj * mer( moj * pi, moj * dru ) {
    if( pi == nullptr ) {
        return dru;
    }
    if( dru == nullptr ) {
        return pi;
    }
    if( pi->war < dru->war ) {
        swap( pi, dru );
    }
    pi->prawy = mer( pi->prawy, dru );
    if( pi->prawy == nullptr ) {
        pi->dl = 1;
        return pi;
    }
    if( pi->lewy == nullptr ) {
        pi->dl = 1;
        swap( pi->lewy, pi->prawy );
        return pi;
    }
    if( pi->prawy->dl > pi->lewy->dl ) {
        swap( pi->lewy, pi->prawy );
    }
    pi->dl = pi->prawy->dl+1;
    return pi;
};

moj* kol[200020];

void uzu( long long gdzie ) {
    for( long long i=1; i<20; i++ ) {
        przodkowie[gdzie][i] = przodkowie[ przodkowie[gdzie][i-1] ][ i-1 ];
        dist[gdzie][i] = dist[gdzie][i-1]+dist[ przodkowie[gdzie][i-1] ][ i-1 ];
    }
}

void DFS( long long gdzie = 1, long long gl = 1, long long oj=0 ) {
    glebia[gdzie] = gl;
    long long j=gdzie, skok=0;
    for( long long i=19; i>=0; i-- ) {
        if( dist[j][i] <= tab[gdzie] ) {
            tab[gdzie] -= dist[j][i];
            j = przodkowie[j][i];
        }
    }
    kol[gdzie] = new moj( glebia[j] );
    wy[gdzie] = 1;
    for( pair<long long, long long> & i : drogi[gdzie] ) {
        przodkowie[i.first][0] = gdzie;
        dist[i.first][0] = i.second;
        uzu( i.first );
        DFS( i.first, gl+1, gdzie );
    }
    while( kol[gdzie]->war > gl ) {
        kol[gdzie] = mer( kol[gdzie]->prawy, kol[gdzie]->lewy );
        wy[gdzie]--;
    }
    if( oj!=0 ) {
        wy[oj] += wy[gdzie];
        kol[oj] = mer( kol[oj], kol[gdzie] );
    }
    wy[gdzie]--;
}

int main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );

    long long n;
    cin >> n;
    for( long long i=1; i<=n; i++ ) {
        cin >> tab[i];
    }
    for( long long a, b, i=2; i<=n; i++ ) {
        cin >> a >> b;
        drogi[a].push_back( {i, b} );
    }

    for( long long i=0; i<20; i++ ) {
        przodkowie[1][i] = 1;
    }
    /*moj a;
    moj*ws = &a;
    for( long long i=0; i<100; i++ ) {
        ws = mer( ws, new moj( (i%10)+1 ) );
    }
    while( ws != nullptr ) {
        cout << ws->war << " ";
        ws = mer( ws->lewy, ws->prawy );
    }*/

    DFS();
    for( long long i=1; i<=n; i++ ) {
        cout << wy[i] << " ";
    }
    return 0;
}
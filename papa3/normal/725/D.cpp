#include<bits/stdc++.h>

using namespace std;

vector<pair<long long, long long> > v;

const long long bazaaaa = 1<<19;
long long drz[bazaaaa*2];
long long ile[bazaaaa*2];
long long baza=1;
long long rozwalone;
long long miejsce;
long long wy;

long long znajdz( long long pyt_kon, long long pocz=1, long long kon=baza, long long gdzie=1 ) {
    if( pyt_kon >= kon ) {
        return gdzie;
    }
    long long sr = (pocz+kon)/2;
    if( pyt_kon <= sr ) {
        return znajdz( pyt_kon, pocz, sr, gdzie*2 );
    } else {
        long long co = znajdz( pyt_kon, sr+1, kon, gdzie*2+1 );
        if( drz[gdzie*2] <= drz[co] ) {
            return gdzie*2;
        } else {
            return co;
        }
    }
}

void niszcz( long long gdzie ) {
    if( gdzie>=baza ) {
        drz[gdzie] = numeric_limits<long long>::max();
        ile[gdzie] = 1;
        return;
    }
    if( drz[gdzie*2] <= drz[gdzie*2+1] ) {
        niszcz( gdzie*2 );
    } else {
        niszcz( gdzie*2+1 );
    }
    drz[gdzie] = min( drz[gdzie*2], drz[gdzie*2+1] );
    ile[gdzie] = ile[gdzie*2] + ile[gdzie*2+1];
}

long long czytaj( long long pyt_kon, long long pocz=1, long long kon=baza, long long gdzie=1 ) {
    if( pyt_kon >= kon ) {
        return ile[gdzie];
    }
    long long sr = (pocz+kon)/2;
    if( pyt_kon <= sr ) {
        return czytaj( pyt_kon, pocz, sr, gdzie*2 );
    } else {
        return ile[gdzie*2] + czytaj( pyt_kon, sr+1, kon, gdzie*2+1 );
    }
}
int main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );

    long long n, x;
    cin >> n;
    long long moje;
    cin >> moje >> x;
    for( long long a, b, i=1; i<n; i++ ) {
        cin >> a >> b;
        v.push_back( {-a, b} );
    }
    sort( v.begin(), v.end() );
    while( baza < n ) {
        baza*=2;
    }
    for( long long i=0; i<n-1; i++ ) {
        drz[baza+i] = v[i].second+v[i].first+1;
    }
    for( long long i=n-1; i<baza; i++ ) {
        drz[baza+i] = numeric_limits<long long>::max();
    }
    for( long long i=baza-1; i>=0; i-- ) {
        drz[ i ] = min( drz[i*2], drz[i*2+1] );
    }
    auto it = lower_bound( v.begin(), v.end(), make_pair(-moje, -1ll) );
    wy = it-v.begin()+1;
    long long ile_trza;
    while( moje ) {
        it = lower_bound( v.begin(), v.end(), make_pair(-moje, -1ll) );
        miejsce = it-v.begin()+1;
        if( miejsce == 1 ) {
            break;
        }
        ile_trza = znajdz( miejsce-1 );
        if( drz[ile_trza] > moje ) {
            break;
        }
        moje -= drz[ile_trza];
        niszcz( ile_trza );
        ile_trza/=2;
        while( ile_trza ) {
            drz[ile_trza] = min( drz[ile_trza*2], drz[ile_trza*2+1] );
            ile[ile_trza] = ile[ile_trza*2] + ile[ile_trza*2+1];
            ile_trza/=2;
        }
        it = lower_bound( v.begin(), v.end(), make_pair(-moje, -1ll) );
        miejsce = it-v.begin()+1;
        wy = min( wy, miejsce-czytaj( miejsce-1 ) );
    }
    cout << wy;
    return 0;
}
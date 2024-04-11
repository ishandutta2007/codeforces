#include<bits/stdc++.h>

using namespace std;

#define int long long
#define x first
#define y second
#define ilo( a, b ) ( a.x*b.y-b.x*a.y )

list<pair<int, int> > v;
int n;
pair<int, int> sr;

void usun() {
    for( auto it = v.begin(); it != v.end(); it++ ) {
        for( auto it2 = it; it2 != v.end(); it2++ ) {
            //if( it == it2 ) continue;
            if( (it->x+it2->x)*n == 2*sr.x && (it->y+it2->y)*n == 2*sr.y ) {
                if( it != it2 ) v.erase( it2 );
                it = v.erase( it );
                it--;
                break;
            }
        }
    }
}

pair<int, int> kier;
int odl[2200];
bool spr() {
    int li=0;
    for( pair<int, int> i : v ) {
        i.x*=n;
        i.y*=n;
        odl[li] = ilo( kier, i );
        li++;
    }
    odl[v.size()] = ilo( kier, sr );
    sort( odl, odl+v.size()+1 );
    if( v.size()%2 ) {
        if( odl[(v.size()+1)/2] != ilo( kier, sr ) ) {
            return 0;
        }
        swap( odl[(v.size()+1)/2], odl[v.size()] );
        sort( odl, odl+v.size() );
    }

    if( odl[v.size()/2] != ilo( kier, sr ) ) return 0;
    for( int pocz, kon=pocz=v.size()/2; pocz>0; pocz--, kon++ ) {
        if( odl[pocz]-odl[pocz-1] != odl[kon+1]-odl[kon] ) return 0;
    }
    return 1;
}

set<pair<int, int> > used;

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    cin >> n;
    for( int a, b, i=1; i<=n; i++ ) {
        cin >> a >> b;
        v.push_back( {a*2, b*2} );
        sr.x += a*2;
        sr.y += b*2;
    }

    usun();
    if( v.size() == 0 ) {
        cout << -1;
        return 0;
    }
    if( v.size() == 1 && v.front().x*n == sr.x && v.front().y == sr.y ) {//jesli jest jeden na srodku
        cout << -1;
        return 0;
    }

    int res = 0;
    pair<int, int> pom;
    for( auto i : v ) {
        //if( i == v.front() ) continue;
        pom.x = (v.front().x+i.x)/2*n;
        pom.y = (v.front().y+i.y)/2*n;
        kier.x = pom.x-sr.x;
        kier.y = pom.y-sr.y;
        int nwd = __gcd( kier.x, kier.y );
        kier.x /= nwd;
        kier.y /= nwd;
        if( kier.x < 0 ) {
            kier.x = -kier.x;
            kier.y = -kier.y;
        } else if( kier.x == 0 && kier.y < 0 ) {
            kier.x = -kier.x;
            kier.y = -kier.y;
        }
        if( used.find( kier ) == used.end() ) {
            res += spr();
            used.insert( kier );
        }
    }
    cout << res;

    return 0;
}
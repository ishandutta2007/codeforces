#include<bits/stdc++.h>

using namespace std;

const int baza = 1<<17;

struct moj {
    int drz[baza*2];
    int lit, skok, p;

    moj( int li, int sko, int po ) {
        lit = li;
        skok = sko;
        p = po;
        for( int i=1; i<baza*2; i++ ) drz[i] = 0;
    }

    int czytaj( int pyt_pocz, int pyt_kon, int pocz, int kon, int gdzie  ) {
        if( pyt_kon <= pocz || kon <= pyt_pocz ) { return 0; }
        if( pyt_pocz <= pocz && kon <= pyt_kon ) { return drz[gdzie]; }
        return  czytaj( pyt_pocz, pyt_kon, pocz, (pocz+kon)/2, gdzie*2 )+
                czytaj( pyt_pocz, pyt_kon, (pocz+kon)/2, kon, gdzie*2+1 );
    }

    int cz( int pyt_pocz, int pyt_kon, int gdzie, int co ) {
        if( lit != co ) return 0;
        if( (gdzie-p)%skok != 0 ) return 0;

        return czytaj( pyt_pocz, pyt_kon, 0, baza, 1 );
    }

    void zmien( int gdzie, int co ) {
        if( lit != co ) return;
        if( (gdzie-p)%skok != 0 ) return;

        gdzie += baza;
        drz[gdzie] ^= 1;
        while( gdzie/=2 ) {
            drz[gdzie] = drz[gdzie*2]+drz[gdzie*2+1];
        }
    }

    void zmien22( int gdzie, int co ) {
        if( lit != co ) return;
        if( (gdzie-p)%skok != 0 ) return;

        gdzie += baza;
        drz[gdzie] ^= 1;
    }

    void make() {
        for( int i=baza-1; i>0; i-- ) {
            drz[i] = drz[i*2]+drz[i*2+1];
        }
    }

};

int tab[3000];
pair<int, int> zakres[20];

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    tab['A'] = 0;
    tab['T'] = 1;
    tab['G'] = 2;
    tab['C'] = 3;

    vector<moj> v;
    for( int i=1; i<=10; i++ ) {
        zakres[i].first = v.size();
        for( int j=0; j<i; j++ ) {
            for( int k=0; k<4; k++ ) {
                v.push_back( {k, i, j} );
            }
        }
        zakres[i].second = v.size();
    }

    string s;
    cin >> s;
    for( int i=0; i<s.size(); i++ ) {
        for( auto & j : v ) {
            j.zmien22( i, tab[s[i]] );
        }
    }
    for( auto & j : v ) {
        j.make();
        //cout << j.lit << " " << j.p << " " << j.skok << "    " << j.czytaj( 0, 8, 0, baza, 1 ) << "\n";
    }

    int q;
    cin >> q;
    int a, b, wy;
    char c;
    string slowo;
    while( q-- ) {
        cin >> a;
        if( a==1 ) {
            cin >> a >> c;
            a--;
            for( auto & j : v ) {
                j.zmien( a, tab[s[a]] );
                j.zmien( a, tab[c] );
            }
            s[a] = c;
        } else {
            cin >> a >> b >> slowo;
            a--;
            wy=0;
            for( int i=0; i<slowo.size(); i++ ) {
                for( int j=zakres[slowo.size()].first; j<zakres[slowo.size()].second; j++ ) {
                    wy += v[j].cz( a, b, a+i, tab[slowo[i]] );
                    //cout << wy << " ";
                }
            }
            cout << wy << "\n";
        }
    }

    return 0;
}
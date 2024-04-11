#include<bits/stdc++.h>

using namespace std;

//#define int long long
#define double long double
const long long mod = 1000000007ll;
const long long INF = 1000000000000000000ll;

bitset<7010> pom[100010], ile[100010];
vector<int> dzielniki[7010];

void init() {
    for( int i=1; i<=7000; i++ ) {
        for( int j=1; j<=i; j++ ) {
            if( i%j == 0 ) dzielniki[i].push_back( j );
        }
    }
    for( int i=7000; i>=1; i-- ) {
        pom[i][i] = 1;
        for( int j=i+i; j<=7000; j+=i ) {
            pom[i] ^= pom[j];
        }
    }
}

void wypisz( int x ) {
    for( int i=0; i<=6; i++ ) {
        cout << ile[x][i];
    }
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    init();
    int n, q;
    cin >> n >> q;
    for( int a, x, y, z, i=1; i<=q; i++ ) {
        cin >> a >> x >> y;
        if( a==1 ) {
            //tab[x].reset();
            ile[x].reset();
            //tab[x][y] = 1;
            for( int j : dzielniki[y] ) {
                ile[x][j] = 1;
            }
        } else if( a==2 ) {
            cin >> z;
            //tab[x] = tab[y]^tab[z];
            ile[x] = ile[y]^ile[z];
        } else if( a==3 ) {
            cin >> z;
            ile[x] = ile[y]&ile[z];
            /*tab[x] = ile[y]&ile[z];
            ile[x].reset();
            for( int j=7000; j>=1; j-- ) {
                for( int k=j; k<=7000; k+=j ) {
                    tab[x][j] = tab[x][j]^tab[x][k];
                }
                if( tab[x][j] )
                    for( int q : dzielniki[j] ) {
                        ile[x][q] = ile[x][q]^1;
                    }
            }*/
        } else {
            cout << (ile[x] & pom[y]).count()%2;
        }
        /*
        for( int i=1; i<=n; i++ ) {
            wypisz( i );
        } cout << endl;//*/
    }


    return 0;
}/*

*/
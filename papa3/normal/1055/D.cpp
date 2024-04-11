#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll

string tab[3010], to[3010];

vector<string> v, w;

int gdzie[3010];
int zmiana;

int t[1000000];

bool kmp( string s, int j ) {
    int x = s.size();
    s = "#"+s+"#"+tab[j];
    //cout << s << endl;
    t[0] = -1;
    for( int i=1; i<s.size(); i++ ) {
        int g = t[i-1];
        while( g!= -1 && s[g+1] != s[i] ) {
            g= t[g];
        }
        t[i] = g+1;
        if( i>x && t[i] == x ) {
            if( i-x-2 == gdzie[j]+zmiana ) return true;
            return false;
        }
    }
    return true;
}

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n;
    cin >> n;
    for( int i=1; i<=n; i++ ) {
        cin >> tab[i];
    }
    for( int i=1; i<=n; i++ ) {
        cin >> to[i];
        bool czy=false;
        string s;
        int pocz=-1, kon=0;
        for( int j=0; j<tab[i].size(); j++ ) {
            if( tab[i][j] != to[i][j] ) {
                kon = max( kon, j );
                if( pocz == -1 ) {
                    pocz = j;
                }
            }
        }
        if( pocz != -1 ) {
            gdzie[i] = kon;
            string ss;
            for( int j=pocz; j<=kon; j++ ) {
                s.push_back( tab[i][j] );
                ss.push_back( to[i][j] );
            }
            v.push_back( s );
            w.push_back( ss );
            if( i>1 ) {
                swap( tab[i], tab[1] );
                swap( to[i], to[1] );
                swap( gdzie[i], gdzie[1] );
            }
        } else {
            gdzie[i] = -1;
        }
    }

    for( int i=1; i<v.size(); i++ ) {
        if( v[i] != v[i-1] || w[i] != w[i-1] ) {
            cout << "NO";
            return 0;
        }
    }

    int dl = v[0].size();
    while( 1 ) {
        bool czy=1;
        if( gdzie[1]-dl < 0 ) break;
        for( int i=1; i<=n; i++ ) {
            if( gdzie[i] != -1 ) {
                if( gdzie[i]-dl >= 0 && tab[i][ gdzie[i]-dl ] == tab[1][ gdzie[1]-dl ] ) {

                } else {
                    czy = false;
                }
            }
        }
        if( czy ) dl++;
        else break;
    }
    while( 1 ) {
        bool czy=1;
        if( gdzie[1]+zmiana+1 >= tab[1].size() ) break;
        for( int i=1; i<=n; i++ ) {
            if( gdzie[i] != -1 ) {
                if( gdzie[i]+zmiana+1 < tab[i].size() && tab[i][ gdzie[i]+zmiana+1 ] == tab[1][ gdzie[1]+zmiana+1 ] ) {

                } else {
                    czy = false;
                }
            }
        }
        if( czy ) {
            dl++;
            zmiana++;
        }
        else break;
    }

    v[0] = "";
    w[0] = "";
    for( int i=gdzie[1]+zmiana-dl+1; i<=gdzie[1]+zmiana; i++ ) {
        v[0].push_back( tab[1][i] );
        w[0].push_back( to[1][i] );
    }

    for( int i=1; i<=n; i++ ) {
        if( !kmp( v[0], i ) ) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES\n";
    cout << v[0] << "\n";
    cout << w[0];



    return 0;
}/*

*/
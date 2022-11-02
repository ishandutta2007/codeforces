#include<bits/stdc++.h>

using namespace std;

//#define int long long
//#define double long double
//#define mod 1000000007ll

#define MAX_N 1000010

vector<pair<int, int> > drogi[MAX_N];
vector<int> edges[MAX_N];
int low[MAX_N];
int id[MAX_N];

void dfs( int gdzie, int skad=0, int gl=1 ) {
    low[gdzie] = gl;
    for( pair<int, int> i : drogi[gdzie] ) {
        if( low[i.first] == 0 ) {
            dfs( i.first, i.second, gl+1 );
        }
    }
    for( pair<int, int> i : drogi[gdzie] ) {
        if( i.second != skad ) {
            low[gdzie] = min( low[gdzie], low[i.first] );
        }
    }
}

bool odw[MAX_N];
int li;
int nr[MAX_N];
void podziel( int gdzie, int gl=1, int id=++li ) {
    odw[gdzie] = 1;
    nr[gdzie] = id;
    for( pair<int, int> i : drogi[gdzie] ) {
        if( !odw[i.first] ) {
            if( low[i.first] > gl ) {
                podziel( i.first, gl+1, ++li );
            } else {
                podziel( i.first, gl+1, id );
            }
        }
    }
}

void make( int n ) {
    for( int i=1; i<=n; i++ ) {
        for( pair<int, int> j : drogi[i] ) {
            if( nr[i] != nr[j.first] ) {
                edges[ nr[i] ].push_back( nr[j.first] );
                //cout << " " << nr[i] << " " << nr[j.first] << '\n';
            }
        }
    }
}

vector<int> korzenie;
pair<int, int> zakres[MAX_N];
int przodkowie[MAX_N][20];

void dfs2( int gdzie, int skad=0 ) {
    zakres[gdzie].first = ++li;
    if( skad == 0 ) {
        for( int i=0; i<20; i++ ) {
            przodkowie[gdzie][i] = gdzie;
        }
    } else {
        przodkowie[gdzie][0] = skad;
        for( int i=1; i<20; i++ ) {
            przodkowie[gdzie][i] = przodkowie[ przodkowie[gdzie][i-1] ][ i-1 ];
        }
    }
    for( int i : edges[gdzie] ) {
        if( i != skad ) {
            dfs2( i, gdzie );
        }
    }
    zakres[gdzie].second = ++li;
}

void Debug() {
    for( int i=0; i<1000; i++ ) {
        for( pair<int, int> j : drogi[i] ) {
            cout << "  " << i << " " << j.first << " " << j.second << endl;
        }
    }
}

int R;
int N;

int rotate(int element) {
   element=(element+R)%N;

   if (element==0) {
       element=N;
   }

   return element;
}

int nr_pytania;

int ile=0;
int cus;
bool used[MAX_N];
int n, m;
vector<int> x;
vector<int> s;

bool cmp( int a, int b ) {
    return zakres[a].first < zakres[b].first;
}

inline bool czy_przodek( int niby_syn, int niby_ojciec ) {
    return zakres[niby_ojciec].first <= zakres[niby_syn].first && zakres[niby_syn].second <= zakres[niby_ojciec].second;
}

int lca( int a, int b ) {
    if( przodkowie[a][19] != przodkowie[b][19] ) return a;
    if( czy_przodek( b, a ) ) return a;
    for( int i=19; i>=0; i-- ) {
        if( !czy_przodek( b, przodkowie[a][i] ) ) {
            a = przodkowie[a][i];
        }
    }
    return przodkowie[a][0];
}

int s_id;

void zrob_kra() {
    int gdzie=s_id;
    s_id++;
    while( s_id != s.size() && czy_przodek( s[s_id], s[gdzie] ) ) {
        m++;
        drogi[ s[gdzie] ].push_back( {s[s_id], m} );
        drogi[ s[s_id] ].push_back( {s[gdzie], m} );
        zrob_kra();
    }
}

struct algo {
    algo() {
        cin >> n >> m;
        x.clear();
        s.clear();
        for( int a, i=1; i<=n; i++ ) {
            cin >> a;
            ile++;
            a = rotate( a );
            //cout << " " << a << endl;
            a = id[a];
            x.push_back( a );
            if( !used[a] ) {
                s.push_back( a );
                used[a] = 1;
            }
        }
        for( int a, b, i=1; i<=m; i++ ) {
            cin >> a >> b;
            ile+=2;
            a = rotate( a );
            b = rotate( b );
            //cout << " " << a << " " << b << endl;
            a = id[a];
            if( !used[a] ) {
                s.push_back( a );
                used[a] = 1;
            }

            b = id[b];
            if( !used[b] ) {
                s.push_back( b );
                used[b] = 1;
            }
            drogi[a].push_back( {b, i} );
            drogi[b].push_back( {a, i} );
        }
        //cout << "wczyt" << endl;

        sort( s.begin(), s.end(), cmp );
        int u;
        int sz = s.size();
        for( int i=1; i<sz; i++ ) {
            u = lca( s[i-1], s[i] );
            if( !used[u] ) {
                s.push_back( u );
                used[u] = 1;
            }
        }
        sort( s.begin(), s.end(), cmp );
        s_id=0;
        while( s_id<s.size() ) {
            zrob_kra();
        }
        //Debug();
        for( int i : s ) {
            if( low[i] == 0 ) {
                dfs( i );
                podziel( i );
            }
        }
        if( x.size() == 0 ) {
            cout << "x.size() == 0...\n";
            return;
        }
        int co = nr[ *x.begin() ];
        int odp=true;
        for( int i : x ) {
            if( co != nr[i] ) {
                odp = false;
                break;
            }
        }
        nr_pytania++;
        if( odp ) {
            cout << "YES\n";
            R=(R+nr_pytania)%N;
        } else {
            cout << "NO\n";
        }
        //cout << endl;

        for( int i : s ) {
            drogi[i].clear();
            nr[i] = 0;
            low[i] = 0;
            odw[i] = 0;
            used[i] = 0;
        }
    }
};

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n, m, q;
    cin >> n >> m >> q;
    N = n;



    for( int a, b, i=1; i<=m; i++ ) {
        cin >> a >> b;
        if( i==1 ) cus = a;
        drogi[a].push_back( {b, i} );
        drogi[b].push_back( {a, i} );
    }

    for( int i=1; i<=n; i++ ) {
        if( low[i] == 0 ) {
            dfs( i );
            podziel( i );
            korzenie.push_back( i );
        }
    }
    make( n );
    li = 0;
    for( int i : korzenie ) {
        dfs2( nr[i] );
    }
    for( int i=1; i<=n; i++ ) {
        drogi[i].clear();
        low[i] = 0;
        id[i] = nr[i];
        nr[i] = 0;
        odw[i] = 0;
    }

    //if( cus == 18634 ) return 0;
    while( q-- ) {
        algo p;
    }

    return 0;
}
/*
-1073741819
-1073741819
-1073741819

7 6 1
1 2
1 3
2 4
2 5
3 6
3 7

5 2
5 1 2 6 7
5 6
1 2





6 7
1 2
1 3
2 3
3 4
4 5
4 6
5 6

*/
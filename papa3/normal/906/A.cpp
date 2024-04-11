#include<bits/stdc++.h>

using namespace std;

#define int long long

int tab[1000];
int v[1000];
bool czy[1000];

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );


    int n;
    cin >> n;
    char a;
    string s;
    int res=0;
    int ile1=0;
    for( int i=1; i<=n; i++ ) {
        cin >> a >> s;
        if( a== '.' ) {
            for( char j : s ) {
                if( tab[j] == 1 )
                    ile1--;
                tab[j] = 2;
            }
        } else if( a== '!' ) {
            if( ile1 == 1 ) res++;
            for( char j : s ) {
                if( tab[j] == 0 ) {
                    ile1++;
                    tab[j] = 1;
                }
                czy[j] = 1;
            }
            for( int j='a'; j<='z'; j++ ) {
                if( czy[j] && tab[j] == 1 ) tab[j] = 1;
                else {
                    if( tab[j] == 1 ) ile1--;
                    tab[j] = 2;
                }
                czy[j] = 0;
            }
        } else {
            if( ile1==1 )
                v[ s[0] ]++;
            if( tab[ s[0] ] == 1 ) {
                ile1--;
                tab[ s[0] ] = 2;
            }
            tab[ s[0] ] = 2;
        }

        int x=0;
        for( int j='a'; j<='z'; j++ ) {
            if( tab[j] == 2 ) x++;
        }
        if( x==25 ) {
            for( int j='a'; j<='z'; j++ ) {
                if( tab[j] != 2 ) tab[j] = 1;
            }
            ile1 = 1;
        }
    }

    for( int i='a'; i<='z'; i++ ) {
        res+=v[i];
    }
    cout << res-v[ s[0] ];

    return 0;
}
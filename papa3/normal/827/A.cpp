#include<bits/stdc++.h>

using namespace std;

#define int long long

char tab[3000010];
int ojciec[3000010];
int f( int gdzie ) {
    if( ojciec[gdzie] == gdzie ) {
        return gdzie;
    }
    return ojciec[gdzie] = f( ojciec[gdzie] );
}

void u( int a, int b ) {
    ojciec[ f(a) ] = f(b);
}

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    for( int i=1; i<=3000000; i++ ) {
        ojciec[i] = i;
    }

    int kon=0;
    int n;
    cin >> n;
    for( int i=1; i<=n; i++ ) {
        string a;
        int x;
        cin >> a;
        cin >> x;
        for( int b, j=1; j<=x; j++ ) {
            cin >> b;
            int gdzie = b;
            do {
                tab[gdzie] = a[gdzie-b];
                kon = max( kon, gdzie );
                u( gdzie, gdzie+1 );
                gdzie = f( gdzie );
            } while( gdzie < b+a.size() );
        }
    }
    for( int i=1; i<=kon; i++ ) {
        if( tab[i] == 0 ) {
            cout << "a";
        } else {
            cout << tab[i];
        }
    }

    return 0;
}
#include<bits/stdc++.h>

using namespace std;

int tab[30];
int wziete[30];
int pojawione[30];
int suma[30];
int litery[100010];
bool czy[100010];
bool czydobrze;

int main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );

    int n;
    string a;
    cin >> n;
    cin >> a;
    for( int i=1; i<=a.size(); i++ ) {
        litery[i] = a[i-1] - 'a';
        suma[ litery[i] ]++;
    }
    tab[ 0 ]++; // dodaje sztuczne 'a'
    for( int i=1; i<n; i++ ) {
        //tab[ litery[i] ]++;
        pojawione[ litery[i] ] = i;
    }
    for( int i=n; i<=a.size(); i++ ) {
        //tab[ litery[i] ]++;
        pojawione[ litery[i] ] = i;
        //tab[ litery[i-n] ]--;
        if( czy[ i-n ] == 1 ) {
            czydobrze=0;
        }
        if( czydobrze == 0 ) {
            int x = 0;
            while( pojawione[ x ] < i-n+1 ) {
                x++;
            }
            czy[ pojawione[x] ] = 1;
            wziete[ x ]++;
            czydobrze = 1;
        }
    }

    int m=0;
    for( int i=0; i<28; i++ ) {
        if( wziete[i] ) {
            m = i;
        }
    }
    char c;
    for( int i=0; i<m; i++ ) {
        c = i+'a';
        for( int j=0; j<suma[i]; j++ ) {
            cout << c;
        }
    }
    c = m+'a';
    for( int i=0; i<wziete[m]; i++ ) {
        cout << c;
    }

    return 0;
}
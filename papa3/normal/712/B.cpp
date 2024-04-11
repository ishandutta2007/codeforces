#include<iostream>
#include<cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );
    string a;
    cin >> a;
    int pion=0, poziom=0;
    for( char & x : a ) {
        if( x == 'D' ) {
            pion--;
        } else if( x == 'U' ) {
            pion++;
        } else if( x == 'L' ) {
            poziom--;
        } else {
            poziom++;
        }
    }
    if( a.size()%2==1 ) {
        cout << -1;
    } else {
        cout << (abs(pion)+abs(poziom))/2;
    }
    return 0;
}
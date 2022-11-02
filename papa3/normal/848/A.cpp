#include<bits/stdc++.h>

using namespace std;

#define int long long


int32_t main() {
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );

    char c='a';
    int n;
    cin >> n;
    int li=0;
    if( n==0 ) {
        cout << c;
        return 0;
    }
    while( n ) {
        int x=2;
        while( x*(x+1) <= n*2 ) {
            x++;
        }
        for( int i=0; i<x; i++ ) {
            cout << c;
            li++;
        }
        c++;
        n-=(x*(x-1))/2;
    }
    //cout << li;

	return 0;
}
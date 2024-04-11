#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <string>
using namespace std;

typedef long long llint;
const int N = 100005;

#define pb push_back

int n;
int P[N];
llint desno[N];
llint levo[N];
int lfake[N];
int rfake[N];

void load( ) {
    scanf( "%d", &n );
    for( int i = 0; i < n; i++ ) scanf( "%d", &P[i] );
}

void solve( ) {
    llint sol = 0;
    llint last = P[n-1];
    rfake[n-1] = last;
    for( int i = n - 2; i >= 0; i-- ) {
            if(P[i] > last ) last = P[i];
            else sol += last - P[i] + 1, last++;
            rfake[i] = last;
            desno[i] = sol;
    }

    sol = 0;
    last = P[0];
    lfake[0] = P[0];
    for( int i = 1; i < n; i++ ) {
            if( P[i] > last ) last = P[i];
            else sol += last - P[i] + 1, last++;
            levo[i] = sol;
            lfake[i] = last;
    }

  //  cout << "da" << endl;
    llint mini = min( levo[n-1], desno[0] );

    for( int i = 1; i < n - 1; i++ ) {
            llint ans = levo[i-1] + desno[i+1];
            llint maks = max(lfake[i-1], rfake[i+1]);
            if( maks >= P[i] ) ans += maks - P[i] + 1;
            mini = min( mini, ans );
    }

    cout << mini << endl;
}


int main( void ) {
    load( );
    solve( );
    return 0;
}
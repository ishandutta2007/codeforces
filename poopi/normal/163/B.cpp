#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <cstring>
#include <memory.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

//#define pii pair< int, int >
struct pii {
    int first, second, id;
    pii( int _first = 0, int _second = 0, int _id = 0 ) {
        first = _first, second = _second, id = _id;
    }
    bool operator < ( const pii & p ) const {
        if( first != p.first )  return first < p.first;
        return second < p.second;
    }
};
#define int64 long long

int64 n, k, h;
pii arr[200000];
int ans[200000], tmp[200000];

bool solve( long double mul, double EPS = 0. ) {
    int ptr = k;
    for( int i = n - 1; i >= 0; i-- ) {
        if( mul * arr[i].second + EPS >= ptr * h ) {
            tmp[--ptr] = arr[i].id;
        }
        if( ptr == 0 )  {
            for( int i = 0; i < k; i++ )    ans[i] = tmp[i];
            return true;
        }
    }
    return false;
}

int main() {
    cin >> n >> k >> h;
    for( int i = 0; i < n; i++ ){
        scanf( "%d", &arr[i].first );
    }
    for( int i = 0; i < n; i++ ){
        scanf( "%d", &arr[i].second );
        arr[i].id = i + 1;
    }
    sort( arr, arr + n );
    long double l = 0, r = 1e10;
    for( int i = 0; i < 100; i++ ) {
        long double mid = (l + r) / 2;
        if( solve( mid ) ) 
            r = mid;
        else
            l = mid;
    }
    for( int i = 0; i < k; i++ ) {
        if( i ) printf( " " );
        printf( "%d", ans[i] );
    }
    printf( "\n" );
    return 0;
}
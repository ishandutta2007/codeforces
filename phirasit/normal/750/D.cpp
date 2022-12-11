#include <iostream>
#include <set>

using namespace std;

const int N = 1000;

const int DI[8][2] = { { 0, 1 }, { 1, 1 }, { 1, 0 }, { 1, -1 }, { 0, -1 }, { -1, -1 }, { -1, 0 }, { -1, 1 } };

typedef pair< int, int > pii;
typedef pair< pii, int > pi3;
set< pi3 > data;
set< pii > ans;

int n;

int main( void ) {

    cin >> n;
    data.insert( { { 0, -1 }, 0  } );
    for ( int i = 0 ; i < n ; ++i ) {
        int t;
        cin >> t;

        set< pi3 > nw_data;
        for ( pi3 p : data ) {
            int x = p.first.first, y = p.first.second, dir = p.second;
            for ( int j = 1 ; j <= t ; ++j ) {
                ans.insert( { x + DI[ dir ][0] * j, y + DI[ dir ][1] * j } );
            }

            int nwx = x + t * DI[ dir ][ 0 ], nwy = y + t * DI[ dir ][ 1 ];
            nw_data.insert( { { nwx, nwy }, ( dir + 1 ) % 8 } );
            nw_data.insert( { { nwx, nwy }, ( dir + 7 ) % 8 } );
        }

        data = nw_data;
    }
    cout << ans.size() << endl;
}
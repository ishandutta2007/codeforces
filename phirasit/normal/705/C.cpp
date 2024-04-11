#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int N = 3e5 + 10;

queue< int > noti;
vector< int > notix[ N ];
bool rem[ N ];
int n, q;

int main( void ) {

    cin.sync_with_stdio( false );
    cin.tie( 0 );

    cin >> n >> q;

    int ans = 0;
    for ( int i = 0, cnt = 1 ; i < q ; ++i ) {

        int type;
        cin >> type;

        if ( type == 1 ) {
            int x;
            cin >> x;
            notix[ x ].emplace_back( cnt );
            noti.emplace( cnt );
            rem[ cnt ] = false;
            ++cnt;
            ++ans;
        } else if ( type == 2 ) {
            int x;
            cin >> x;
            for ( int id : notix[ x ] ) {
                if ( not rem[ id ] ) {
                    rem[ id ] = true;
                    --ans;
                }
            }
            notix[ x ].clear();
        } else if ( type == 3 ) {
            int t;
            cin >> t;
            while ( ( not noti.empty() ) and noti.front() <= t ) {
                int id = noti.front();
                noti.pop();
                if ( not rem[ id ] ) {
                    rem[ id ] = true;
                    --ans;
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
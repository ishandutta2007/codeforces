#include <iostream>
#include <vector>

using namespace std;

vector< long long > data1, data2;
vector< long long > val1, val2;

string str;
int n;

int main( void ) {

    cin.sync_with_stdio( false );
    cin.tie( 0 );

    cin >> n >> str;

    str = "#" + str;

    for ( int i = n+1 ; i >= 1 ; --i ) {
        if ( i == n+1 or str[i] == 'D' ) {
            data2.emplace_back( i + ( i == n+1 ? 0 : data2.back() ) );
            val2.emplace_back( i );
        }
    }

    data1.emplace_back( 0 );
    val1.emplace_back( 0 );

    for ( int i = 1 ; i <= n ; ++i ) {
        long long ans = 0ll;
        if ( str[i] == 'U' ) {

            data1.emplace_back( i + data1.back() );
            val1.emplace_back( i );

            if ( data1.size() <= data2.size() ) {
                ans -= 2 * data1.back() - val1.rbegin()[ 0 ] - val1[ 0 ];
                ans += 2 * ( data2.back() - data2.rbegin()[ data1.size()-1 ] );
            } else {
                ans -= 2 * ( data1.back() - data1.rbegin()[ data2.size() ] ) - val1.back();
                ans += 2 * data2.back() - val2[ 0 ];
            }

        } else if ( str[i] == 'D' ) {

            if ( data2.size() <= data1.size() ) {
                ans += 2 * data2.back() - val2.rbegin()[ 0 ] - val2[ 0 ];
                ans -= 2 * ( data1.back() - data1.rbegin()[ data2.size()-1 ] );
            } else {
                ans += 2 * ( data2.back() - data2.rbegin()[ data1.size() ] ) - val2.back();
                ans -= 2 * data1.back() - val1[ 0 ];
            }

            data2.pop_back();
            val2.pop_back();
        }

        cout << ans << " ";
    }

    cout << endl;

    return 0;
}
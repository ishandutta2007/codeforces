#include <iostream>

using namespace std;

const int value [] = { 4, 5, 6, 3, 2, 1 };

int main( void ) {
    string str;
    cin >> str;

    long long row = 0;
    for ( int i = 0 ; i+1 < str.length() ; ++i ) {
        row = 10 * row + str[i] - '0';
    }

    int seat = ( str.back() - 'a' );

    long long ans = 16 * ( ( row - 1 ) / 4 ) + ( row - 1 ) % 2 * 7 + value[ seat ];

    cout << ans << endl;

    return 0;
}
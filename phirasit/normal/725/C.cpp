#include <iostream>
#include <algorithm>

char output[ 2 ][ 13 ];

int main( void ) {

    std::string str;
	std::cin >> str;

    const int len = str.length();
    auto z = [ &str ] ( void ) -> char {
        for ( char i = 'A' ; i <= 'Z' ; ++i ) {
            if ( std::count( str.begin(), str.end(), i ) == 2 )
            return i;
        }
    }();

    for ( int r = 0 ; r < 2 ; ++r ) {
        for ( int c = 0 ; c < 13 ; ++c ) {
            output[ r ][ c ] = '.';
        }
    }
    int id1 = -1, id2 = -1;
    for ( int i = 0 ; i < len ; ++i ) {
        if ( str[i] == z ) {
            ( id1 == -1 ? id1 : id2 ) = i;
        }
    }

    if ( id1 + 1 == id2 ) {
        std::cout << "Impossible" << std::endl;
        return 0;
    }

    int x = 12 - ( id2 - id1 - 1 ) / 2;
    output[ 0 ][ x ] = z;
    for ( int r = 0, c = x + 1, i = id1+1 ; i < id2 ; ++i ) {
        if ( c > 12 ) {
            r = 1, c = 12;
        }
        output[ r ][ c ] = str[ i ];
        c += ( r == 0 ? 1 : -1 );
    }

    for ( int i = ( id1 + len - 1 ) % len, r = 0, c = x - 1 ; i != id2 ; i = ( i + len - 1 ) % len ) {
        if ( c < 0 ) {
            r = 1, c = 0;
        }
        output[ r ][ c ] = str[ i ];
        c += ( r == 0 ? -1 : 1 );
    }

    for ( int r = 0 ; r < 2 ; ++r ) {
        for ( int c = 0 ; c < 13 ; ++c ) {
            std::cout << output[ r ][ c ];
        }
        std::cout << std::endl;
    }

    return 0;
}
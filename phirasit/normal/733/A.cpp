#include <iostream>

using namespace std;

bool vowel( char ch ) {
    return
        ch == 'A' or
        ch == 'E' or
        ch == 'I' or
        ch == 'O' or
        ch == 'U' or
        ch == 'Y';
}
int main( void ) {

    string str;
	cin >> str;

    int last = -1;
    int ans = 0;
    for ( int i = 0 ; i < str.length() ; ++i ) {
        if( vowel( str[i] ) ) {
            ans = max( ans, i - last );
            last = i;
        }
    }

    ans = max( ans, (int) str.length() - last );

    cout << ans << endl;

    return 0;
}
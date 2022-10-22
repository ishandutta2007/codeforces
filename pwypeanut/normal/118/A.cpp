#include <iostream>
#include <cctype>
using namespace std;

int main() {
    string s;
    cin >> s;
    for ( int i = 0; i < s.length(); i++ ) {
        s[i] = tolower(s[i]);
    }
    string r;
    for ( int i = 0; i < s.length(); i++ ) {
        if ( s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'y' ) {
             continue;
        }
        else {
             r = r + '.' + s[i];
        }
    }
    cout << r << endl;
    return 0;
}
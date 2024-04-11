#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );

    int n;
    string s;
    cin >> n >> s;
    int wy=0;
    int i=0;
    while( s[i] == '<' && i<s.size() ) {
        wy++;
        i++;
    }
    i = s.size()-1;
    while( s[i] == '>' && i<s.size() ) {
        wy++;
        i--;
    }
    cout << wy;
    return 0;
}
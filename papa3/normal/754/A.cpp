#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );

    int n, sum=0;
    cin >> n;
    vector<int> tab;
    for( int a, i=0; i<n; i++ ) {
        cin >> a;
        tab.push_back( a );
        sum+=a;
    }
    if( sum != 0 ) {
        cout << "YES\n1\n1 " << n;
        return 0;
    } else {
        for( int i=0; i<n; i++ ) {
            sum += tab[i];
            if( sum!=0 ) {
                cout << "YES\n2\n";
                cout << 1 << " " << i+1 << "\n";
                cout << i+2 << " " << n;
                return 0;
            }
        }
    }
    cout << "NO";

    return 0;
}
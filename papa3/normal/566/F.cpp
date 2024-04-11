#include<bits/stdc++.h>

using namespace std;

vector<int> liczby;
int wy[1000010];

int main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );
    int n, mm=1;
    cin >> n;
    for( int a, i=0; i<n; i++ ) {
        cin >> a;
        liczby.push_back( a );
        wy[a]++;
    }
    sort( liczby.begin(), liczby.end() );
    for( int i : liczby ) {
        for( int j=i+i; j<1000005; j+=i ) {
            if( wy[j] && wy[j] < wy[i]+1 ) {
                wy[j] = wy[i]+1;
                mm = max( mm, wy[j] );
            }
        }
    }
    cout << mm;
    return 0;
}
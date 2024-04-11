#include<bits/stdc++.h>

using namespace std;

pair<int, int> tab[1000000];
int wy[1000000];
int jeden=1, dwa=2;

int main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );

    int n, a, b;
    cin >> n >> a >> b;
    if( a > b ) {
        swap( a, b );
        swap( jeden, dwa );
    }
    for( int i=1; i<=n; i++ ) {
        cin >> tab[i].first;
        tab[i].second = i;
    }
    sort( tab+1, tab+n+1 );

    int x;
    for( int i=1; i<=n; i++ ) {
        if( wy[ tab[i].second ] != 0 ) {
            continue;
        }
        x = b-tab[i].first;
        auto it = lower_bound( tab+1, tab+n+1, make_pair(x, 0)  );
        if( it!=tab+n+1 && (*it).first == x && wy[(*it).second] == 0 ) {
            wy[(*it).second] = dwa;
            wy[tab[i].second] = dwa;
        } else {
            x = a-tab[i].first;
            it = lower_bound( tab+1, tab+n+1, make_pair(x, 0) );
            if( it!=tab+n+1 && (*it).first == x && wy[(*it).second] == 0 ) {
                wy[(*it).second] = jeden;
                wy[tab[i].second] = jeden;
            } else {
                cout << "NO";
                return 0;
            }
        }
    }

    cout << "YES\n";
    for( int i=1; i<=n; i++ ) {
        cout << wy[i]-1 << " ";
    }
    return 0;
}
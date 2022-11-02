#include <bits/stdc++.h>

using namespace std;

pair<int, int> tab[100010];
int n, m;
bool czy=false;

bool algo() {
    vector<int> v;
    for( int i=1; i<=n; i++ ) {
        v.push_back( i );
    }
    random_shuffle( v.begin(), v.end() );
    for( int i=0; i<m; i++ ) {
        if( tab[v[i]].first == v[(i+1)%n] ) return false;
        if( tab[v[i]].second == v[(i+1)%n] ) return false;
    }
    for( int i=0; i<m; i++ ) {
        cout << v[i] << " " << v[(i+1)%n] << '\n';
    }
    return true;
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for( int a, b, i=1; i<=m; i++ ) {
        cin >> a >> b;
        if( tab[a].first == 0 ) {
            tab[a].first = b;
        } else {
            tab[a].second = b;
        }
        if( tab[b].first == 0 ) {
            tab[b].first = a;
        } else {
            tab[b].second = a;
        }
	}

	for( int i=1; i<=500; i++ ) {
        if( algo() ) return 0;
	}
	cout << -1;

	return 0;
}
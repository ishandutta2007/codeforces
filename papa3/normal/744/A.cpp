#include<bits/stdc++.h>

using namespace std;

vector<int> drogi[1010];
bool czy[1010];
vector<int> wy;
bool odw[1010];

int DFS( int gdzie ) {
    odw[gdzie] = true;
    int a=0;
    for( int i : drogi[gdzie] ) {
        if( !odw[i] ) {
            a+=DFS( i );
        }
    }
    return a+1;
}

int main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );

    long long n, m, k;
    cin >> n >> m >> k;
    for( int a, i=0; i<k; i++ ) {
        cin >> a;
        czy[a] = true;
    }
    for( int a, b, i=0; i<m; i++ ) {
        cin >> a >> b;
        drogi[a].push_back(b);
        drogi[b].push_back(a);
    }
    int x=0;
    for( int i=1; i<=n; i++ ) {
        if( czy[i] ) {
            wy.push_back( DFS(i) );
            x+=wy[wy.size()-1];
        }
    }
    sort( wy.begin(), wy.end() );
    wy[wy.size()-1] += n-x;
    long long res=0;
    for( int i : wy ) {
        res += i*(i-1)/2;
    }
    cout << res-m;

    return 0;
}
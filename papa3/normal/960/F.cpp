#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000

set<pair<int, int> > s[1000010];

void Debug( int gdzie ) {
    cout << " " ;
    for( auto i : s[gdzie] ) {
        cout << i.first << "," << i.second << " ";
    }
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n, m;
    cin >> n >> m;
    int res=0;
    for( int a, b, c, i=1; i<=m; i++ ) {
        cin >> a >> b >> c;
        int ile = 1;
        if( s[a].size() ) {
            auto it = s[a].lower_bound( {c, 0} );
            if( it != s[a].begin() ) {
                it--;
                ile = it->second+1;
            }
        }
        res = max( res, ile );
        auto it = s[b].upper_bound( {c, m+10} );
        if( s[b].size() && it !=s[b].begin() && (--it)->second >= ile ) continue;
        it = s[b].insert( {c, ile} ).first;
        it++;
        auto pom = it;
        while( it != s[b].end() && it->second<=ile ) {
            pom = it;
            pom++;
            s[b].erase( it );
            it = pom;
        }
        //Debug( 4 );
    }
    cout << res;

    return 0;
}
/*
5 5
1 3 2
3 2 3
5 4 10
3 4 5
4 5 8

5
3 14
2 5 -3
3 14
2 3 1
3 14
*/
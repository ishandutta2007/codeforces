#include<bits/stdc++.h>

using namespace std;

#define int long long

struct moj {
    int x, y, id, kier;
    bool operator < ( const moj & other ) const {
        return y < other.y;
    }
};

struct coss {
    int x, y;
    bool operator < ( const coss & other ) const {
        if( x == other.x ) {
            return y < other.y;
        }
        return x > other.x;
    }
};

set<moj> asdf[2000010];
set<moj> * s = &asdf[1000005];
pair<int, int> res[100010];

int32_t main() {
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );

    int n, www, h;
    cin >> n >> www >> h;
    for( int x, y, a, b, c, i=1; i<=n; i++ ) {
        cin >> a >> b >> c;
        if( a==1 ) {
            x = b;
            y = -c;
        } else {
            x = -c;
            y = b;
        }
        s[x+y].insert( {x, y, i, a} );
    }

    for( int w = -400000; w<=400000; w++ ) {
        vector<coss> v;
        for( auto & i : s[w] ) {
            if( i.kier == 1 ) {
                v.push_back( {i.x, h} );
            } else {
                v.push_back( {www, i.y} );
            }
            //cout << v.rbegin()->x << ' ' << v.rbegin()->y << "\n";
        }
        sort( v.begin(), v.end() );
        int j=0;
        for( auto & i : s[w] ) {
            res[i.id] = {v[j].x, v[j].y};
            j++;
        }
    }
    //cout << '\n';
    for( int i=1; i<=n; i++ ) {
        cout << res[i].first << ' ' << res[i].second << "\n";
    }

	return 0;
}
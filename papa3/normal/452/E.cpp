#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll

int res[1000010];

struct suffix_automaton {
    vector<map<char, int> > edges;
    vector<int> link;
    vector<int> length;
    int last;
    int ll[3];
    vector<int> ways[3];

    suffix_automaton( string s ) {
        edges.push_back( {} );
        link.push_back( -1 );
        length.push_back( 0 );
        last = 0;

        for( int p, q, r, qq, i=0; i<(int)s.size(); i++ ) {
            edges.push_back( {} );
            link.push_back( 0 );
            length.push_back( i+1 );
            r = edges.size()-1;

            p = last;
            while( p>=0 && edges[p].find( s[i] ) == edges[p].end() ) {
                edges[p][s[i]] = r;
                p = link[p];
            }
            if( p>=0 ) {
                q = edges[p][s[i]];
                if( length[q] == length[p]+1 ) {
                    link[r] = q;
                } else {
                    edges.push_back( edges[q] );
                    link.push_back( link[q] );
                    length.push_back( length[p]+1 );
                    qq = edges.size()-1;

                    while( p>=0 && edges[p][s[i]] == q ) {
                        edges[p][s[i]] = qq;
                        p = link[p];
                    }
                    link[q] = qq;
                    link[r] = qq;
                }
            }
            last = r;
            if( '0' <= s[i] && s[i] <= '2' ) {
                ll[ s[i]-'0' ] = last;
            }
        }

        for( int x, i=0; i<3; i++ ) {
            ways[i].resize( edges.size() );
            x = ll[i];
            while( x>0 ) {
                ways[i][x] = 1;
                x = link[x];
            }
        }

        for( int ile, i=0; i<(int)edges.size(); i++ ) {
            if( ways[2][i] == 0 ) {
                dfs( i );
            }
            if( i!=0 ) {
                ile = ways[0][i]*(ways[1][i]-ways[0][i])*(ways[2][i]-ways[1][i])%mod;
                res[ length[link[i]]+1 ] = (res[ length[link[i]]+1 ] + ile)%mod;
                res[ length[i]+1 ] = (res[ length[i]+1 ]+mod-ile)%mod;
                //cout << length[link[i]]+1 << " " << length[i] << " " << ile << "\n";
            }
        }
    }

    void dfs( int gdzie ) {
        for( pair<char, int> i : edges[gdzie] ) {
            if( ways[2][i.second] == 0 ) {
                dfs( i.second );
            }
            for( int j=0; j<3; j++ ) {
                ways[j][gdzie] += ways[j][i.second];
            }
        }
    }

    void f( string s ) {
        int where = 0;
        for( char c : s ) {
            where = edges[where][c];
        }
        cout << where << endl;
    }
};

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    string a, b, c;
    cin >> a >> b >> c;
    string s = a+'0'+b+'1'+c+'2';

    suffix_automaton p( s );
    for( int x=0, i=1; i<=min(a.size(), min(b.size(), c.size())); i++ ) {
        x = (x+res[i])%mod;
        cout << x << " ";
    }

    return 0;
}
/*

*/
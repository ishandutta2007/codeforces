#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define INF 1000000000000000000ll
#define mod 1000000007

int ways[1000010];
int dp[1000010];
bool kon[1000010];

struct suffix_automat {
    vector<map<char, int> > edges;
    vector<int> link;
    vector<int> length;
    int last;

    suffix_automat( string s ) {
        edges.push_back( {} );
        link.push_back( -1 );
        length.push_back( 0 );
        last = 0;
        for( int p, q, qq, r, i=0; i<s.size(); i++ ) {
            edges.push_back( {} );
            link.push_back( 0 );
            length.push_back( i+1 );
            r = edges.size()-1;
            p = last;
            while( p != -1 && edges[p].find( s[i] ) == edges[p].end() ) {
                edges[p][ s[i] ] = r;
                p = link[p];
            }
            if( p != -1 ) {
                q = edges[p][ s[i] ];
                edges.push_back( edges[q] );
                link.push_back( link[q] );
                length.push_back( length[p]+1 );
                qq = edges.size()-1;

                link[r] = qq;
                link[q] = qq;
                while( p!=-1 && edges[p][s[i]] == q ) {
                    edges[p][s[i]] = qq;
                    p = link[p];
                }
            }
            last = r;
        }
        make();
    }

    void make() {
        int a = last;
        while( a!=-1 ) {
            kon[a] = true;
            a = link[a];
        }
        dfs();
    }

    void dfs( int gdzie=0 ) {
        if( kon[gdzie] ) ways[gdzie] = 1;
        for( pair<char, int> i : edges[gdzie] ) {
            if( ways[i.second] == 0 ) {
                dfs( i.second );
            }
            ways[gdzie] += ways[i.second];
            dp[gdzie] += dp[i.second];
        }
        dp[gdzie] += ways[gdzie];
    }
};

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    string s;
    int k;
    cin >> s >> k;
    suffix_automat p( s );
    k+=ways[0];
    int where = 0;
    string res = "";
    while( k ) {
        bool czy=false;
        k-=ways[where];
        if( k<=0 ) break;
        for( pair<char, int> i : p.edges[where] ) {
            if( dp[i.second] >= k ) {
                res.push_back( i.first );
                where = i.second;
                czy = true;
                break;
            }
            k -= dp[i.second];
        }
        if( !czy ) {
            cout << "No such line.";
            return 0;
        }
    }
    cout << res;

    /*string s;
    int n;
    cin >> s >> n;
    suffix_automat x( s );
    string res="";
    int gdzie=0;
    n+=dp[0];
    while( n ) {
        n -= dp[gdzie];
        if( n<=0 ) {
            cout << res;
            return 0;
        }
        bool czy=0;
        for( pair<char, int> i : x.edges[gdzie] ) {
            n -= dp[i.second];
            if( n<=0 ) {
                n += dp[i.second];
                res.push_back( i.first );
                gdzie = i.second;
                czy = 1;
                break;
            }
        }
        if( !czy ) {
            cout << "No such line.";
            return 0;
        }
    }*/

    return 0;
}
/*

*/
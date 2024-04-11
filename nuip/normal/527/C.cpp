// Standard I/O
#include <iostream>
#include <sstream>
#include <cstdio>
// Standard Library
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
// Template Class
#include <complex>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
// Container Control
#include <algorithm>

using namespace std;

#define rep( i, n ) for( int i = 0; i < n; ++i )
#define irep( i, n ) for( int i = n-1; i >= 0; --i )
#define reep( i, s, n ) for ( int i = s; i < n; ++i )
#define ireep( i, n, s ) for ( int i = n-1; i >= s; --i )
#define foreach(itr, x) for( typeof(x.begin()) itr = x.begin(); itr != x.end(); ++itr)

#define mp( a, b ) make_pair( a, b )
#define pb( a ) push_back( a );
#define all( v ) v.begin(), v.end()
#define fs first
#define sc second
#define vc vector

typedef long long ll;
typedef complex<double> Point;

typedef pair<int, int> pii;
typedef pair<int, pii> ipii;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector< vector<int> > vii;
typedef vector< vector<double> > vdd;

typedef vector<int>::iterator vi_itr;

const int IINF = 1 << 28;
const double INF = 1e30;
const double EPS = 1e-10;
const double PI = acos(-1.0);

// Direction : L U R D
const int dx[] = { -1, 0, 1, 0};
const int dy[] = { 0, -1, 0, 1 };

ll w, h, n;
set<ll> st[2];
multiset<ll> mst[2];

int main()
{
    cin >> w >> h >> n;
    st[0].insert(0);
    st[0].insert(h);
    st[1].insert(0);
    st[1].insert(w);
    mst[0].insert(h);
    mst[1].insert(w);
    char c;
    int x;
    while(n--) {
        cin >> c >> x;
        if(c == 'H') {
            set<ll>::iterator it = st[0].lower_bound(x);
            ll v1 = *it;
            ll v2 = *(--it);
            mst[0].erase(mst[0].find(v1-v2));
            st[0].insert(x);
            mst[0].insert(v1-x);
            mst[0].insert(x-v2);
            cout << (*mst[0].rbegin()) * (*mst[1].rbegin()) << endl;
        } else {
            set<ll>::iterator it = st[1].lower_bound(x);
            ll v1 = *it;
            ll v2 = *(--it);
            mst[1].erase(mst[1].find(v1-v2));
            st[1].insert(x);
            mst[1].insert(v1-x);
            mst[1].insert(x-v2);
            cout << (*mst[1].rbegin()) * (*mst[0].rbegin()) << endl;
        }
    }
    return 0;
}
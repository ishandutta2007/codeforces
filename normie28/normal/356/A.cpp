#include <bits/stdc++.h>

 
#define fi first
#define se second
#define LL long long
 
using namespace std;
 
const int N = 5e5 + 7;
const int mod = 1e9 + 7;
const int B = sqrt(N);
 
int n,m;
int par[N];
int ans[N];
set < int > s;
 
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(NULL);

 
    cin >> n >> m;
    for( int i = 1; i <= n; i++ )s.insert(i);
    for( int i = 1; i <= m; i++ ){
        int l,r,x;
        cin >> l >> r >> x;
        vector < int > v;
        auto p = s.upper_bound(l - 1);
        while( p != s.end() ){
            if( *p > r )break;
            if( *p != x ){
                ans[*p] = x;
                v.push_back(*p);
            }
            p = s.upper_bound(*p);
        }
        for( auto y : v )s.erase(y);
    }
    for( int i = 1; i <= n; i++ )
        cout << ans[i] << " ";
}
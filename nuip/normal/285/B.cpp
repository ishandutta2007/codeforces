#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

using namespace std;
int main(void) {
    int n, s, t;
    cin >> n >> s >> t;;
    
    vector<int> p(n);
    REP(i, n) cin >> p[i];;
    
    int ans = 0;
    while( s != t ) {
        s = p[s-1];
        ans++;
        if ( ans > n ) {
            cout << -1 << endl;
            return 0;
        }
    }
    
    cout << ans << endl;
    return 0;
}
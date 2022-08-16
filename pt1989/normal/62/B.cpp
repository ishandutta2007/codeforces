//      hello world


//DS includes
#include<bitset>
#include<complex>
#include<deque>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>

//Other Includes
#include<algorithm>
#include<cassert>
#include<climits>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<iostream>
#include<sstream>

#define oo          0xBADC0DE
#define s(n)            scanf("%d",&n)
#define sl(n)           scanf("%lld",&n)
#define sf(n)           scanf("%lf",&n)
#define fill(a,v)       memset(a, v, sizeof a)
#define ull             unsigned long long
#define ll              long long
#define bitcount        __builtin_popcount
#define all(x)          x.begin(), x.end()
#define pb( z )         push_back( z )
#define gcd             __gcd

#define FOR(i,n) for (int i=0; i < (n); i++)

using namespace std;

int n, k;
vector<int> pos[26];
#define id(x) (x-'a')
const int mxn = 200007;
char s[mxn];
char w[mxn];
int main(int argc, char** argv) {
    s(n); s(k);
    scanf("%s", s);
    for (int i=0; i < k; i++) {
        pos[ id( s[i] ) ].pb( i );
    }
    for (int wi=0; wi < n; wi++) {
        scanf("%s", w);
        int len = strlen(w);
        ll ans = 0;
        for (int i=0; i < len; i++) {
            int v = id( w[i] );
            if (pos[v].size() == 0) {
                ans += len;
            } else {
                int q = lower_bound( all(pos[v]), i ) - pos[v].begin();
                int cur = INT_MAX;
                for (int z=max(0,q-2); z < q+2 && z < (int)pos[v].size(); z++) {
                    cur = min(cur, abs(i - pos[v][z]) );
                }
                ans += cur;
            }
        }
        printf("%I64d\n", ans);
        //cout << ans << endl;
    }
    return 0;
}
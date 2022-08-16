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

const int mxn = 1024;
bool poss[mxn];
char buf[64];
char buf2[1024];
int main(int argc, char** argv) {
    int n, m;
    gets(buf2);
    sscanf(buf2, "%d %d", &n, &m);
    
    fill(poss, 1);
    
    while (m-- > 0) {
        gets(buf2);
        int v;
        sscanf(buf2, "To the %s of %d", buf, &v);
        //cout << buf2 << endl;
        if (buf[0] == 'l') {
            for (int x=v; x <= n; x++)
                poss[x] = 0;
        } else {
            for (int x=1; x <= v; x++)
                poss[x] = 0;
        }
    }
    int ans = 0;
    for (int i=1; i <= n; i++) if (poss[i]) ans ++;
    if (ans==0) ans = -1;
    cout << ans << endl;
    return 0;
}
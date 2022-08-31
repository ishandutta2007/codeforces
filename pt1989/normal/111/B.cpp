#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<bitset>
#include<complex>
 
#include<sstream>
#include<fstream>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<climits>
 
#define oo            (int)13e7
#define getcx getchar
inline void s( int &n ) {
	n=0;
	int ch=getcx();
	while( ch < '0' || ch > '9' ) ch=getcx();
	
	while(  ch >= '0' && ch <= '9' )
		n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
}
#define sl(n)         scanf("%lld",&n)
#define sf(n)         scanf("%lf",&n)
#define fill(a,v)     memset(a, v, sizeof a)
#define ull           unsigned long long
#define ll            long long
#define bitcount      __builtin_popcount
#define all(x)        x.begin(), x.end()
#define pb( z )       push_back( z )
#define gcd           __gcd
using namespace std;

const int mxn = 100007;
vector<int> factors[mxn];
int last[mxn];

int main(int argc, char** argv) {
	for (int f=1; f < mxn; f++)
    for (int n=f; n < mxn; n += f)
        factors[n].pb( f );
    
    
    for (int i=0; i < mxn; i++)
        last[i] = -1;
    
    int queries; s(queries);
    for (int qi=0; qi < queries; qi++) {
        int num; s(num);
        int index; s(index);
        int lo = qi - index;
        int cnt = 0;
        //cout << qi << "th query : \n";
        for (int j=0; j < factors[num].size(); j++) {
            int f = factors[num][j];
            if (last[f] < lo) {
                cnt++;
            }
        }
        for (int j=0; j < factors[num].size(); j++) {
            last[ factors[num][j] ] = qi;
        }
        printf("%d\n", cnt);
    }
    
	return 0;
}
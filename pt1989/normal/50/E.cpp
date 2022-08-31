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




#define oo 				0xBADC0DE
#define s(n)			scanf("%d",&n)
#define sl(n) 			scanf("%lld",&n)
#define sf(n) 			scanf("%lf",&n)
#define fill(a,v) 		memset(a, v, sizeof a)
#define ull 			unsigned long long
#define ll 				long long
#define bitcount 		__builtin_popcount
#define all(x) 			x.begin(), x.end()
#define pb( z ) 		push_back( z )
#define gcd				__gcd
using namespace std;
const int mxn = 5000000;
int op[4*mxn];
int cl[4*mxn];
#define id(x) (x+2*mxn)
inline void addRange(int lo, int hi) {
	op[id(lo)]++;
	cl[id(hi)]++;
}
int main(){
	int n, m;
	cin>>n>>m;
	ll ans = 0;
	
	for (int b=1; b <= n; b++) {
		ll b2 = b*(ll)b;
		ll hi = b2-1;
		ll lo = max(0LL,b2-m);
		ll lq = sqrt(lo); //if(lq*lq == lo) lq--;
		ll hq = sqrt(hi);
		ll roots = hq - lq + (lq*lq == lo);
		
		if (roots >= 1) {
			//1 root exists
			//cout << b << " -> " << lo << " , " << hi << endl;
			//cout << (-b-hq) << " to " << (-b-lq) << endl;
			//cout << (-b+lq) << " to " << (-b+hq) << endl;
			while (lq*lq < lo) lq++;
			
			addRange(-b-hq, -b-lq);
			addRange(-b+lq, -b+hq);
		}
		//cout << b << " -> " << lo << " , " << hi << endl;
		//cout << b << " " << roots << endl;
		ans += 2*( (hi-lo+1)-roots );
		
	}
	int in = 0;
	for (int i=0; i < 4*mxn; i++) {
		in += op[i];
		if (in > 0) {
			//cout << (i-2*mxn) << endl;
			ans++;
		}
		in -= cl[i];
	}
	cout << ans << endl;
	return 0;
}
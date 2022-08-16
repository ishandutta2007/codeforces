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

#define oo 			0xBADC0DE
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

#define FOR(i,n) for (int i=0; i < (n); i++)

using namespace std;

ll x, y, z, k;
ll ans = 0;

int main(int argc, char** argv) {
	cin>>x>>y>>z>>k;
	
	//maximise a*b*c, a, b, c <= x, y, z a+b+c-3 <= k
	
	{
		vector<ll> a;
		a.pb(x); a.pb(y); a.pb(z);
		sort( all(a) );
		vector<ll> cuts(3);
		while (k > 0) {
			bool cutMade = 0;
			for (int i=0; i < 3; i++) {
				if (a[i] > 1 && k > 0) {
					a[i]--; k--; cuts[i]++;
					cutMade = 1;
				}
			}
			if (!cutMade) break;
		}
		ll ans = 1;
		for (int i=0; i < 3; i++) {
			ans *= cuts[i] + 1;
		}
		cout << ans << endl;
	}
	
	return 0;
}
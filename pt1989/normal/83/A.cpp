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

const int mxn = 100007;
int a[mxn];
int n;

int main(int argc, char** argv) {
	s(n);
	for (int i=0; i < n; i++) s(a[i]);
	ll ans = 0;
	for (int i=0; i < n; ) {
		int j = i;
		while (j < n && a[j] == a[i]) {
			j++;
		}
		ll x = j-i;
		ans += x*(x+1)/2;
		i = j;
	}
	cout << ans << endl;
	return 0;
}
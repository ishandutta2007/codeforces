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

int main(){
	int n;
	cin>>n;
	string a;
	cin>>a;
	int H = 0, T = 0;
	for (int i=0; i < n; i++) {
		if (a[i] == 'H') H++;
		else T++;
	}
	
	int ans = oo;
	for (int hstart=0; hstart < n; hstart++) {
		int tigs = 0;
		for (int l=hstart; l < hstart+H; l++) {
			if ( a[ l%n ] == 'T' ) tigs++;
		}
		ans = min( ans, tigs );
	}
	cout << ans << endl;
	return 0;
}
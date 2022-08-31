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

int main(int argc, char** argv) {
	int y, x;
	cin>>x>>y;
	int turn = 0;
	while (true) {
		int H = 0, T = 0;
		if (turn==0) {
			H = min(2, x);
			T = (220 - H*100)/10;
		} else {
			if (y >= 22) {
				T = 22; H = 0;
			} else if (y >= 12) {
				T = 12; H = 1;
			} else {
				T = 2; H = 2;
			}
		}
		if (H > x || T > y) break;
		turn ^= 1;
		x -= H; y -= T;
	}
	if (turn)
		cout << "Ciel" << endl;
	else 
		cout << "Hanako" << endl;
	return 0;
}
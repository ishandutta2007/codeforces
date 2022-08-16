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
ull A, B;

int a[100], b[100];

bool vis[100][2];
string dp[100][2];
string solve(int bit, int carry) {
	if (bit < 0) {
		return carry == 0 ? "" : "z";
	}
	bool &v = vis[bit][carry];
	string &ret = dp[bit][carry];
	if (v)
		return ret;
	v = 1;
	ret = "z";
	for (int cur=0; cur < 2; cur++) {
		int xi = cur;
		int yi = b[bit] ^ xi;
		
		int ai = (xi + yi + carry)&1;
		if (ai == a[bit]) {
			int ncarry = (xi + yi + carry)>>1;	
			string nret = solve(bit-1, ncarry) + (char)(xi+ '0');
			ret = min(ret, nret);
		}
	}
	return ret;
}

ull decode(string x) {
	ull ret = 0;
	for (int i=0; i < x.size(); i++){
		ret = ret << 1;
		if (x[i] == '1') {
			ret ++;
		} else if (x[i] != '0') {
			cout << -1 << endl;
			exit(0);
		}
	}
	return ret;
}

int main(int argc, char** argv) {
	cin>>A>>B;
	ull oA = A, oB = B;
	for (int i=0; i < 64; i++) {
		a[63-i] = A&1; A >>= 1;
		b[63-i] = B&1; B >>= 1;
	}
	string ans = solve(63, 0);
	ull x = decode(ans);
	
	if (oA >= x) {
		cout << x << " " << oA-x << endl;
	} else {
		cout << -1 << endl;
	}
	return 0;
}
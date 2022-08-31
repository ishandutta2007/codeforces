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


int gcd(int a, int b) {
	if (a < b) return gcd(b, a);
	if (b==0) return a;
	return gcd(b, a%b);
}
#define FOR(i,n) for (int i=0; i < (n); i++)

struct fract {
	int num, den;
	fract(int N, int D) {
		int G = gcd(N, D);
		num = N/G;
		den = D/G;
	}
	bool operator < (const fract &f) const {
		return num * (ll)f.den < den * (ll)f.num;
	}
};
int rev(int x) {
	int y = 0;
	while (x > 0) {
		y = y*10 + x%10;
		x /= 10;
	}
	return y;
}
using namespace std;


const int mxn = 100011;


map<fract, int> cnt;
map<fract, int> cnt2;
int tree[mxn];


int main(int argc, char** argv) {
	int mxx, mxy, w;
	cin>>mxx>>mxy>>w;
	
	// a/ra = rb/b
	for (int a=1; a <= mxx; a++) {
		int ra = rev(a);
		fract f(a, ra);
		cnt[ f ]++;
	}
	const ll inf = (ll)1e18;
	ll ans = inf;
	int solA, solB = -1;
	int b = 1;
	ll count = 0;
	//must slide b up
	for (int a=mxx; a >= 1; a--) {
		while (count < w && b <= mxy) {
			int rb = rev(b);
			fract f(rb, b);
			count += cnt[f];
			cnt2[f]++;
			b++;
		}
		
		if (count >= w) {
			//do shit
			
			ll A = a;
			ll B = b-1;
			//cout << A << " " << B << " " << count << endl;
			if ( A * B <= ans ) {
				ans = A*B;
				solA = A;
				solB = B;
			}
		}
		int ra = rev(a);
		fract f(a, ra);
		count -= cnt2[f];
		cnt[f]--;
	}
	
	if (solB == -1) {
		cout << -1 << endl;
		exit(0);
	} else {
		cout << solA << " " << solB << endl;
	}
	return 0;
}
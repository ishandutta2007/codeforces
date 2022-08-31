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

int n, q;
const int mxn = 300007;
int w[mxn];
struct query {
	int a, b, id;
	ll sub;
	bool operator < (const query& p) const {
		if (b == p.b)
			return a < p.a;
		return b < p.b;
	}
};
query p[mxn];
ll mod[mxn];
ll sol[mxn];
int main(int argc, char** argv) {
	s(n);
	for (int i=1; i <= n; i++) s(w[i]);
	s(q);
	for (int i=0; i < q; i++) {
		p[i].id = i;
		s(p[i].a); s(p[i].b);
	}
	sort(p, p+q);
	
	int SQRTN = (int)round(sqrt(n));
	for (int i=0; i < q;) {
		int B = p[i].b;
		if (B <= SQRTN) {
			for (int m=0; m < B; m++)
				mod[m] = 0;
			int j = i;
			while (j < q && p[j].b == p[i].b) {
				j++;
			}
			
			//for (int pos=i; pos < j; pos++)cout << p[pos].a << "," << p[pos].b << endl; cout << endl;
			
			int ptr = j-1;
			for (int pos=n, f=n%B; pos >= 0; pos--, f--) {
				if (f < 0) f = B-1;
				mod[f] += w[pos];
				while (ptr >= i && p[ptr].a == pos) {
					p[ptr].sub = mod[f];
					ptr--;
				}
			}
			for (int pos=i; pos < j; pos++) {
				sol[ p[pos].id ] = p[pos].sub;
			}
			i = j;
		} else {
			ll &sum = sol[ p[i].id ] ;
			sum = 0;
			for (int pos=p[i].a; pos <= n; pos += p[i].b) {
				sum += w[pos];
			}
			i = i+1;
		}
	}
	
	if (1)
	for (int i=0; i < q; i++)
		printf("%I64d\n", sol[i]);
	
	return 0;
}
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
#define pc putchar
ll n, k;
int Q;
int main(int argc, char** argv) {
	cin>>n>>k>>Q;
	while (Q-- > 0) {
		ll p;
		cin>>p;
		if (n%2) {
			if (p == n) {
				pc(k > 0 ? 'X' : '.');
				continue;
			}
		}
		ll N = n - (n%2);
		ll K = k - (n%2);
		--p;
		/*
		p = KMAX
		0 = 8
		2 = 7
		4 = 6
		6 = 5

		1 = 4
		3 = 3
		5 = 2
		7 = 1
		*/
		ll KMAX = 0;
		if (p%2 == 0) {
			KMAX = N - (p/2);
		} else {
			KMAX = N/2 - (p-1)/2;
		}
		pc (K < KMAX ? '.' : 'X');
	}
	pc('\n');
	return 0;
}
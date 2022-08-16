//DS includes
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<bitset>
#include<complex>

//Other Includes
#include<sstream>
#include<fstream>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>

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
	int a, b, n;
	cin>>a>>b>>n;
	bool sign = (a<0) ^ (b<0);
	a = abs(a); b = abs(b);
	
	if (b==0) {
		cout << 0 << endl;
		exit(0);
	}
	
	bool bad = false;
	if (n%2 == 0 && sign) {
		bad = true;
	}
	else if ( a > 0 && b%a == 0 ) {
		
		int z = b/a;
		bad = true;
		for(int m=1; ;m++) {
			int tmp = 1;
			for(int k=0; k < n; k++)
				tmp *= m;
			
			if (tmp==z) {
				cout << m *(sign ? -1 : 1) << endl;
				exit(0);
			}
			
			if (tmp > z ) break;
		}
		
		
	} else {
		bad = true;
	}
	if (bad) cout << "No solution" << endl; 
	return 0;
}
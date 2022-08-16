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

string sz[] = {"S", "M", "L", "XL", "XXL"};
map<string,int> szm;
int cap[8];
int main(){
	for (int i=0; i < 5; i++) szm[sz[i]] = i;
	for (int i=0; i < 5; i++) cin>>cap[i];
	
	int n;
	cin>>n;
	while(n-- > 0) {
		string z; cin>>z;
		int s = szm[z];
		
		int bestid = 100000000;
		for (int i=4; i >= 0; i--)
		if (cap[i] > 0) {
			if ( abs(bestid-s) > abs(i-s) ) {
				bestid = i;
			}
		}
		cap[bestid]--;
		cout << sz[bestid] << endl;
		
	}
	
	return 0;
}
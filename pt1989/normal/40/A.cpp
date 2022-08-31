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
	int x, y;
	cin>>x>>y;
	int quad = (x < 0) ^ (y < 0);
	
	x = abs(x); y = abs(y);
	set<int> squares;
	for (int i=0; i <= 2048; i++) squares.insert(i*i);
	int r2 = x*x + y*y;
	if ( squares.find(r2) != squares.end() ) {
		cout <<"black"<<endl;
		exit(0);
	}
	
	int r = ceil(sqrt(r2));
	
	if ( (r%2==0) ^ quad )
		cout <<"white"<<endl;
	else
		cout<<"black"<<endl;
	
	return 0;
}
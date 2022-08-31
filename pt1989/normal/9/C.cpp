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



#define oo 					(int)13e7
#define s(n)					scanf("%d",&n)
#define sl(n) 					scanf("%lld",&n)
#define sf(n) 					scanf("%lf",&n)
#define fill(a,v) 				memset(a, v, sizeof a)
#define ull 					unsigned long long
#define ll 						long long
#define bitcount 			__builtin_popcount
#define all(x) 				x.begin(), x.end()
#define pb( z ) 				push_back( z )
#define gcd					__gcd
using namespace std;


vector< int > a;
void go( ll z )
{
	if( z > 1e9 ) return;
	a.pb( z );
	go( z*10 );
	go( z*10 + 1 );
}

int main()
{
	go( 1 );
	sort( all( a ) );
	int n;
	cin>>n;
	
	
	cout<< lower_bound( all( a ), n+1 ) - a.begin() << endl;
	return 0;
}
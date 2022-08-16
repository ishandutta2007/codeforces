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


int lo[128], hi[128];
int p1, p2, p3, t1, t2;
int n;

ll solve( int t )
{
	ll ret = 0;
	ret += min( t, t1 )*p1;
	t -= t1;
	if( t <= 0 ) return ret ;
	ret += min( t, t2 )*p2;
	t -= t2;
	if( t <= 0 ) return ret ;
	ret += t*p3;
	return ret;
}

int main()
{
	
	cin>>n;
	
	cin>>p1>>p2>>p3>>t1>>t2;
	
	for(int i=0; i < n; i++)
	cin>>lo[i]>>hi[i];
	
	ll ans = 0;
	
	for(int i=0; i < n; i++)
	{
		ans += (hi[i] - lo[i])*p1;
		if( i+1 < n )
		ans += solve( lo[i+1] - hi[i] );
	}
	cout<< ans << endl;
	
	return 0;
}
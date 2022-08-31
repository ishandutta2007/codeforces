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


ll dp[40][40][2];
int H;
ll solve( int n, int h, int comp)
{
	if( n==0 )
	{
		if( comp )
			return h >= H;
		return h < H;
	}
	ll& d = dp[n][h][comp];
	if( ~d ) return d;
	d = 0;
	for(int p=0; p < n; p++)
	{
		int L = p;
		int R = n-p-1;
		
		ll x, y, z;
		if( !comp )
		{
			d += x=solve( L, h+1, 0 )*solve( R, h+1, 0 );
	//		cout<< n << "->" << L << " " << R <<endl;		
	//		cout<< x <<endl;
			continue;
		}
		
		
		d += x=solve( L, h+1, 0 )*solve( R, h+1, 1 );
		d += y=solve( L, h+1, 1 )*solve( R, h+1, 0 );
		d += z=solve( L, h+1, 1 )*solve( R, h+1, 1 );
	//	cout<< n << "->" << L << " " << R <<endl;		
	//	cout<< x << " " << y << " " << z << endl;
	}
	//cout<< n+1 << " " << h << " " << comp << " = " << d << endl;
	return d;
}

int main()
{
	fill( dp, -1 );
	int n;
	s( n ); s( H );
	
	cout<< solve( n, 0, 1 ) << endl;
	return 0;
}
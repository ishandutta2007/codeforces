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
#define ull 					unsigned long long
#define ll 						long long
#define bitcount 			__builtin_popcount
#define all(x) 				x.begin(), x.end()
#define pb( z ) 				push_back( z )
#define gcd					__gcd
using namespace std;


int toStart[32];
int adj[32][32];
int lx[32], ly[32];
int n;
int ihyp( int dx, int dy )
{
	return dx*dx + dy*dy;
}

const int mx = 2705000;

int dp[1<<24];
int nxt[1<<24];
short bits[1<<24];

bool ok( int z )
{
	int b = bits[z];
	int fb = 0;
	while( z&1 )
	{
		z >>= 1;
		fb++;
	}
	return 2*fb >= b;
}

int main()
{
	int sx, sy;
	s( sx ); s( sy );
	s( n );
	for(int i=0; i < n; i++) s( lx[i] ), s( ly[i] );
	for(int i=0; i < (1<<n); i++)
	bits[i] = bits[i>>1] + (i&1);
	for(int i=0; i < n; i++)
	{
		toStart[ i ] = ihyp( lx[i]-sx, ly[i]-sy );
		for(int j=0; j < n; j++)
		adj[i][j] = ihyp( lx[i]-lx[j], ly[i]-ly[j] );
	}
	
	for(int mask=(1<<n)-1; mask >= 0; mask--)
	if( ok( mask ) )
	{
		if( mask == (1<<n)-1 ) continue;
		int &d = dp[mask];
		int z = 0;
		d = (int)2e9;
		for(int i=0; i < n; i++)
		if( !(mask & 1<<i) )
		{
			
			int nv = 2*toStart[i] + dp[ mask | 1<< i ] ;
			if( nv < d )
			{
				d=nv;
				z = mask | 1<<i;
			}
			for(int j=i+1; j < n; j++)
			if( !( mask & 1<<j ) )
			{
				nv = toStart[i] + toStart[j] + adj[i][j] + dp[ mask | 1<<i | 1<<j ];
				if( nv < d )
				{
					d=nv;
					z = mask | 1<<i | 1 << j;
				}
			}
			
			break;
		}
		
		nxt[mask ] =z;
	}
	vector<int> sol;
	int m = 0;
	sol.pb( 0 );
	while( m != (1<<n)-1 )
	{
		int nmask = nxt[ m ];
		int b = nmask ^ m;
		
		if( bitcount( b ) == 1 )
		{
			for(int i=0; i < n; i++)
			if( b & 1<<i )
				sol.pb( i+1 );
		}
		else
		{
			for(int i=0; i < n; i++)
			if( b & 1<<i )
			for(int j=i+1; j < n; j++)
			if( b & 1<<j )
				sol.pb( i+1 ), sol.pb( j+1 );
		}
		sol.pb( 0 );
		m = nmask;
	}
	
	printf("%d\n", dp[0] );
	int sz = sol.size();
	for(int i=0; i < sz; i++)
	{
		printf("%d%c", sol[i], i+1==sz ? '\n' : ' ' );
	}
	
	return 0;
}
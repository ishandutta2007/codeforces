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

const int mxn = (int)1e5+7;
char a[mxn];
char b[mxn];
char c[mxn];
int pre[mxn];

bool ok( char *a, char *b, char *c )
{
	
	
	char *pat = b;
	char *txt = a;
	int nt = strlen( txt );
	int np = strlen( pat );
	for(int i=1, m=0; i < np; ++i)
	{
			while( m > 0 && pat[ i ] != pat[ m ] )
			{
					m = pre[ m - 1 ];
			}
			if( pat[i] == pat[m] )
					++m;
			pre[i] = m;
	}
	int mnp = nt;
	for(int i=0, m=0; i < nt; ++i)
	{
			while( m > 0 && m < np    && txt[i] != pat[m] )
			{
					  m = pre[ m - 1  ];
			}
			if( txt[i] == pat[m] )    ++m;
			if( m == np )
			{
					  mnp = i-m+1; 
					  m = pre[m-1];
					  break;
			}
	}

	pat = c;
	txt = a;
	nt = strlen( txt );
	np = strlen( pat );
	for(int i=1, m=0; i < np; ++i)
	{
			while( m > 0 && pat[ i ] != pat[ m ] )
			{
					m = pre[ m - 1 ];
			}
			if( pat[i] == pat[m] )
					++m;
			pre[i] = m;
	}
	int mxp = -1;
	for(int i=0, m=0; i < nt; ++i)
	{
			while( m > 0 && m < np    && txt[i] != pat[m] )
			{
					  m = pre[ m - 1  ];
			}
			if( txt[i] == pat[m] )    ++m;
			if( m == np )
			{
					  mxp = i-m+1; 
					  m = pre[m-1];
			}
	}
	
	//cout<< a << " " << b << " " << c << " " << mnp << " " << mxp << endl;
	return mnp+(int)strlen(b) <= mxp;
}

int main()
{
	scanf("%s%s%s", a, b, c );
	int F = ok( a, b, c );
	reverse( a, a+strlen( a  ) );
	int B = ok( a, b, c );
	if( F&&B )
	{
		cout<<"both"<<endl;
	}
	else if( F )
	{
		cout<<"forward"<<endl;
	}
	else if( B )
	{
		cout<<"backward"<<endl;
	}
	else
		cout<<"fantasy"<<endl;
	return 0;
}
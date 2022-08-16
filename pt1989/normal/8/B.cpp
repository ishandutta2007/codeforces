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

#define pii pair< int,int >
#define mp make_pair
set< pii > m;
int main()
{
	string a;
	cin>>a;
	int sz = a.size();
	int x=0, y=0;
	m.insert( mp( x, y ) );
	
	vector< int > X, Y;
	X.pb( x ); Y.pb( y ); 
	
	for(int i=0; i < sz; i++)
	{
		char c = a[i];
		if( c == 'L' ) x--;
		if( c=='R' ) x++;
		if( c=='U' ) y++;
		if( c=='D' ) y--;
		if( m.count( mp(x,y) ) )
		{
			cout<<"BUG"<<endl;
			exit( 0 );
		}
		m.insert( mp( x, y ) );
		X.pb( x );
		Y.pb( y );
	}
	
	int n = X.size();

	for(int i=0; i < n; i++)
	for(int j=i+2; j < n; j++)
	if( abs( X[i] - X[j] ) + abs( Y[i] - Y[j] ) <= 1 )
	{
		cout<<"BUG"<<endl;
		exit( 0 );
	}
	
	
	
	cout<<"OK"<<endl;
	
	return 0;
}
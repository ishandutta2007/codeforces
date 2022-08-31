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

const int mxn = (int)1e5;
int a[mxn];
int pre[mxn];
int main()
{
	int n;
	s(n);
	for(int i=1; i <= n; i++)
	{
		s(a[i]);
		pre[i] = pre[i-1]+a[i];
	}
	int sum = pre[n];
	int sol = 0;
	for(int i=1; i < n; i++)
	{
		int Z = pre[n]-pre[i];
		if( Z*2 == sum )
			sol++;
	}
	cout<< sol << endl;
	return 0;
}
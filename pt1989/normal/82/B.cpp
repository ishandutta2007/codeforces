//      hello world


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

#define oo 			0xBADC0DE
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

#define FOR(i,n) for (int i=0; i < (n); i++)

using namespace std;

//fun fun fun
//returns a & b
vector<int> inter(vector<int> a, vector<int> b) {
	set<int> aset( a.begin(), a.end() );
	vector<int> com;
	for (int i=0; i < (int)b.size(); i++)
		if (aset.count( b[i] ))
			com.pb( b[i] );
	return com;
}
const int mxn = 207;
int n, m;
vector<int> a[mxn*mxn];
vector<int> exists[mxn];
bool marked[mxn];
set<int> _nums;

int main(int argc, char** argv) {
	s(n);
	m = (n*(n-1))/2;
	
	for (int i=0; i < m; i++) {
		int k; s(k);
		a[i].resize( k );
		for (int j=0; j < k; j++) {
			s(a[i][j]);
			exists[ a[i][j] ].pb( i );
			_nums.insert( a[i][j] );
		}
	}
	
	if (n==2) {
		cout << 1 << " ";
		cout << a[0][0] << endl;
		
		cout << a[0].size()-1 ;
		for (int i=1; i < (int)a[0].size(); i++)
			cout << " " << a[0][i];
		cout << endl;
		exit(0);
	}
	
	vector<int> nums( _nums.begin(), _nums.end() );
	for (int i=0; i < nums.size(); i++) {
		int x = nums[i];
		if (marked[x]) continue;
		marked[x] = 1;
		vector<int> th = inter( a[ exists[x][0] ], a[ exists[x][1] ] );
		printf("%d", th.size());
		for (int z=0; z < (int)th.size(); z++) {
			printf(" %d", th[z]);
			marked[ th[z] ] = 1;
		}
		puts("");
	}
	
	return 0;
}
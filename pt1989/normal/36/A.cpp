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
	
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int n;
	string a;
	cin>>n>>a;
	
	vector<int> p;
	
	for (int i=0; i < a.size(); i++) 
	if (a[i] == '1') p.pb(i);
	
	int diff = p[1] - p[0];
	bool bad = false;
	for (int i=2; i < p.size(); i++)
	if ( p[i] - p[i-1] != diff ) {
		bad = true;
		break;
	}
	cout << ( bad ? "NO" : "YES" ) << endl;
	return 0;
}
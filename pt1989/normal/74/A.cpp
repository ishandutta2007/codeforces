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

int main(int argc, char** argv) {
	int n;
	cin>>n;
	string name;
	int ans = 0;
	bool first = 1;
	while (n-- > 0) {
		string handle;
		int plus, minus, a, b, c, d, e;
		cin>>handle>>plus>>minus>>a>>b>>c>>d>>e;
		int curScore = plus*100 + minus*-50 + a + b + c + d + e;
		if (curScore > ans || first) {
			ans = curScore;
			name = handle;
		}
		first = 0;
	}
	cout << name << endl;
	return 0;
}
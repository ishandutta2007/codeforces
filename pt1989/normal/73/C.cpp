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

char s[128];
int k;
int n;
int a[32][32];

int dp[28][102][102];
bool vis[28][102][102];
int solve(int prev, int pos, int left) {
	if (s[pos] == 0)
		return 0;
	int &ret = dp[prev][pos][left];
	bool &v = vis[prev][pos][left];
	if (v) return ret;
	v=1;
	int curChar = s[pos] - 'a';
	ret = a[prev][curChar] + solve(curChar, pos+1, left);
	if (left > 0) {
		for (int nchar=0; nchar < 26; nchar++) {
			ret = max(ret, a[prev][nchar] + solve(nchar, pos+1, left-1) );
		}
	}
	return ret;
}

int main(int argc, char** argv) {
	fill(a, 0); fill(dp, -1);
	cin>>s>>k;
	
	cin>>n;
	while (n-- > 0) {
		string F, T;
		int C;
		cin>>F>>T>>C;
		int f = F[0] - 'a';
		int t = T[0] - 'a';
		a[f][t] = C;
	}
	
	cout << solve(26, 0, k) << endl;
	
	return 0;
}
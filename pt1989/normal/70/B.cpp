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
char a[10007];
bool isEnd(char c) {
	return c == '.' || c == '!' || c == '?';
}
vector<int> sents;

int dp[10007];
int n;
int solve(int v) {
	
	int len = sents.size();
	if (v >= len)
		return 0;
	int &ret = dp[v];
	if (~ret) return ret;
	int sum = 0;
	ret = (int)1e9;
	for (int nv=v; nv < len; nv++) {
		sum += sents[nv];
		if (sum > n) break;
		ret = min(ret, 1 + solve(nv+1));
		sum++;
		if (sum > n) break;
	}
	return ret;
}

int main(int argc, char** argv) {
	
	gets(a); 
	sscanf(a, "%d", &n);
	gets(a);
	
	stringstream sin(a);
	
	int len = 0;
	int count = 0;
	for (string tmp; sin>>tmp; ){
		len += tmp.size();
		count++;
		if (isEnd(tmp[ tmp.size()-1 ])) {
			sents.pb(len + count-1);
			len = 0;
			count = 0;
		}	
	}
	fill(dp, -1);
	int res = solve(0);
	if (res > sents.size()) {
		puts("Impossible");
	} else {
		cout << res << endl;
	}
	
	return 0;
}
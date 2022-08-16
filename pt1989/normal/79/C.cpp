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

const int mxn = 100007;
char a[mxn];
char b[16][16];
int sub[mxn];
bool startsWith(char *txt, char *pat) {
	int i=0;
	for (; txt[i] && pat[i]; i++) {
		if (txt[i] != pat[i])
			return 0;
	}
	return pat[i] == 0;
}
const int INF = (int)1e9;
int dp[mxn];

int main(int argc, char** argv) {
	scanf("%s", a);
	int n; 
	s(n);
	for (int i=0; i < n; i++) {
		scanf("%s", b[i]);
	}
	
	for (int i=0; i < n; i++)
	for (int j=i+1; j < n; j++)
	if (strlen(b[j]) < strlen(b[i])) {
		swap(b[i], b[j]);
	}
		
	int A = strlen(a);
	for (int i=0; i  < A; i++) {
		sub[i] = INF;
		for (int j=0; j < n; j++) {
			if (startsWith( a+i, b[j] )) {
				sub[i] = strlen( b[j] );
				break;
			}
		}
	}
	
	int ans = 0, pos = 0;
	for (int i=A-1; i >= 0; i--) {
		if (sub[i] == INF) {
			dp[i] = 1 + dp[i+1];
		} else {
			int len = sub[i] - 1;
			dp[i] = len;
			for (int np=i+1; np < i+len; np++)
				if (sub[np] != INF) {
					dp[i] = min(dp[i],  np + sub[np] - 1 - i);
				}
		}
		if (dp[i] > ans) {
			ans = dp[i];
			pos = i;
		}
	}
	cout << ans <<" " << pos << endl;
	return 0;
}
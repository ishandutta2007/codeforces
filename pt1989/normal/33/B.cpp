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

const int mxn = (int)1e5 + 7;
char a[mxn], b[mxn], c[mxn];
ll cost[256][256];

const ll INF = (ll)1e17;

int main(){
	int n;
	scanf("%s %s %d", a, b, &n);
	for(int i=0; i < 256; i++)
	for(int j=0; j < 256; j++)
	cost[i][j] = INF;
	
	
	for(int j=0; j < 256; j++)
	cost[j][j] = 0;
	
	while (n--) {
		char x[12], y[12];
		int cc;
		scanf("%s %s %d", x, y, &cc);
		cost[ x[0] ][ y[0] ] = min( cost[x[0]][y[0]], (ll)cc); 
		
	}
	
	for (int k='a'; k <= 'z'; k++)
	for (int i='a'; i <= 'z'; i++) 
	for (int j='a'; j <= 'z'; j++)
	cost[i][j] = min( cost[i][j], cost[i][k] + cost[k][j] );
	
	int al = strlen(a), bl = strlen(b);
	
	
	bool bad = al != bl;
	ll solution = 0;
	for (int i=0; i < al; i++) {
		char ai = a[i];
		char bi = b[i];
		
		ll sol = INF;
		int mchar = -1;
		for (int meet='a'; meet <= 'z'; meet++) {
			ll lcost = cost[ai][meet];
			ll rcost = cost[bi][meet];
			
			if (lcost + rcost < sol) {
				sol = lcost + rcost;
				mchar = meet;
			}
		}
		if (mchar == -1) {
			bad = true;
			break;
		}
		solution += sol;
		c[i] = mchar;
	}
	
	if (bad) {
		puts("-1");
		exit(0);
	}
	cout << solution << endl;
	printf("%s\n", c);
	
	return 0;
}
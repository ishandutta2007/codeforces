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

char a[2][1024][1024];
char orig[1024][1024];
int main(){
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, k;
	cin>>n>>k;
	
	for (int i=0; i < n; i++) {
		cin>> orig[i];
		for (int j=0; j < n; j++)
			a[1][i][j] = orig[i][j];
	}
	
	int N = n;
	for (int ki=2; ki <= k; ki++) {
		N *= n;
		int cur = ki&1;
		int prev = cur ^ 1;
		for (int i=0; i < N; i++) {
			
			for (int j=0; j < N; j++) {
				int x = i/n, y = j/n;
				if (a[prev][x][y] == '*') {
					a[cur][i][j] = '*';
				} else {
					int xx = i%n, yy = j%n;
					a[cur][i][j] = orig[xx][yy];
				}
			} 
		}
		
		
		
		
	}
	for (int i=0; i < N; i++)
	cout << a[k&1][i] << endl;
	
	return 0;
}
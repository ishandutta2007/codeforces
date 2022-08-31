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


int a[9][9];

int main(){
	int x, y;
	string tmp;
	cin>>tmp;
	x = tmp[0] - 'a' + 1;
	y = tmp[1] - '0';
	for (int i=1; i <= 8; i++)
	for (int j=1; j <= 8; j++)
	if (x==i || j==y) {
		a[i][j] = 1;
	}
	
	for (int dx=-2; dx <= 2; dx++)
	for (int dy=-2; dy <= 2; dy++)
	if (dx*dx + dy*dy == 5) {
		int nx = x + dx;
		int ny = y + dy;
		if (nx >= 1 && ny >= 1 && nx <= 8 && ny <= 8) {
			a[nx][ny] = 1;
		}
	}
	
	cin>>tmp;
	x = tmp[0] - 'a' + 1;
	y = tmp[1] - '0';
	
	a[x][y] = 1;
	for (int dx=-2; dx <= 2; dx++)
	for (int dy=-2; dy <= 2; dy++)
	if (dx*dx + dy*dy == 5) {
		int nx = x + dx;
		int ny = y + dy;
		if (nx >= 1 && ny >= 1 && nx <= 8 && ny <= 8) {
			a[nx][ny] = 1;
		}
	}
	
	
	int ans = 0;
	for (int i=1; i <= 8; i++)
	for (int j=1; j <= 8; j++)
	if (!a[i][j]) {
		ans++;
	} 
	
	cout << ans << endl;
	return 0;
}
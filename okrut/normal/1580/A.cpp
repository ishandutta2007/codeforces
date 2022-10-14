#pragma GCC optimize "O3"
#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) //fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 403;

string B[N];
int LL[N][N], R[N][N], C[N][N];

int main ()
{
	ios_base::sync_with_stdio(false);
	
	int t; cin>>t;
	rep(q,0,t) {
		int n, m;
		cin>>n >>m;
		rep(i,0,n) cin>>B[i];
		
		rep(i,0,n) {
			rep(j,0,m) R[i+1][j+1] = R[i+1][j] + B[i][j] - '0';
		}
		
		rep(j,0,m) {
			rep(i,0,n) C[i+1][j+1] = C[i][j+1] + B[i][j] - '0';
		}
		
		rep(i,0,n) rep(j,0,m) {
			LL[i+1][j+1] = LL[i][j+1] + R[i+1][j+1];
		}
		
		int best = n*m;
		
		rep(xl,1,n) rep(xh,xl+4,n+1) {
			
			int sum = 0;
			rep(i,1,m+1) sum += C[xh-1][i] - C[xl][i] + 2 - (B[xl-1][i-1] - '0') - (B[xh-1][i-1] - '0');
			
			pair <int, int> mini = {n*m, m+10};
			
			debug ("\nDo rows %d and %d (sum = %d)\n", xl, xh, sum);
			
			for (int yl = m-3; yl > 0; yl--) {
				int i = yl + 3;
				
				sum -= C[xh-1][i] - C[xl][i] + 2 - (B[xl-1][i-1] - '0') - (B[xh-1][i-1] - '0');
				
				int res = sum + (xh - xl - 1) - (C[xh-1][i] - C[xl][i]);
				
				mini = min(mini, make_pair(res, i));
				
				int yh = mini.se;
				
				
				
				int middle = LL[xh-1][yh-1] - LL[xh-1][yl] - LL[xl][yh-1] + LL[xl][yl];
			
				int rows = 0;
				rows += R[xh][yh-1] - R[xh][yl];
				rows += R[xl][yh-1] - R[xl][yl];
				rows += C[xh-1][yh] - C[xl][yh];
				rows += C[xh-1][yl] - C[xl][yl];
				
				
				int curr = middle + 2*(xh - xl + yh - yl - 2) - rows;
				best = min(best, curr);
				
				debug ("Do option [%d %d] --> %d\n", yl, yh, curr);
			}
		}
		
		cout<<best <<"\n";
	}
}
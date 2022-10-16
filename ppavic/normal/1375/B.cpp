#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef pair < ll, ll > pll;
typedef vector < int > vi;

const int N = 5005;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 18;
const int OFF = (1 << OFF);

int n, m, T, A[N][N];

int main(){
	scanf("%d", &T);
	for(;T--;){
		scanf("%d%d", &n, &m);
		for(int i = 0;i < n;i++)
			for(int j = 0;j < m;j++)
				scanf("%d", &A[i][j]);
		bool mogu = 1;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				int ans = (i != 0) + (i != n - 1) + (j != 0) + (j != m - 1);
				if(A[i][j] > ans)
					mogu = 0;
				A[i][j] = ans;
			}
		}
		if(mogu){
			printf("YES\n");
		}
		else{
			printf("NO\n");
			continue;
		}
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				printf("%d ", A[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
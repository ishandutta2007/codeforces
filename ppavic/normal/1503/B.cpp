#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef pair < int, int > pt;
typedef vector < int > vi;

const int N = 105;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7; // 998244353
const int LOG = 20;
const int OFF = (1 << LOG);

inline int add(int A, int B) {if(A + B >= MOD) return A + B - MOD; return A + B; }
inline int sub(int A, int B) {if(A - B < 0) return A - B + MOD; return A - B; }
inline int mul(int A, int B) { return (ll)A * B % MOD; }

vector < pii > p[3];

int n, bio[N][N];

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			p[1 + (i + j) % 2].PB({i, j});
	for(int i = 0;i < n * n;i++){
		int x; scanf("%d", &x);
		int biram = 1 + (x == 1);
		printf("%d %d %d\n", biram, p[biram].back().X, p[biram].back().Y);
		fflush(stdout);
		bio[p[biram].back().X][p[biram].back().Y] = 1;
		p[biram].pop_back();
		if((int)p[biram].size() == 0){
			for(int i = 1;i <= n;i++)
				for(int j = 1;j <= n;j++)
					if(!bio[i][j]) {
						int x; scanf("%d", &x);
						if(x != 3)
							printf("3 %d %d\n", i, j);
						else
							printf("%d %d %d\n", 3 - biram, i, j);
						fflush(stdout);
					}	
			break;
		}
	}
	fflush(stdout);
	return 0;
}
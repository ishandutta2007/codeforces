#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <vector>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;
typedef pair < int, int > pt;
typedef vector < int > vi;
typedef set < int > si;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 18;
const int OFF = (1 << 18);

ll ccw(pt A, pt B, pt C) { return (ll)A.X * (B.Y - C.Y) + (ll)B.X * (C.Y - A.Y) + (ll)C.X * (A.Y - B.Y); }
int add(int A, int B) { if(A + B >= MOD) return A + B - MOD; return A + B; }
int mul(int A, int B) { return (ll)A * B % MOD; }
int sub(int A, int B) { if(A - B < 0) return A - B + MOD; return A - B; }

int n = 32, L, R;
int do_pot = 21;
vector < pair < pii, int > > edg;

int main(){
	scanf("%d%d", &L, &R);
	if(L == R){
		printf("YES\n");
		printf("2 1\n1 2 %d\n", L);
		return 0;
	}
	if(L == 1){
		edg.PB({{1, n}, 1}); L++;
	}
	for(int i = 2;i <= do_pot;i++){
		for(int j = 1;j < i;j++)
			edg.PB({{j, i}, (1 << (i - 2))});
	}
	int cur = 22;
	for(int j = 19;j >= 0;j--){
		if(R - L + 1 >= (1 << j)){
			if(L > (1 << j)){
				edg.PB({{j + 2, n}, L - (1 << j)});
			}	
			else{
				for(int k = -1;k < j;k++){
					edg.PB({{k + 2, cur}, 1});
				}
				edg.PB({{cur++, n}, L - 1});
			}
			L += (1 << j);
		}
	}
	printf("YES\n");
	printf("%d %d\n", n, (int)edg.size());
	for(pair < pii, int > tmp : edg)
		printf("%d %d %d\n", tmp.X.X, tmp.X.Y, tmp.Y);
	//printf("cur = %d\n", cur);
	return 0;
}
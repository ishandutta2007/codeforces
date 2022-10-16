#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <set>
#include <map>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef vector < int > vi;
typedef set < int > si;
typedef vector < ll > vl;
typedef pair < ll, ll > pll;

const int N = 1e3 + 500;
const ll INF = 1e11;
const int MOD = 1e9 + 7;
const int BS = 31337;
const int OFF  = (1 << 18);


int pos[4][4] = {{8,9,1,13},{3,12,7,5},{0,2,4,11},{6,10,15,14}};

int n;
int a[N][N];

int main(){
	scanf("%d", &n);
	int m = n / 4;
	for(int i = 0;i < m;i++){
		for(int j = 0;j < m;j++){
			for(int k = 0;k < 4;k++){
				for(int l = 0;l < 4;l++){
					a[4 * i + k][4 * j + l] = pos[k][l] + 16 * (m * i + j);
				}
			}
		}
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
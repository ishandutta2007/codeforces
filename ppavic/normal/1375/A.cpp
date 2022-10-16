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

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 18;
const int OFF = (1 << OFF);

int A[N], n, T;

int main(){
	scanf("%d", &T);
	for(;T--;){
		scanf("%d", &n);
		for(int i = 0;i < n;i++){
			int x; scanf("%d", &x);
			x = (x < 0 ? -x : x);
			if(i & 1) x = -x;
			printf("%d ", x);
		}
		printf("\n");
	}
	return 0;
}
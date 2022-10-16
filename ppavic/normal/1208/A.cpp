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

const int N = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int BS = 31337;

int n, T, a, b;

int main(){
	scanf("%d", &T);
	for(;T--;){
		scanf("%d%d%d", &a, &b, &n);
		if(n % 3 == 0) printf("%d\n", a);
		else if(n % 3 == 1) printf("%d\n", b);
		else printf("%d\n", a ^ b);
	}
	return 0;
}
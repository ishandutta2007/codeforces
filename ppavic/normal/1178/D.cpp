#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef vector < int > vi;
typedef vector < ll > vl;
typedef pair < pii, int > ppi;
typedef pair < int, pii > pip;
typedef long double ld;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int LOG = 20;
const int OFF = (1 << LOG);
const ld PI = 3.1415926535;
const ld EPS = 1e-9;

int n;

bool prime(int x){
	if(x == 2) return 1;
	for(int i = 2;i * i <= x;i++){
		if(!(x % i)) return 0;
	}
	return 1;
}

int main(){
	scanf("%d", &n);
	for(int j = n;j <= n + n / 2;j++){
		if(!prime(j)) continue;
		int ost = j - n;
		printf("%d\n", j);
		for(int i = 1;i < n;i++) printf("%d %d\n", i, i + 1);
		printf("%d %d\n", n , 1);
		for(int k = 1;k <= ost;k++){
			printf("%d %d\n", k, k + n / 2);
		}
		return 0;
	}
	return 0;
}
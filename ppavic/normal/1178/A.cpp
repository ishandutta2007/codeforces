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

int n, A[N], sm = 0, u[N], cnt = 0, uk = 0;

int main(){
	scanf("%d", &n);
	for(int i = 0;i < n;i++){
		scanf("%d", A + i);
		uk += A[i];
	}
	sm = A[0]; cnt = 1; u[0] = 1;
	for(int i = 1;i < n;i++){
		if(A[0] >= 2 * A[i]){
			u[i] = 1; cnt++; sm += A[i];
		}
	}
	if(2 * sm <= uk){
		printf("0\n");
		return 0;
	}
	printf("%d\n", cnt);
	for(int i = 0;i < n;i++)
		if(u[i]) printf("%d ", i + 1);
	printf("\n");
	return 0;
}
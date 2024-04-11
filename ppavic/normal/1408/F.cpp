#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef pii pt;
typedef vector < int > vi;
typedef vector < ll > vl;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int LOG = 20;
const int OFF = (1 << LOG);

int n, p = 1;
vector < pii > sol;

int main(){
	scanf("%d", &n);
	while(2 * p < n)
		p *= 2;
	for(int k = 0;(1 << k) < p;k++){
		for(int i = 0;i < p;i++){
			if(!(i & (1 << k))){
				sol.PB({i + 1, i + (1 << k) + 1});
			}	
		}
	}
	for(int k = 0;(1 << k) < p;k++){
		for(int i = 0;i < p;i++){
			if(!(i & (1 << k))){
				sol.PB({i + 1 + n - p, i + (1 << k) + 1 + n - p});
			}	
		}
	}	
	printf("%d\n", (int)sol.size());
	for(pii tmp : sol)
		printf("%d %d\n", tmp.X, tmp.Y);
	return 0;
}
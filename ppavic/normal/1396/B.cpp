#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
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

const int N = 105;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 18;
const int OFF = (1 << LOG);

int n, T, a[N], ima[N];
multiset < int > S;

int main(){
	scanf("%d", &T);
	for(;T--;){
		scanf("%d", &n);
		for(int i = 0;i < n;i++){
			scanf("%d", a + i);
			S.insert(a[i]);
		}
		bool pot = 0;
		int lst = 0;
		for(;(int)S.size() > 0;pot = !pot){
			int nw = *(--S.end());
			S.erase(--S.end());
			if(lst != 0)
				S.insert(lst);
			lst = nw - 1;
		}
		if(pot)
			printf("T\n");
		else
			printf("HL\n");
		
	}
	return 0;
}
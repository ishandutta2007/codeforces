#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <algorithm>
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
typedef set < int > si;
typedef long double ld;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 18;
const ld PI = 3.1415926535;
const ld EPS = 1e-9;

ll n, k, a[N];
int m;

int main(){
	scanf("%lld%d%lld", &n, &m, &k);
	for(int i = 0;i < m;i++)
		scanf("%lld", a + i), a[i]--;
	int sol = 0;
	for(int i = 0;i < m;){
		int j = i;
		ll cur = (a[i] - j) / k;
		while(i < m && (a[i] - j) / k == cur)
			i++;	
		sol++; 
	}		
	printf("%d\n", sol);
	return 0;
}
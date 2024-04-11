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

const int N = 3e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 18;
const int OFF = (1 << OFF);

int P[N], n, T, moz[N], dpL[N];

int main(){
	scanf("%d", &T);
	for(;T--;){
		scanf("%d", &n);
		for(int i = 0;i < n;i++)
			scanf("%d", P + i);
		if(P[0] < P[n - 1])
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
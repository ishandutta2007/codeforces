#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > pii;

const int N = 1e5 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 18;
const int OFF = (1 << 18);

ll fik[10];
ll cur = 1, k;
char s[20] = "codeforces";

int main(){
	scanf("%lld", &k);
	for(int i = 0;i < 10;i++) fik[i] = 1;
	int i = 0;
	while(cur < k){
		cur = (cur / fik[i]) * (fik[i] + 1);
		fik[i]++; i = (i + 1) % 10;
	}
	for(int i = 0;i < 10;i++){
		for(int j = 0;j < fik[i];j++)
			printf("%c", s[i]);
	}
	printf("\n");
	return 0;
}
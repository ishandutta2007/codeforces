#include <cstdio>
#include <vector>
#include <algorithm>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef pair < int, int > pii;
typedef vector < int > vi;
typedef vector < pii > vp;

const int N = 1e5 + 500;
const int INF = 0x3f3f3f3f;

vp v;
int A[N], n, m;

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0;i < n;i++)
		scanf("%d", A + i);
	for(int i = 0;i < m;i++){
		int x, y; scanf("%d%d", &y, &x);
		v.PB({y, x});
	}
	v.PB({0, 0});
	sort(v.begin(), v.end());
	for(int i = 1;i < v.size();i++)
		v[i].Y += v[i - 1].Y;
	for(int i = 0;i < n;i++){
		printf("%d ", (--upper_bound(v.begin(), v.end(), (pii){A[i], INF})) -> Y);
	}
	printf("\n");
}
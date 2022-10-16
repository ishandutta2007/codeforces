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
const int INF = 0x3f3f3f3f;
const int LOG = 20;
const int OFF = (1 << LOG);

vector < pii > uvj;

int n, m, x[N], y[N], a[N], b[N];

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0;i < n;i++)
		scanf("%d%d", x + i, y + i);
	for(int i = 0;i < m;i++)
		scanf("%d%d", a + i, b + i);
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++)
			if(a[j] >= x[i] && b[j] >= y[i])
				uvj.PB({a[j] - x[i] + 1, b[j] - y[i] + 1});
	sort(uvj.rbegin(), uvj.rend());
	int mor = 0, ans = INF;
	for(int i = 0;i < (int)uvj.size();i++){
		ans = min(ans, uvj[i].X + mor);
		mor = max(mor, uvj[i].Y);
	}
	ans = min(ans, mor);
	printf("%d\n", ans);
	return 0;
}
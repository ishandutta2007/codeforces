#include <cstdio>
#include <cstring>
#include <vector>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef vector < int > vi;
const int N = 2e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int OFF = (1 << LOG);

int n, a[N];
ll sm = 0, mi, mx;

int main(){
	scanf("%d", &n);
	for(int i = 0;i < n;i++){
		a[i] = 2 * i + 1, a[n + i] = 2 * i + 2;
		if(i & 1) swap(a[i], a[n + i]);
	}
	sm = 1LL * n * (2 * n + 1);
	ll cur = 0;
	for(int i = 0;i < n;i++)
		cur += a[i];
	mi = cur, mx = 0;
	
	for(int i = 0;i < n;i++){
		cur -= a[i]; cur += a[n + i];
		mi = min(min(cur, sm - cur), mi);
		mx = max(max(cur, sm - cur), mx);
	}
	if(mx - mi > 1){
		printf("NO\n"); return 0;
	}
	printf("YES\n");
	for(int i = 0;i < 2 * n;i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}
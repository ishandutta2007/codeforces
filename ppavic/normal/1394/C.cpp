#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

#define X first
#define Y second
#define PB push_back

/**

Jesam li sto rekao?
Sve sto sam rekao,
zaglusio je tutanj tramvaja...

Antun Soljan

**/

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef vector < int > vi;
typedef long long ll;

const int N = 5e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int OFF = (1 << 18);

int mi_x = N, mi_y = N, mx_x = 0, mx_y = 0;
int mx_dig = -N, mi_dig = N;
int x[N], y[N], n;
char s[N];
int ans_x = 0, ans_y = 0;

int dis(int x, int y, int a, int b){
	if((x <= a && y <= b) || (x >= a && y >= b))
		return max(abs(x - a), abs(y - b));
	return abs(x - a) + abs(y - b);
}

bool probaj_toc(int cx, int cy, int k){
	//printf("probavam %d %d\n", cx, cy);
	for(int i = 0;i < n;i++)
		if(dis(cx, cy, x[i], y[i]) > k)
			return 0;
	ans_x = cx, ans_y = cy;
	return 1;

}

bool probaj(int k){
	int cx = mi_x + k, cy = mi_y + k;
	if(probaj_toc(cx, cy, k)) return true;
	if(probaj_toc(k + cy + mi_dig, cy, k)) return true;	
	if(probaj_toc(cx, k + cx - mi_dig, k)) return true;	
	if(probaj_toc(k + cy + mx_dig, cy, k)) return true;	
	if(probaj_toc(cx, k + cx - mx_dig, k)) return true;
	return false;	
}

int main(){
	scanf("%d", &n);
	for(int i = 0;i < n;i++){
		scanf("%s", s);
		int ln = strlen(s);
		for(int j = 0;j < ln;j++){
			x[i] += (s[j] == 'B');
			y[i] += (s[j] == 'N');
		}
		mi_x = min(mi_x, x[i]);
		mi_y = min(mi_y, y[i]);
		mx_x = max(mx_x, x[i]);
		mx_y = max(mx_y, y[i]);
		mi_dig = min(mi_dig, x[i] - y[i]);
		mx_dig = max(mx_dig, x[i] - y[i]);
	}
	int ans = -1;
	for(int i = 20;i >= 0;i--)
		if(!probaj(ans + (1 << i)))
			ans += (1 << i);
	ans++; probaj(ans);
	printf("%d\n", ans);
	for(int i = 0;i < ans_x;i++)
		printf("B");
	for(int i = 0;i < ans_y;i++)
		printf("N");
	printf("\n");
	return 0;
}
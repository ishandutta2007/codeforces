#include <cstdio>
#include <vector>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long double ld;

const int N = 1e5 + 500;

ld sol = 0;
vector < int > v[N];
int n;

void dfs(int x, int lst, int dep){
	sol += 1.0 / (ld)dep;
	for(int y : v[x]){
		if(y == lst) continue;
		dfs(y, x, dep + 1);
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i < n;i++){
		int x, y; scanf("%d%d", &x, &y);
		v[x].PB(y); v[y].PB(x);
	}
	dfs(1, 1, 1);
	printf("%.10Lf\n", sol);
	return 0;
}
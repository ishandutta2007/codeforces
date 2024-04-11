#include <cstdio>
#include <vector>
#include <algorithm>
 
#define X first
#define Y second
#define PB push_back
 
using namespace std;
 
typedef long long ll;
 
const int N = 1e5 + 500;
 
vector < int > v[N], tmp;
 
int siz[N], n, cen, dep[N], ans[N];
ll sol = 0;
 
bool cmp(int x, int y){
	return siz[x] > siz[y];
}
 
void dfs(int x, int lst){
	siz[x] = 1;
	for(int y : v[x]){
		if(y == lst) continue;
		dfs(y, x); siz[x] += siz[y];
	}
}
 
void rijesi(int x, int lst){
	sol += 2LL * dep[x];
	if(x == cen)
		sort(v[x].begin(), v[x].end(), cmp);	
	for(int y : v[x]){
		if(y == lst) continue;
		dep[y] = dep[x] + 1;
		rijesi(y, x);
	}	
	tmp.PB(x); 
}
 
int main(){
	scanf("%d", &n);
	for(int i = 1;i < n;i++){
		int x, y; scanf("%d%d", &x, &y);
		v[x].PB(y), v[y].PB(x);
	}
	dfs(1, 1);
	cen = 1;
	for(int i = 2;i <= n;i++)
		if(2 * siz[i] >= n && siz[i] < siz[cen])
			cen = i;
	dfs(cen, cen);
	rijesi(cen, cen);
	if(n & 1){
		for(int i = 1;i + (n - 3) / 2 < n - 2;i++){
			ans[tmp[i]] = tmp[i + (n - 3) / 2];				
			ans[tmp[i + (n - 3) / 2]] = tmp[i];
		}
		ans[tmp[0]] = tmp[n - 2];
		ans[tmp[n - 2]] = tmp.back();
		ans[tmp.back()] = tmp[0];
			
	}
	else{
		for(int i = 0;i + n / 2 < n;i++){
			ans[tmp[i]] = tmp[i + n / 2];
			ans[tmp[i + n / 2]] = tmp[i];
		}
	}
	printf("%lld\n", sol);
	for(int i = 1;i <= n;i++)
		printf("%d ", ans[i]);
	printf("\n"); 
	return 0;
}
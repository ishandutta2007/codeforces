#include <cstdio>
#include <set>
#include <vector>

#define PB push_back

using namespace std;

const int N = 1e5 + 500;
const int B = 300;

set < int > mali;

int A[N], dod[N / B], par[N];
int n, q;

void smanji(int l, int r, int x){
	if(r - l < 2 * B){
		for(int i = l;i <= r;i++)
			A[i] = max(A[i] - x, 1);
		return;
	}
	while(l % B != 0)
		A[l] = max(A[l] - x, 1), l++;
	while(r % B != B - 1)
		A[r] = max(A[r] - x, 1), r--;
	for(int i = l / B;i <= r / B;i++)
		dod[i] = min(dod[i] + x, N);
}

inline int get(int x){
	return max(A[x] - dod[x / B], 1);
}

void izgradi(int x){
	if(get(x) / B != x / B)
		par[x] = x;
	else
		par[x] = par[get(x)];
}

int lca(int x, int y){
	for(;par[x] != par[y];){
		if(x < y) swap(x, y);
		x = get(par[x]);
	}
	for(;x != y;){
		if(x < y) swap(x, y);
		x = get(x);
	}
	return x;
}

void popravi_male(int l, int r){
	auto it = mali.lower_bound(l);
	while(it != mali.end() && *it <= r){
		izgradi(*it);
		if(get(*it) == 1 || get(*it) / B != (*it) / B)
			it = mali.erase(it);	
		else
			it++;
	}
}


int main(){
	scanf("%d%d", &n, &q);
	for(int i = 2;i <= n;i++){
		scanf("%d", A + i);
		izgradi(i);
		if(get(i) != i)
			mali.insert(i);
	}
	for(int i = 0;i < q;i++){
		int ty; scanf("%d", &ty);
		if(ty == 1){
			int l, r, x; scanf("%d%d%d", &l, &r, &x);
			smanji(l, r, x);
			popravi_male(l, min(r + B, n));
		}
		else{
			int x, y; scanf("%d%d", &x, &y);
			printf("%d\n", lca(x, y));
		}
	}
	return 0;
}
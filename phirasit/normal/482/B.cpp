#include <stdio.h>
#include <algorithm>

#define N 100010
#define K 30

#define A first
#define B second

using namespace std;

typedef pair<int, int> pii;

int from[N], to[N], val[N];
int ans[N];

bool set[K][4*N];
pii rng[4*N];

int n, m;
bool err = false;

void init(int j, int idx, int a, int b) {
	if(a < b) {
		int mid = (a + b) / 2;
		init(j, 2*idx, a, mid);
		init(j, 2*idx+1, mid+1, b);
	}
	set[j][idx] = false;
	rng[idx] = pii(a, b);
}
void set_all(int j, int idx, int a, int b) {
	if(b < rng[idx].A || rng[idx].B < a) {
		return;
	}
	if(a <= rng[idx].A && rng[idx].B <= b) {
		set[j][idx] = true;
		return;
	}
	if(set[j][idx]) {
		return;
	}
	set_all(j, 2*idx, a, b);
	set_all(j, 2*idx+1, a, b);
	if(set[j][2*idx] == true && set[j][2*idx+1] == true) {
		set[j][idx] = true;
	}
}
bool is_all(int j, int idx, int a, int b) {
	if(b < rng[idx].A || rng[idx].B < a) {
		return true;
	}
	if(a <= rng[idx].A && rng[idx].B <= b) {
		return set[j][idx];
	}
	if(set[j][idx] == true) {
		return true;
	}
	return is_all(j, 2*idx, a, b) && is_all(j, 2*idx+1, a, b);
}
void dfs(int j, int idx) {
	if(rng[idx].A >= rng[idx].B) {
//		printf("%d[%d] ", j, set[j][idx]);
		if(set[j][idx]) {
			ans[rng[idx].A] += (1 << j);
		}
	}else {
		if(set[j][idx]) {
			set[j][2*idx] = set[j][2*idx+1] = true;
		}
		dfs(j, 2*idx);
		dfs(j, 2*idx+1);
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++) {
		ans[i] = 0;
	}
	for(int i = 0;i < K;i++) {
		init(i, 1, 1, n);
	}
	
	for(int i = 0;i < m;i++) {
		int l, r, q;
		scanf("%d%d%d", &l, &r, &q);
		
		for(int j = 0;j < K;j++) {
			if(q & (1 << j)) {
				set_all(j, 1, l, r);
			}
		}
		from[i] = l;
		to[i] = r;
		val[i] = q;
	}
	for(int i = 0;i < m;i++) {
		for(int j = 0;j < K;j++) {
			if((val[i] & (1 << j)) == 0) {
				if(is_all(j, 1, from[i], to[i]) == true) {
//					printf("%d %d %d %d\n", from[i], to[i], 1 << j, is_all(j, 1, from[i], to[i]));
					err = true;
				}
			}
		}
	}
	if(err) {
		printf("NO\n");
	}else {
		printf("YES\n");
		for(int i = 0;i < K;i++) {
			dfs(i, 1);
		}
		for(int i = 1;i <= n;i++) {
			printf("%d ", ans[i]);
		}
		printf("\n");
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

const int maxn = 1100;

int tot = 0;
int X[maxn];
int Y[maxn];
int a[maxn];
bool f[maxn];
void add(int x, int y) {
	tot++;
	X[tot] = x;
	Y[tot] = y;
}
int main() {
	//freopen("b.in","r",stdin);
	int n;
	scanf("%d", &n);
	int sum = 0;
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	
	if (a[1] == 0 || sum < n-1) {
		printf("-1\n");
		return 0;
	}
	int las = 1;
	for (int i = 2; i <= n; i++) {
		if (a[i]) {
			add(las, i);
			
			a[las]--;
			las = i;
			f[i] = true;
		}
	}
	//int now = 2;
	for (int i = 1; i <= n; i++) {
		if (a[i] == 0) continue;
		for (int j = 2; j <= n; j++) {
			if (f[j]) continue;
			add(i, j);
			a[i]--;
			f[j] = true;
			if (a[i] == 0) break;
		}
	}
	printf("%d\n", tot);
	for (int i = 1; i <= tot; i++)
		printf("%d %d\n", X[i], Y[i]);
}
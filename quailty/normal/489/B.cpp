#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<stack>
#include<queue>
using namespace std;;
int main()
{
	int n, m, i, j, a[100], b[100], pa = 0, pb = 0, tot = 0;
	scanf("%d", &n);
	for (i = 0; i <= n - 1; i++)scanf("%d", &a[i]);
	scanf("%d", &m);
	for (i = 0; i <= m - 1; i++)scanf("%d", &b[i]);
	sort(a, a + n);
	sort(b, b + m);
	while (pa < n && pb < m){
		if (a[pa] == b[pb] || a[pa] == b[pb] + 1 || a[pa] == b[pb] - 1){
			pa++;
			pb++;
			tot++;
		}
		else if (a[pa] < b[pb])pa++;
		else pb++;
	}
	printf("%d\n", tot);
	return 0;
}
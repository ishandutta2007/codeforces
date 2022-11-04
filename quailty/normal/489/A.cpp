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
#define INF 1000000007;
using namespace std;
int a[3000],p[3000],q[3000];
void swap(int &a, int &b)
{
	int temp = a; a = b; b = temp;
}
int main()
{
	int n, i, j, maximum, maxi, tot = 0;
	scanf("%d", &n);
	for (i = 0; i <= n - 1; i++){
		scanf("%d", &a[i]);
	}
	for (i = n - 1; i >= 1; i--){
		maximum = -INF;
		for (j = 0; j <= i; j++){
			maximum = max(a[j], maximum);
			if (maximum == a[j])maxi = j;
		}
		if (maxi == i)continue;
		else{
			swap(a[maxi], a[i]);
			p[tot] = maxi;
			q[tot] = i;
			tot++;
		}
	}
	printf("%d\n", tot);
	if (tot != 0){
		for (i = 0; i <= tot - 1; i++)
			printf("%d %d\n", p[i], q[i]);
	}
	return 0;
}
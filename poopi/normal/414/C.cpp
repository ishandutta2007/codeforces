										/* in the name of Allah */
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <list>
#include <map>
#include <set>

using namespace std;

#define uint unsigned int
#define int64 long long
#define P pair<int, int>
#define Pss pair<string, string>
#define PLL pair<int64, int64>
#define Inf 1000000
#define Mod 1000000007LL

int n, m, q;
int cur[30];
int64 cnt[30][2];
int64 tot[30];
int arr[2000010];
int h[2000010];

void merge(int str, int end, int lev){
	if(lev == 0)
		return;
	int mid = (str + end) / 2;
	merge(str, mid, lev - 1);
	merge(mid + 1, end, lev - 1);
	int p = str, q = mid + 1;
	int idx = str;
	while(p <= mid && q <= end){
		if(arr[p] <= arr[q])
			h[idx++] = arr[p++];
		else{
			h[idx++] = arr[q++];
			cnt[lev][0] += mid - p + 1;
		}
	}
	while(p <= mid)
		h[idx++] = arr[p++];
	while(q <= end)
		h[idx++] = arr[q++];
	int same = 0;
	for(int i = str; i <= end; i++){
		arr[i] = h[i];
		if(i != str && arr[i] == arr[i - 1])
			same++;
		else same = 0;
		tot[lev] += i - str - same;
	}
}

int main(){
	cin >> n;
	for(int i = 0; i < (1 << n); i++)
		scanf("%d", &arr[i]);
	merge(0, (1 << n) - 1, n);
	for(int i = 1; i <= n; i++)
		for(int j = 0; j < i; j++)
			tot[i] -= tot[j];
	for(int i = 1; i <= n; i++)
		cnt[i][1] = tot[i] - cnt[i][0];
	cin >> m;
	for(int i = 0; i < m; i++){
		scanf("%d", &q);
		for(int j = 1; j <= q; j++)
			cur[j] = 1 - cur[j];
		int64 res = 0;
		for(int j = 1; j <= n; j++)
			res += cnt[j][cur[j]];
		printf("%I64d\n", res);
	}
	return 0;
}
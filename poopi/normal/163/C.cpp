										/* in the name of Allah */
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

#define int64 long long
#define P pair<double, int>

int n;
double l, v1, v2, tot;
P arr[200010];
double prob[100010];

double norm(double val){
	if(val < 1e-10)
		val += tot;
	if(val > tot - 1e-10)
		val -= tot;
	return val;
}

int main(){
	cin >> n >> l >> v1 >> v2;
	tot = 2 * l / v1;
	int x, sz = 1, cnt = 0;
	arr[0] = P(0, 0);
	for(int i = 0; i < n; i++){
		scanf("%d", &x);
		double t1 = (2 * l - x) / v1;
		arr[sz++] = P(norm(t1), 1);
		double t2 = (l - x) / v1 - l / (v1 + v2);
		arr[sz++] = P(norm(t2), -1);
		if(x <= l && x > 0 && l / (v1 + v2) - 1e-10 < (l - x) / v1)
			cnt++;
	}
	arr[sz++] = P(tot, 0);
	sort(arr + 1, arr + sz - 1);
	for(int i = 1; i < sz; i++){
		prob[cnt] += (arr[i].first - arr[i - 1].first) / tot;
		cnt += arr[i].second;
	}
	for(int i = 0; i <= n; i++)
		printf("%.10lf\n", prob[i]);
	return 0;
}
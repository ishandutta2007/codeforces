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

int n;
int l[10], r[10];
double lsq[10][10010];

double grq(int idx, int val){
	if(val <= l[idx])
		return 1;
	return (double)max(0, r[idx] - val + 1) / (r[idx] - l[idx] + 1);
}

double ls(int idx, int val){
	if(val > r[idx])
		return 1;
	return (double)max(0, val - l[idx]) / (r[idx] - l[idx] + 1);
}

double eq(int idx, int val){
	if(val < l[idx] || val > r[idx])
		return 0;
	return 1. / (r[idx] - l[idx] + 1);
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> l[i] >> r[i];

	for(int i = 0; i <= 10000; i++){
		for(int j = 0; j <= n; j++){
			lsq[j][i] = 1;
			for(int k = 0; k < n; k++){
				if(k == j) continue;
				if(i <= r[k])
					lsq[j][i] *= (double)max(0, i - l[k] + 1) / (r[k] - l[k] + 1);
			}
		}
	}
	
	double res = 0;
	for(int i = 1; i <= 10000; i++){
		for(int j = 0; j < (1 << n); j++){
			double p = 1;
			int cnt = 0;
			for(int k = 0; k < n; k++){
				if(j & (1 << k)){
					p *= eq(k, i);
					cnt++;
				}
				else p *= ls(k, i);
			}
			if(cnt > 1)
				res += p * i;
		}
		double p = 0;
		for(int k = 0; k < n; k++)
			p += grq(k, i + 1) * (lsq[k][i] - lsq[k][i - 1]);
		res += i * p;
	}
	cout << setprecision(9) << fixed << res << endl;
	return 0;
}
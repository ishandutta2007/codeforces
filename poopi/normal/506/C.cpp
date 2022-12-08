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

int n, m, k, p;
int64 h[100010];
int64 a[100010];
int64 tot[100010];
int64 need[100010];
int64 cnt[5010];

bool can(int64 mx){
	int64 sum = 0;
	for(int i = 0; i < n; i++){
		need[i] = max(0LL, (tot[i] - mx + p - 1) / p);
		sum += need[i];
	}
	if(sum > m * k)
		return false;
	memset(cnt, 0, sizeof cnt);
	for(int i = 0; i < n; i++){
		int64 ini = h[i] + need[i] * p - (tot[i] - mx);
		int64 last = 0;
		for(int j = 0; j < need[i]; j++){
			int64 more = max(0LL, (p - ini + a[i] - 1) / a[i]);
			last += more;
			ini += more * a[i] - p;
			if(last >= m)
				return false;
			cnt[last]++;
		}
	}
	
	int64 tot = 0;
	for(int i = m - 1; i >= 0; i--){
		tot += cnt[i];
		if(tot > k * (m - i))
			return false;
	}
	return true;
}

int main(){
	int64 mx = 0;
	cin >> n >> m >> k >> p;
	for(int i = 0; i < n; i++){
		cin >> h[i] >> a[i];
		tot[i] = h[i] + a[i] * m;
		mx = max(mx, tot[i]);
	}
	int64 l = 0, r = mx;
	while(l < r){
		int64 mid = (l + r) / 2;
		if(can(mid))
			r = mid;
		else l = mid + 1;
	}
	cout << r << endl;
	return 0;
}
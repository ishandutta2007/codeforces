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

int h, w, n;
int r[2010], c[2010];
int64 fact[200010];
int64 rfact[200010];
int64 dp[2010];
vector <P> v;

int64 modP(int64 x, int64 y){
	int64 ret = 1;
	while(y){
		if(y % 2)
			ret = (ret * x) % Mod;
		x = (x * x) % Mod;
		y /= 2;
	}
	return ret;
}

int64 cnt(int64 a, int64 b){
	int64 ret = (fact[b] * rfact[a]) % Mod;
	ret = (ret * rfact[b - a]) % Mod;
	return ret;
}

int main(){
	fact[0] = 1;
	rfact[0] = 1;
	for(int i = 1; i < 200010; i++){
		fact[i] = (fact[i - 1] * i) % Mod;
		rfact[i] = (rfact[i - 1] * modP(i, Mod - 2)) % Mod;
	}

	cin >> h >> w >> n;
	for(int i = 0; i < n; i++){
		cin >> r[i] >> c[i];
		v.push_back(P(r[i], c[i]));
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < n; i++)
		r[i] = v[i].first, c[i] = v[i].second;
	r[n] = h, c[n] = w;

	for(int idx = 0; idx <= n; idx++){
		dp[idx] = cnt(r[idx] - 1, r[idx] + c[idx] - 2);
		for(int i = 0; i < idx; i++)
			if(r[i] <= r[idx] && c[i] <= c[idx])
				dp[idx] = (dp[idx] - dp[i] * cnt(r[idx] - r[i], r[idx] - r[i] + c[idx] - c[i])) % Mod;
		dp[idx] = (dp[idx] + Mod) % Mod;
	}
	cout << dp[n] << endl;
	return 0;
}
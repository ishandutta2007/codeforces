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
int v[5], p[5];
int cnt[5], add[5];

int getMaxScr(int acc, int tot){
	int MaxScr;
	for(int i = 0; i < 6; i++){
		int t = 1 << i;
		if(tot >= t * acc)
			MaxScr = (i + 1) * 500;
	}
	return MaxScr;
}

bool ok(int m){
	int vScr = 0, pScr = 0;
	for(int i = 0; i < 5; i++){
		int MaxScr = getMaxScr(cnt[i] + m * add[i], n + m);
		if(v[i] != -1)
			vScr += MaxScr / 250 * (250 - v[i]);
		if(p[i] != -1)
			pScr += MaxScr / 250 * (250 - p[i]);
	}
	return vScr > pScr;
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 5; j++){
			int t;
			cin >> t;
			if(i == 0)
				v[j] = t;
			if(i == 1)
				p[j] = t;
			if(t != -1)
				cnt[j]++;
		}
	}
	for(int i = 0; i < 5; i++)
		if(v[i] != -1 && p[i] != -1 && p[i] < v[i])
			add[i] = 1;

	int ans = 0;
	while(!ok(ans) && ans < 100000)
		ans++;
	cout << (ans == 100000 ? -1 : ans) << endl;
	return 0;
}
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


int n, m;
int l[100010], r[100010], q[100010];
int cnt[100010];
int zero[100010];
int res[100010];

int main(){
	cin >> n >> m;
	for(int i = 0; i < m; i++)
		cin >> l[i] >> r[i] >> q[i];

	bool can = true;
	for(int d = 0; d < 30; d++){
		memset(cnt, 0, sizeof cnt);
		memset(zero, 0, sizeof zero);

		for(int i = 0; i < m; i++){
			if(q[i] & (1 << d)){
				cnt[l[i]]++;
				cnt[r[i] + 1]--;
			}
		}

		int cur = 0;
		for(int i = 1; i <= n; i++){
			cur += cnt[i];
			zero[i] = zero[i - 1];
			if(cur > 0)
				res[i] |= (1 << d);
			else zero[i]++;
		}

		for(int i = 0; i < m; i++)
			if((q[i] & (1 << d)) == 0 && zero[r[i]] == zero[l[i] - 1])
				can = false;
	}
	if(can){
		cout << "YES" << endl;
		for(int i = 1; i <= n; i++)
			cout << res[i] << ' ';
		cout << endl;
	}
	else cout << "NO" << endl;
	return 0;
}
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
#define P pair<int, int>

int n, cnt[5];

int main(){
	cin >> n;
	int a;
	for(int i = 0; i < n; i++){
		scanf("%d", &a);
		cnt[a]++;
	}
	int res = cnt[4] + cnt[3] + (cnt[2] + 1) / 2;
	cnt[1] -= min(cnt[1], cnt[3]);
	if(cnt[2] % 2)
		cnt[1] -= min(cnt[1], 2);
	res += (cnt[1] + 3) / 4;
	cout << res << endl;
	return 0;
}
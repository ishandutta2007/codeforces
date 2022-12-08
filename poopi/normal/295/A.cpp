										/* in the name of Allah */

#include <algorithm>
#include <iostream>
#include <memory.h>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <list>
#include <map>

using namespace std;

#define int64 long long
#define P pair<int, double>

int n, m, k;
int64 arr[100010];
int64 c1[100010], c2[100010];
int l[100010], r[100010];
int64 d[100010];

int main(){
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	for(int i = 0; i < m; i++){
		cin >> l[i] >> r[i] >> d[i];
		l[i]--, r[i]--;
	}
	int x, y;
	for(int i = 0; i < k; i++){
		cin >> x >> y;
		x--, y--;
		c1[x]++, c1[y + 1]--;
	}
	int64 cnt = 0;
	for(int i = 0; i < m; i++){
		cnt += c1[i];
		c2[l[i]] += cnt * d[i];
		c2[r[i] + 1] -= cnt * d[i];
	}
	cnt = 0;
	for(int i = 0; i < n; i++){
		cnt += c2[i];
		cout << arr[i] + cnt << ' ';
	}
	cout << endl;
	return 0;
}
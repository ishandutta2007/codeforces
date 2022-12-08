										/* in the name of Allah */
#include <iostream>
#include <fstream>
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

int n, k;
int d[2010];
int s[2010];

int main(){
	int T;
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> d[i];
	for(int i = 0; i < n; i++)
		cin >> s[i];
	int tot = 0, res = 0, mx = 0;
	for(int i = 0; i < n; i++){
		tot += s[i];
		mx = max(mx, s[i]);
		if(tot < d[i]){
			int diff = d[i] - tot;
			int tmp = (diff + mx - 1) / mx;
			res += k * tmp;
			tot += mx * tmp;
		}
		tot -= d[i];
		res += d[i];
	}
	cout << res << endl;
	return 0;
}
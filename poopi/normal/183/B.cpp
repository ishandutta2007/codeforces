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

int n, m;
int64 x[300], y[300];
int mx[1000010];

int main(){
	cin >> n >> m;
	for(int i = 0; i < m; i++)
		cin >> x[i] >> y[i];
	for(int i = 1; i <= n; i++)
		mx[i] = 1;
	for(int i = 0; i < m; i++){
		for(int j = i + 1; j < m; j++){
			int64 dx1 = x[i] - x[j];
			int64 dy1 = y[i] - y[j];
			int cnt = 0;
			for(int k = 0; k < m; k++){
				int64 dx2 = x[i] - x[k];
				int64 dy2 = y[i] - y[k];
				if(dx1 * dy2 == dx2 * dy1)
					cnt++;
			}
			if(y[i] == y[j])
				continue;
			if(x[i] > 0 && x[i] <= n && x[i] == x[j]){
				mx[x[i]] = max(mx[x[i]], cnt);
				continue;
			}
			int64 xr = -y[i] * dx1 / dy1;
			int64 nx = x[i] + xr;
			if(nx <= n && nx > 0 && xr * dy1 == -y[i] * dx1)
				mx[nx] = max(mx[nx], cnt);
		}
	}
	int sum = 0;
	for(int i = 1; i <= n; i++)
		sum += mx[i];
	cout << sum << endl;
	return 0;
}
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
#define Max 110000

bool np[Max];
int dif[Max];
int r[510], c[510];
int mat[510][510];

void find_prime(){
	np[1] = true;
	for(int i = 2; i < Max; i++)
		if(!np[i])
			for(int j = i + i; j < Max; j += i)
				np[j] = true;
}

int main(){
	find_prime();
	dif[Max - 1] = Max - 1;
	for(int i = Max - 2; i >= 1; i--){
		if(!np[i])
			dif[i] = 0;
		else dif[i] = dif[i + 1] + 1;
	}
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> mat[i][j];
			int tmp = dif[mat[i][j]];
			r[i] += tmp;
			c[j] += tmp;
		}
	}
	int res = r[0];
	for(int i = 0; i < n; i++)
		res = min(res, r[i]);
	for(int i = 0; i < m; i++)
		res = min(res, c[i]);
	cout << res << endl;
	return 0;
}
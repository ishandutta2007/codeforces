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

int r, c, k;
int a, b;
char mat[200][200];
int xc[30], yc[30];
vector <int> x, y;

int ABS(int num){
	return (num < 0 ? -num : num);
}

int main(){
	x.clear();
	y.clear();
	cin >> r >> c >> k;
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cin >> mat[i][j];
			if(mat[i][j] >= 'a' && mat[i][j] <= 'z')
				xc[mat[i][j] - 'a'] = i, yc[mat[i][j] - 'a'] = j;
		}
	}
	cin >> a >> b;
	a--, b--;
	string str;
	cin >> str;
	for(int i = 0; i < str.length(); i++){
		x.push_back(xc[str[i] - 'a']);
		y.push_back(yc[str[i] - 'a']);
	}
	int t1, t2;
	cin >> t1 >> t2;
	t1--, t2--;
	x.push_back(t1);
	y.push_back(t2);
	int p = 0, tot = mat[a][b] - '0';
	while(p < x.size() && tot <= k){
		if(a != x[p])
			a += (x[p] - a) / ABS(x[p] - a);
		if(b != y[p])
			b += (y[p] - b) / ABS(y[p] - b);
		if(a == x[p] && b == y[p])
			tot++, p++;
		else tot += mat[a][b] - '0';
	}
	cout << a + 1 << ' ' << b + 1 << endl;
	return 0;
}
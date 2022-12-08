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
#define Max 1000010
int n, c;
int l[Max], r[Max], e[Max];
bool mark[Max];

void print(int idx){
	for(int i = idx + 1; i <= l[idx]; ){
		print(i);
		i = e[i] + 1;
	}
	cout << idx + 1 << ' ';
	for(int i = l[idx] + 1; i <= e[idx]; ){
		print(i);
		i = e[i] + 1;
	}
}

int main(){
	cin >> n >> c;
	int a, b;
	string str;
	for(int i = 0; i < n; i++){
		e[i] = l[i] = i;
		r[i] = n;
	}
	for(int i = 0; i < c; i++){
		cin >> a >> b >> str;
		a--, b--;
		if(a >= b){
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}
		if(str[0] == 'L')
			l[a] = max(l[a], b);
		else r[a] = min(r[a], b);
		e[a] = max(e[a], b);
	}

	for(int idx = n - 1; idx >= 0; idx--){

		for(int i = idx + 1; i <= l[idx]; ){
			l[idx] = max(l[idx], e[i]);
			i = e[i] + 1;
		}

		e[idx] = max(e[idx], l[idx]);

		for(int i = l[idx] + 1; i <= e[idx]; ){
			e[idx] = max(e[idx], e[i]);
			i = e[i] + 1;
		}

		if(r[idx] <= l[idx]){
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}
	}
	memset(mark, false, sizeof mark);
	e[0] = n - 1;
	print(0);
	cout << endl;
	return 0;
}
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

int n, in[400];
int pr[400][400];
bool mark[400];

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &pr[i][j]);
			pr[i][j]--;
		}
	}
	for(int i = 0; i < n; i++){
		cin >> in[i];
		in[i]--;
	}
	for(int i = 0; i < n; i++){
		memset(mark, false, sizeof mark);
		int mn = n + 1;
		for(int j = 0; j < n; j++){
			if(in[j] == i){
				mark[in[j]] = true;
				continue;
			}
			if(mn < in[j])
				mark[in[j]] = true;
			mn = min(mn, in[j]);
		}
		int idx = 0;
		while(idx < n && mark[pr[i][idx]])
			idx++;
		if(i > 0)
			cout << ' ';
		cout << pr[i][idx] + 1;
	}
	cout << endl;
	return 0;
}
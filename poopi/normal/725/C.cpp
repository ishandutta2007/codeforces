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

string str;
int ref[300];
char ans[2][26];

int main(){
	cin >> str;
	int a, b;
	memset(ref, -1, sizeof ref);
	for(int i = 0; i < str.length(); i++){
		if(ref[str[i]] != -1){
			a = ref[str[i]];
			b = i;
		}
		ref[str[i]] = i;
	}
	if(b == a + 1){
		cout << "Impossible" << endl;
		return 0;
	}

	int len = b - a - 1;
	ans[0][len / 2] = str[a];
	int r = 0, c = len / 2;
	for(int i = a + 1; i < b; i++){
		if(r == 0){
			c--;
			if(c < 0){
				c = 0;
				r = 1;
			}
		}
		else c++;
		ans[r][c] = str[i];
	}

	str = str.substr(b + 1) + str.substr(0, a);
	r = 0, c = len / 2;
	for(int i = 0; i < str.length(); i++){
		if(r == 0){
			c++;
			if(c > 12){
				c = 12;
				r = 1;
			}
		}
		else c--;
		ans[r][c] = str[i];
	}

	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 13; j++)
			cout << ans[i][j];
		cout << endl;
	}
	return 0;
}
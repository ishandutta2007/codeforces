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

int n;
int mat[110][110];
int cnt[110];
int ig[110];
bool mark[110];

int main(){
	cin >> n;
	char ch;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> ch;
			mat[i][j] = ch - '0';
			cnt[j] += mat[i][j];
		}
	}
	for(int i = 0; i < n; i++)
		cin >> ig[i];

	int rem = n;
	for(int I = 0; I < n; I++){
		for(int i = 0; i < n; i++){
			if(!mark[i] && cnt[i] == ig[i]){
				rem--;
				mark[i] = true;
				for(int j = 0; j < n; j++)
					cnt[j] -= mat[i][j];
				break;
			}
		}
	}
	cout << rem << endl;
	for(int i = 0; i < n; i++)
		if(!mark[i])
			cout << i + 1 << ' ';
	cout << endl;
	return 0;
}
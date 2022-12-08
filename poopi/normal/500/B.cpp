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
int arr[500];
bool mark[500];
bool mat[500][500];
vector <int> num, idx;

void dfs(int x){
	idx.push_back(x);
	num.push_back(arr[x]);
	mark[x] = true;
	for(int i = 0; i < n; i++)
		if(mat[x][i] && !mark[i])
			dfs(i);
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			char ch;
			cin >> ch;
			mat[i][j] = (ch == '1');
		}
	}
	for(int i = 0; i < n; i++){
		if(!mark[i]){
			num.clear();
			idx.clear();
			dfs(i);
			sort(idx.begin(), idx.end());
			sort(num.begin(), num.end());
			for(int j = 0; j < num.size(); j++)
				arr[idx[j]] = num[j];
		}
	}
	for(int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	cout << endl;
	return 0;
}
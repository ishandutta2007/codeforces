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

int n, m, sz;
bool mark[1010];
int w[1010];
int ord[1010];

int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> w[i];
	int idx, res = 0;
	for(int i = 0; i < m; i++){
		cin >> idx;
		idx--;
		if(!mark[idx]){
			mark[idx] = true;
			ord[sz++] = idx;
		}
		int p = 0;
		while(ord[p] != idx){
			res += w[ord[p]];
			p++;
		}
		for(int j = p; j > 0; j--)
			swap(ord[j], ord[j - 1]);
	}
	cout << res << endl;
	return 0;
}
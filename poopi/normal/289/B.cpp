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

ifstream fin("input.txt");
ofstream fout("output.txt");

#define uint unsigned int
#define int64 long long
#define P pair<int, int>
#define Pss pair<string, string>
#define PLL pair<int64, int64>
//#define cin fin
//#define cout fout

int n, m, d;
int mat[110][110];
int cnt[10010];

int main(){
	cin >> n >> m >> d;
	bool fl = true;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> mat[i][j];
			if(mat[i][j] % d != mat[0][0] % d)
				fl = false;
		}
	}
	if(!fl){
		cout << -1 << endl;
		return 0;
	}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cnt[mat[i][j] / d]++;
	int res = 0, tot = 0;
	for(int i = 0; i <= 10000; i++){
		res += cnt[i] * i;
		tot += cnt[i];
	}
	int past = cnt[0], cur = res;
	for(int i = 1; i <= 10000; i++){
		cur += 2 * past - tot;
		res = min(res, cur);
		past += cnt[i];
	}
	cout << res << endl;
    return 0;
}
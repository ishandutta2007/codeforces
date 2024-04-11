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

int n, m;
bool mark[3000];
bool mat[3000][3000];
int lf[3000], rt[3000];

bool match(int idx){
	for(int i = 0; i < m; i++){
		if(mat[idx][i] && !mark[i]){
			mark[i] = true;
			if(lf[i] == -1 || match(lf[i])){
				rt[idx] = i;
				lf[i] = idx;
				return true;
			}
		}
	}
	return false;
}

int x, y;
int good[110][110];
vector <P> v;

int main(){
	cin >> x >> y;
	int tmp;
	for(int i = 0; i < x; i++){
		cin >> tmp;
		for(int j = 2; j * j <= tmp; j++){
			while(tmp % j == 0){
				v.push_back(P(j, i));
				tmp /= j;
			}
		}
		if(tmp > 1)
			v.push_back(P(tmp, i));
	}

	int a, b;
	for(int i = 0; i < y; i++){
		cin >> a >> b;
		a--, b--;
		good[a][b] = good[b][a] = true;
	}

	n = m = v.size();
	for(int i = 0; i < v.size(); i++){
		if(v[i].second % 2)
			continue;
		for(int j = 0; j < v.size(); j++){
			if(v[i].first == v[j].first && good[v[i].second][v[j].second])
				mat[i][j] = true;
		}
	}
    int cnt = 0;
	memset(lf, -1, sizeof lf);
    memset(rt, -1, sizeof rt);
    for( int i = 0; i < n; i++ ){
        memset( mark, false, sizeof mark);
        if(match(i)) cnt++;
    }
	cout << cnt << endl;
	return 0;
}
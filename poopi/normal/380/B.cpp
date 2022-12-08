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

struct triple{
	int lf, rt, x;
	triple(){}
	triple(int l, int r, int _x){
		lf = l, rt = r, x = _x;
	}
};

int n, m;
int lef[200010];
int righ[200010];
vector <triple> v[7010];


int main(){
	int pnt = 0;
	for(int i = 1; i < 200000; i++){
		lef[i] = righ[i] = i + pnt;
		if((i & (i - 1)) == 0){
			pnt++;
			righ[i]++;
		}
	}

	cin >> n >> m;
	int md, lev, lf, rt, x;
	for(int i = 0; i < m; i++){
		cin >> md >> lev;
		if(md == 1){
			cin >> lf >> rt >> x;
			v[lev].push_back(triple(lf, rt, x));
		}
		else{
			set <int> st;
			cin >> lf;
			rt = lf;
			for(int i = lev; i <= n; i++){
				for(int j = 0; j < v[i].size(); j++)
					if(lf <= v[i][j].rt && v[i][j].lf <= rt)
						st.insert(v[i][j].x);
				lf = lef[lf];
				rt = righ[rt];
			}
			cout << st.size() << endl;
		}
	}
	return 0;
}
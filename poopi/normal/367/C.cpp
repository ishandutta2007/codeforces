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
vector <int> v;

int main(){
	cin >> n >> m;
	int a, b;
	for(int i = 0; i < m; i++){	
		cin >> a >> b;
		v.push_back(b);
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	int64 tot = 1, pnt = 0;
	int64 res = 0;
	while(tot <= n && pnt < m){
		res += v[pnt++];
		tot = pnt * (pnt + 1) / 2 + 1;
		if(pnt % 2 == 1)
			tot += (pnt - 1) / 2;
	}
	cout << res << endl;
	return 0;
}
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
vector <P> v;

int main(){
	cin >> n;
	int a, b;
	for(int i = 0; i < n; i++){
		cin >> a >> b;
		v.push_back(P(a, b));
	}
	sort(v.begin(), v.end());
	int bef = 0;
	for(int i = 0; i < n; i++){
		if(bef <= v[i].second)
			bef = v[i].second;
		else bef = v[i].first;
	}
	cout << bef << endl;
	return 0;
}
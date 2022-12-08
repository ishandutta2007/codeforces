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

int n, t1, t2, k;
vector <P> v;

bool cmp(P a, P b){
	if(a.first != b.first)
		return a.first > b.first;
	return a.second < b.second;
}

int main(){
	cin >> n >> t1 >> t2 >> k;
	t1 *= (100 - k);
	t2 *= 100;
	if(t1 > t2)
		swap(t1, t2);
	int a, b;
	for(int i = 0; i < n; i++){
		cin >> a >> b;
		if(a > b) swap(a, b);
		v.push_back(P(t1 * a + t2 * b, i + 1));
	}
	sort(v.begin(), v.end(), cmp);
	for(int i = 0; i < n; i++)
		printf("%d %d.%02d\n", v[i].second, v[i].first / 100, v[i].first % 100);
	return 0;
}
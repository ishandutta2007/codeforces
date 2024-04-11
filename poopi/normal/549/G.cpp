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
P arr[200010];

bool cmp(P a, P b){
	return a.first + a.second < b.first + b.second;
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i].first;
		arr[i].second = i;
	}

	sort(arr, arr + n, cmp);
	bool can = true;
	for(int i = 0; i + 1 < n; i++)
		if(arr[i].first + arr[i].second == arr[i + 1].first + arr[i + 1].second)
			can = false;

	if(can){
		for(int i = 0; i < n; i++)
			cout << arr[i].first + arr[i].second - i << ' ';
		cout << endl;
	}
	else cout << ":(" << endl;
	return 0;
}
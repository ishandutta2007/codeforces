										/* in the name of Allah */
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

#define int64 long long
#define P pair<int, int>

int n;
P arr[100010];
int a[100010];
int k[100010];

int main(){
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;
	sort(arr, arr + n);
	for(int i = 0; i < n; i++){
		a[i] = arr[i].second;
		k[i] = arr[i].first;
	}
	for(int i = 0; i < n - 1; i++){
		if(k[i + 1] - k[i] >= 30)
			continue;
		for(int j = k[i]; j < k[i + 1]; j++)
			a[i] = (a[i] + 3) / 4;
		a[i + 1] = max(a[i + 1], a[i]);
	}
	int res = k[n - 1];
	if(a[n - 1] == 1)
		cout << res + 1 << endl;
	else{
		while(a[n - 1] > 1){
			res++;
			a[n - 1] = (a[n - 1] + 3) / 4;
		}
		cout << res << endl;
	}
	return 0;
}
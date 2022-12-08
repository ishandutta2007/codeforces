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

int n, d;
int arr[100010];

int main(){
	cin >> n >> d;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	long long res = 0;
	int st = 0, end = 0;
	while(st < n){
		while(end < n && arr[end] - arr[st] <= d)
			end++;
		long long tot = end - st - 1;
		res += max(0LL, tot * (tot - 1) / 2);
		st++;
	}
	cout << res << endl;
	return 0;
}
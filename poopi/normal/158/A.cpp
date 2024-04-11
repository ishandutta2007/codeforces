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

int n, k;
int arr[60];

int main(){
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	reverse(arr, arr + n);
	int p = 0;
	while(p < n && arr[p] > 0 && (p < k || arr[p] == arr[p - 1]))
		p++;
	cout << p << endl;
	return 0;
}
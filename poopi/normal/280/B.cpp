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

int n, res;
int arr[100010];
int ds[100010];

void func(){
	int pnt = 0;
	ds[0] = arr[0];
	for(int i = 1; i < n; i++){
		res = max(res, ds[pnt] ^ arr[i]);
		ds[++pnt] = arr[i];
		while(pnt > 0 && ds[pnt] > ds[pnt - 1]){
			ds[pnt - 1] = ds[pnt];
			pnt--;
			if(pnt > 0)
				res = max(res, ds[pnt] ^ ds[pnt - 1]);
		}
	}
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	func();
	reverse(arr, arr + n);
	func();
	cout << res << endl;
	return 0;
}
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
int arr[1000010];

int main(){
	cin >> n >> k;
	if(n < 3 * k){
		cout << -1 << endl;
		return 0;
	}
	bool f = false;
	if(k % 2){
		k--;
		n -= 3;
		f = true;
	}
	for(int i = 0; i < k; i++){
		int j = i / 2;
		if(i % 2)
			arr[6 * j + 2] = arr[6 * j + 4] = arr[6 * j + 5] = i;
		else arr[6 * j] = arr[6 * j + 1] = arr[6 * j + 3] = i;
	}
	if(f)
		cout << k + 1 << ' ' << k + 1 << ' ';
	for(int i = 0; i < n; i++){
		cout << arr[i] + 1;
		if(i < n - 1)
			cout << ' ';
	}
	if(f) cout << ' ' << k + 1;
	cout << endl;
	return 0;
}
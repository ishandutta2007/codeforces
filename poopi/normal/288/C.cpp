										/* in the name of Allah */

#include <algorithm>
#include <iostream>
#include <memory.h>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <list>
#include <map>

using namespace std;

#define int64 long long
#define P pair<int, double>

int arr[1000010];

void calc(int n){
	if(n < 0) return;
	if(n == 0){
		arr[0] = 0;
		return;
	}
	if(n == 1){
		arr[0] = 1;
		arr[1] = 0;
		return;
	}
	int t = 1;
	while(2 * t <= n)
		t *= 2;
	for(int i = 0; t + i <= n; i++){
		arr[t + i] = t - i - 1;
		arr[t - i - 1] = t + i;
	}
	calc(2 * t - n - 2);
}

int main(){
	int n;
	cin >> n;
	calc(n);
	cout << (int64)n * (n + 1) << endl;
	for(int i = 0; i <= n; i++)
		cout << arr[i] << ' ';
	cout << endl;
	return 0;
}
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
int arr[20010];

int main(){
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	int mx = -1000000000;
	for(int i = 1; i <= n; i++){
		if(n % i || n / i < 3) continue;
		for(int s = 0; s < i; s++){
			int sum = 0;
			for(int e = s; e < n; e += i)
				sum += arr[e];
			mx = max(mx, sum);
		}
	}
	cout << mx << endl;
	return 0;
}
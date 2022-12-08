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

int64 n, sum;
int64 arr[100010];

int64 gcd(int64 a, int64 b){
	return (b == 0 ? a : gcd(b, a % b));
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	for(int i = 0; i < n; i++){
		sum += arr[i];
		if(i != 0)
			sum += 2 * (arr[i] - arr[i - 1]) * i * (n - i);
	}
	int64 d = gcd(sum, n);
	sum /= d;
	n /= d;
	cout << sum << ' ' << n << endl;
	return 0;
}
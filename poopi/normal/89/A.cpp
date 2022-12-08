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
int64 m, k;
int arr[10001];

int main(){
	while(cin >> n >> m >> k){
		int64 mn = 1000000;
		for(int i = 0; i < n; i++){
			cin >> arr[i];
			if(i % 2 == 0)
				mn = min(mn, (int64)arr[i]);
		}
		if(n % 2 == 0){
			cout << 0 << endl;
			continue;
		}
		int64 tmp = k * (m / (n / 2 + 1));
		cout << min(tmp, mn) << endl;
	}
	return 0;
}
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

int n, k;
int arr[10010];

int main(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		arr[i] = (i < n ? 1 : 0);
	for(int i = 0; i < k; i++){
		for(int j = 1; j <= n; j++){
			int tmp = j;
			if(n - j - arr[j] < arr[j])
				tmp += arr[j];
			cout << tmp << ' ';
			arr[j] += arr[tmp];
		}
		cout << endl;
	}
	return 0;
}
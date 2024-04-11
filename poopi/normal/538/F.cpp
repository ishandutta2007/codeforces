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

int n;
int arr[200010];
int sum[200010];

int main(){
	cin >> n;
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	for(int i = 1; i < n; i++){
		int k = 1;
		while(k < i){
			int p = (i - 1) / k;
			int nk = (i - 1) / p + 1;
			if(arr[i] < arr[p])
				sum[k]++, sum[nk]--;
			k = nk;
		}
		if(arr[i] < arr[0])
			sum[i]++;
	}
	int ans = 0;
	for(int i = 1; i < n; i++){
		ans += sum[i];
		printf("%d ", ans);
	}
	cout << endl;
	return 0;
}
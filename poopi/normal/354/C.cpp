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
#define Max 1000000
#define Mod 1000000007LL

int n, k;
int arr[300010];
int nex[1000010];

int main(){
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);
	if(arr[0] <= k){
		cout << arr[0] << endl;
		return 0;
	}
	memset(nex, -1, sizeof nex);
	for(int i = 0; i < n; i++)
		nex[arr[i] - k - 1] = i;
	nex[Max] = n;
	for(int i = Max - 1; i > 0; i--)
		if(nex[i] == -1)
			nex[i] = nex[i + 1];

	bool can = false;
	int res = arr[0] + 1;
	while(!can){
		res--;
		can = true;
		int idx = 0, num = 0;
		while(can && idx < n){
			num += res;
			if(num > arr[idx])
				can = false;
			idx = nex[num];
		}
	}
	cout << res << endl;
	return 0;
}
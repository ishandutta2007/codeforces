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
int arr[100001];
int res[100001];
int tmp[100001];
int idx[100001];

int main(){
	while(cin >> n){
		for(int i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		res[n - 1] = -1;
		tmp[0] = arr[n - 1];
		idx[0] = n - 1;
		int sz = 1;
		for(int i = n - 2; i >= 0; i--){
			if(arr[i] > tmp[sz - 1]){
				int l = 0, r = sz - 1;
				while(l < r){
					int mid = (l + r) / 2;
					if(tmp[mid] >= arr[i])
						l = mid + 1;
					else r = mid;
				}
				res[i] = idx[l] - i - 1;
			}
			else{
				res[i] = -1;
				if(arr[i] < tmp[sz - 1]){
					tmp[sz] = arr[i];
					idx[sz++] = i;
				}
			}
		}
		for(int i = 0; i < n; i++){
			if(i > 0)
				printf(" ");
			printf("%d", res[i]);
		}
		printf("\n");
	}
	return 0;
}
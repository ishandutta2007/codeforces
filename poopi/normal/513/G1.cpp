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

int n, k;
int arr[10];
int cnt = 0, sum = 0;

void bt(int rem){
	if(rem == 0){
		cnt++;
		for(int i = 0; i < n; i++)
			for(int j = i + 1; j < n; j++)
				if(arr[i] > arr[j])
					sum++;
	}
	else{
		for(int i = 0; i < n; i++){
			for(int j = i; j < n; j++){
				reverse(arr + i, arr + j + 1);
				bt(rem - 1);
				reverse(arr + i, arr + j + 1);
			}
		}
	}
}

int main(){
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	bt(k);
	cout << setprecision(9) << fixed << (double)sum / cnt << endl;
	return 0;
}
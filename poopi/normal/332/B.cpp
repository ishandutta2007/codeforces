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

ifstream fin("input.txt");
ofstream fout("output.txt");

#define uint unsigned int
#define int64 long long
#define P pair<int, int>
#define Pss pair<string, string>
#define PLL pair<int64, int64>
#define Inf 1000000
#define Mod 1000000007LL
//#define cin fin
//#define cout fout

int n, k;
int64 arr[200010];
int64 sum[200010];
int64 mx[200010];
int64 idx[200010];

int main(){
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	int64 res = 0;
	int A, B;
	sum[n - 1] = arr[n - 1];
	for(int i = 2; i <= k; i++)
		sum[n - i] = arr[n - i] + sum[n - i + 1];
	idx[n - k] = n - k;
	mx[n - k] = sum[n - k];
	for(int i = n - k - 1; i >= 0; i--){
		sum[i] = arr[i] + sum[i + 1] - arr[i + k];
		if(res <= mx[i + k] + sum[i]){
			res = mx[i + k] + sum[i];
			A = i + 1, B = idx[i + k] + 1;
		}
		res = max(res, mx[i + k] + sum[i]);
		if(sum[i] >= mx[i + 1]){
			mx[i] = sum[i];
			idx[i] = i;
		}
		else{
			mx[i] = mx[i + 1];
			idx[i] = idx[i + 1];
		}
	}
	cout << A << ' ' << B << endl;
}
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
int arr[60];
int64 k;

int main(){
	cin >> n >> k;
	if(n == 1){
		cout << 1 << endl;
		return 0;
	}
	k--;
	int str = 0, end = n - 1;
	int64 p = 1LL << (n - 2);
	for(int i = 1; i <= n; i++){
		if(k >= p){
			k -= p;
			arr[end--] = i;
		}
		else arr[str++] = i;
		p >>= 1;
	}
	for(int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	cout << endl;
	return 0;
}
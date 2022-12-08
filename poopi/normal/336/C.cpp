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
int a[100010];

int main(){
	cin >> n;
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int res = -1, cnt;
	for(int i = 0; i < 30; i++){
		int sum = (1 << 30) - 1;
		int tot = 0;
		for(int j = 0; j < n; j++){
			if(a[j] & (1 << i)){
				sum &= a[j];
				tot++;
			}
		}
		if(sum % (1 << i) == 0){
			res = i;
			cnt = tot;
		}
	}
	cout << cnt << endl;
	for(int j = 0; j < n; j++)
		if(a[j] & (1 << res))
			cout << a[j] << ' ';
	cout << endl;
	return 0;
}
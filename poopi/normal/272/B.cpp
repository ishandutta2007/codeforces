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
#define PLL pair<int64, int64>
#define Max 1000010

int n;
int64 cnt[50];

int main(){
	cin >> n;
	int a, c;
	for(int i = 0; i < n; i++){
		cin >> a;
		c = 0;
		while(a){
			if(a & 1) c++;
			a >>= 1;
		}
		cnt[c]++;
	}
	int64 res = 0;
	for(int i = 0; i < 50; i++)
		res += cnt[i] * (cnt[i] - 1) / 2;
	cout << res << endl;
    return 0;
}
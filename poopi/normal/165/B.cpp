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

int main(){
	int n, k;
	cin >> n >> k;
	int l = 1, r = n;
	while(l < r){
		int mid = (l + r) / 2;
		int64 p = 1, sum = 0;
		while(p <= mid){
			sum += mid / p;
			p *= k;
		}
		if(sum >= n)
			r = mid;
		else l = mid + 1;
	}
	cout << r << endl;
    return 0;
}
										/* in the name of Allah */
#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <map>

using namespace std;

#define int64 long long
int n;
int64 x[200010];
int64 c[10];

bool can(int64 len){
	int ptr = 0, bef;
	for(int i = 0; i < 3; i++){
		bef = ptr;
		c[i] = x[min(bef, n - 1)] + len;
		while(ptr < n && x[ptr] - x[bef] <= 2 * len)
			ptr++;
	}
	return (ptr == n);
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x[i];
		x[i] *= 2;
	}
	sort(x, x + n);
	int64 l = 0, r = 2000000000;
	//int64 l = 1, r = 2;
	while(l < r){
		int64 mid = (l + r) / 2;
		if(can(mid))
			r = mid;
		else l = mid + 1;
	}
	can(l);
	cout.precision(6);
	cout.setf(ios::fixed | ios::showpoint);
	cout << (double)l / 2. << endl;
	cout << (double)c[0] / 2. << ' ' << (double)c[1] / 2. << ' ' << (double)c[2] / 2. << endl;
	return 0;
}
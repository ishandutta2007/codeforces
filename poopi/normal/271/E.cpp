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
#define P pair<int64, int>

int64 gcd(int64 a, int64 b){
	return (b == 0 ? a : gcd(b, a % b));
}

int n, m;
vector <P> dv;

int64 calc(int idx, int64 num){
	if(idx == dv.size()){
		int64 res = 0;
		while(num < n){
			res += n - num;
			num *= 2;
		}
		return res;
	}
	int64 res = 0;
	for(int i = 0; i <= dv[idx].second; i++){
		res += calc(idx + 1, num);
		num *= dv[idx].first;
	}
	return res;
}

int main(){
	cin >> m >> n;
	int x = 0, t;
	for(int i = 0; i < m; i++){
		cin >> t;
		t--;
		x = gcd(x, t);
	}
	while(x % 2 == 0)
		x /= 2;
	for(int i = 2; i * i <= x; i++){
		int cnt = 0;
		while(x % i == 0){
			cnt++;
			x /= i;
		}
		if(cnt > 0)
			dv.push_back(P(i, cnt));
	}
	if(x > 1)
		dv.push_back(P(x, 1));
	int64 res = calc(0, 1);
	cout << res << endl;
	return 0;
}
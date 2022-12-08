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
int64 m;
P x[200010];

int64 calc(int idx, int cnt){
	int64 res = 1;
	for(int i = 2; i <= idx; i++){
		int t = i;
		while(t % 2 == 0 && cnt){
			cnt--;
			t /= 2;
		}
		res = (res * t) % m;
	}
	return res;
}

int main(){
	cin >> n;
	n *= 2;
	for(int i = 0; i < n; i++){
		cin >> x[i].first;
		x[i].second = i % (n / 2);
	}
	x[n] = P(2000000000, -1);
	sort(x, x + n + 1);
	cin >> m;
	int64 res = 1;
	int fc = 0, cnt = 0;
	for(int i = 0; i <= n; i++){
		if(i > 0 && x[i].first != x[i - 1].first){
			res = (res * calc(fc, cnt)) % m;
			fc = cnt = 0;
		}
		else if(i > 0 && x[i].second == x[i - 1].second)
			cnt++;
		fc++;
	}
	cout << res << endl;
	return 0;
}
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

vector <P> v;
vector <int> dv;

int gcd(int a, int b){
	return (b == 0 ? a : gcd(b, a % b));
}

void bt(int idx, int num){
	if(idx == v.size()){
		dv.push_back(num);
		return;
	}
	for(int i = 0; i <= v[idx].second; i++){
		bt(idx + 1, num);
		num *= v[idx].first;
	}
}

int main(){
	int a, b, n;
	cin >> a >> b >> n;
	int d = gcd(a, b);
	for(int i = 2; i * i <= d; i++){
		int cnt = 0;
		while(d % i == 0){
			d /= i;
			cnt++;
		}
		if(cnt > 0)
			v.push_back(P(i, cnt));
	}
	if(d > 1)
		v.push_back(P(d, 1));
	bt(0, 1);
	sort(dv.begin(), dv.end());
	int l, r;
	for(int i = 0; i < n; i++){
		cin >> l >> r;
		int res = -1;
		for(int j = 0; j < dv.size(); j++)
			if(dv[j] >= l && dv[j] <= r)
				res = dv[j];
		cout << res << endl;
	}
	return 0;
}
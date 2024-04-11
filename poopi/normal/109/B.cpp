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

int k;
vector <int> v;

bool isluk(int x){
	while(x){
		int d = x % 10;
		if(d != 4 && d != 7)
			return false;
		x /= 10;
	}
	return true;
}

int getsz(int a, int b, int x, int y){
	int s = max(x, a);
	int e = min(b, y);
	return max(0, e - s + 1);
}

double calc(int pl, int pr, int vl, int vr){
	int64 sum = 0;
	for(int i = 0; i + k + 1 < v.size(); i++){
		int f = v[i], s = v[i + k];
		int64 t1 = (double)getsz(v[i] + 1, v[i + 1], pl, pr);
		int64 t2 = (double)getsz(v[i + k], v[i + k + 1] - 1, vl, vr);
		sum += t1 * t2;
	}
	double ret = (double)sum / (vr - vl + 1) / (pr - pl + 1);
	//cout << ret << endl;
	return ret;
}

int main(){
	int pl, pr, vl, vr;
	while(cin >> pl >> pr >> vl >> vr >> k){
		v.clear();
		for(int i = 1; i < 10; i++){
			for(int j = 0; j < (1 << i); j++){
				int x = 0;
				for(int k = 0; k < i; k++)
					x = 10 * x + ((j & (1 << k)) ? 4 : 7);
				v.push_back(x);
			}
		}
		v.push_back(0);
		v.push_back(1000000001);
		sort(v.begin(), v.end());
		double res = 0;
		res += calc(pl, pr, vl, vr);
		res += calc(vl, vr, pl, pr);
		if(k == 1){
			int cnt = 0;
			for(int i = 1; i + 1 < v.size(); i++)
				if(v[i] >= pl && v[i] <= pr && v[i] >= vl && v[i] <= vr)
					cnt++;
			res -= (double)cnt / (vr - vl + 1) / (pr - pl + 1);
		}
		cout.precision(10);
		cout.setf(ios::fixed | ios::showpoint);
		cout << res << endl;
	}
	return 0;
}
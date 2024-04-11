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
#define Mod 1000000007LL

struct tri{
	int t, ref, st;
	tri(int _t, int _r, int _s){
		t = _t;
		ref = _r;
		st = _s;
	}
	bool operator < (const tri &a) const{
		if(t != a.t)
			return t > a.t;
		return st > a.st;
	}
};

int n, m;
int64 res[100010];
vector <tri> v;

int main(){
	while(cin >> n >> m){
		v.clear();
		int a, b;
		v.push_back(tri(-1, 0, 0));
		v.push_back(tri(0, 0, 1));
		v.push_back(tri(n, m + 1, 0));
		v.push_back(tri(n + 1, m + 1, 1));
		for(int i = 0; i < m; i++){
			scanf("%d%d", &a, &b);
			v.push_back(tri(a, i + 1, 0));
			v.push_back(tri(b, i + 1, 1));
			v.push_back(tri(b - 1, i + 1, 2));
		}
		res[m + 1] = 1;
		sort(v.begin(), v.end());
		int64 sum = 1;
		for(int i = 1; i < v.size(); i++){
			tri tmp = v[i];
			int t = tmp.t;
			int idx = tmp.ref;
			if(tmp.st == 0)
				sum = (sum - res[idx] + Mod) % Mod; 
			if(tmp.st == 1)
				res[idx] = sum;
			if(tmp.st == 2)
				sum = (sum + res[idx]) % Mod;
			//cout << t << ' ' << idx << ' ' << tmp.st << ' ' << sum << endl;
		}
		cout << res[0] << endl;
	}
	return 0;
}
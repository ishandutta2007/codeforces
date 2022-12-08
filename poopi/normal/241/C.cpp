										/* in the name of Allah */
#include <iostream>
#include <fstream>
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
#define Max 100000.

int h1, h2, n;
int w[110];
double s[110], e[110];
bool mark[110], st[110];

int calc(double m){
	if(fabs(m) < 1e-9)
		return 0;
	double x = 0, h = h1;
	int res = 0;
	memset(mark, false, sizeof mark);
	while(x < 100000.){
		if(m < 0){
			x += (0 - h) / m;
			h = 0;
			m *= -1;
			if(x > Max) return res;
			bool f = false;
			for(int i = 0; i < n; i++){
				if(st[i] == 0 && s[i] <= x && x <= e[i]){
					f = true;
					if(mark[i])
						return 0;
					mark[i] = true;
					res += w[i];
				}
			}
			if(!f)
				return 0;
		}
		else{
			x += (100 - h) / m;
			h = 100;
			m *= -1;
			if(x > Max) return res;
			bool f = false;
			for(int i = 0; i < n; i++){
				if(st[i] == 1 && s[i] <= x && x <= e[i]){
					f = true;
					if(mark[i])
						return 0;
					mark[i] = true;
					res += w[i];
				}
			}
			if(!f)
				return 0;
		}
	}
	return res;
}

int main(){
	int T;
	cin >> h1 >> h2 >> n;
	char ch;
	for(int i = 0; i < n; i++){
		cin >> w[i] >> ch >> s[i] >> e[i];
		if(ch == 'T')
			st[i] = 1;
		else st[i] = 0;
	}
	int res = 0;
	for(int i = -200; i <= 200; i++){
		int t = i * 200 + h2;
		double m = (double)(t - h1) / 100000;
		res = max(res, calc(m));
		t = i * 200 - h2;
		m = (double)(t - h1) / 100000;
		res = max(res, calc(m));
	}
	cout << res << endl;
	return 0;
}
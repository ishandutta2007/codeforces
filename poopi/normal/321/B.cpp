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

int n, m;
vector <int> a, d, v;
bool mark[200];

int main(){
	cin >> n >> m;
	string str;
	int x;
	for(int i = 0; i < n; i++){
		cin >> str >> x;
		if(str[0] == 'A')
			a.push_back(x);
		else d.push_back(x);
	}
	for(int i = 0; i < m; i++){
		cin >> x;
		v.push_back(x);
	}
	sort(a.begin(), a.end());
	sort(d.begin(), d.end());
	sort(v.begin(), v.end());
	int res = 0, sum, p;
	for(int s = 0; s < a.size(); s++){
		sum = 0, p = (int)v.size() - 1;
		for(int j = s; p >= 0 && j >= 0; j--){
			if(v[p] >= a[j]){
				sum += v[p] - a[j];
				p--;
			}
		}
		res = max(res, sum);
	}
	p = 0;
	bool can = true;
	for(int i = 0; i < d.size(); i++){
		while(p < v.size() && v[p] <= d[i])
			p++;
		if(p == v.size()){
			can = false;
			break;
		}
		mark[p++] = true;
	}
	if(can){
		sum = 0;
		p = (int)a.size() - 1;
		for(int i = v.size() - 1; i >= 0; i--){
			if(mark[i]) continue;
			if(p < 0)
				sum += v[i];
			else if(v[i] >= a[p])
				sum += v[i] - a[p--];
		}
		res = max(res, sum);
	}
	cout << res << endl;
	return 0;
}
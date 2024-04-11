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
#define Max 2000000

struct triple{
	int o, c, t;
	triple(){}
	triple(int a, int b, int _c){
		o = a, c = b, t = _c;
	}
};

int n, m, pnt;
char ch[1000010];
int lf[Max], rt[Max];
int st[Max], en[Max];
int open[Max], close[Max], match[Max];

void build(int idx, int s, int e){
	st[idx] = s;
	en[idx] = e;
	if(s == e){
		lf[idx] = rt[idx] = -1;
		open[idx] = (ch[s] == '(' ? 1 : 0);
		close[idx] = (ch[s] == ')' ? 1 : 0);
	}
	else{
		int tmp = (s + e) / 2;
		lf[idx] = ++pnt;
		rt[idx] = ++pnt;
		build(lf[idx], s, tmp);
		build(rt[idx], tmp + 1, e);
		int newM = min(open[lf[idx]], close[rt[idx]]);
		open[idx] = open[rt[idx]] + open[lf[idx]] - newM;
		close[idx] = close[lf[idx]] + close[rt[idx]] - newM;
		match[idx] = match[lf[idx]] + match[rt[idx]] + newM;
	}
}

triple query(int idx, int l, int r){
	if(r < l)
		return triple(0, 0, 0);
	if(l <= st[idx] && en[idx] <= r)
		return triple(open[idx], close[idx], match[idx]);

	int tmp = (st[idx] + en[idx]) / 2;
	triple t1 = query(lf[idx], max(l, st[idx]), min(r, tmp));
	triple t2 = query(rt[idx], max(l, tmp + 1), min(r, en[idx]));
	int newM = min(t1.o, t2.c);
	triple res;
	res.o = t1.o + t2.o - newM;
	res.c = t1.c + t2.c - newM;
	res.t = t1.t + t2.t + newM;
	return res;
}

int main(){
	scanf("%s", ch);
	n = strlen(ch);
	build(0, 0, n - 1);
	cin >> m;
	int l, r;
	for(int i = 0; i < m; i++){
		cin >> l >> r;
		l--, r--;
		cout << 2 * query(0, l, r).t << endl;
	}
	return 0;
}
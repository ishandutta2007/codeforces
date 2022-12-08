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

char ch[5];
string str;

int64 calc(int a, int b, int c, int d, int e, int y){
	int t = min(a, y);
	a -= t, y -= t;
	t = min(b, y);
	b -= t, y -= t;
	t = min(e, y);
	e -= t, y -= t;
	t = min(a, c);
	a -= t, c -= t;
	return b + d + e - a - c;
}

int main(){
	int n, a, b, c, d, e;
	a = b = c = d = e = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
		scanf("%s", ch);
		str = ch;
		if(str == "UL")
			a++;
		else if(str == "UR")
			b++;
		else if(str == "DL")
			c++;
		else if(str == "DR")
			d++;
		else e++;
	}
	int64 cnt = 0, tmp;
	for(int i = 0; i <= a + b + e; i++){
		tmp = calc(a, b, c, d, e, i);
		tmp += calc(b, a, d, c, e, i);
		cnt += tmp / 2 + 1;
	}
	for(int i = 1; i <= c + d + e; i++){
		tmp = calc(c, d, a, b, e, i);
		tmp += calc(d, c, b, a, e, i);
		cnt += tmp / 2 + 1;
	}
	cout << cnt << endl;
	return 0;
}
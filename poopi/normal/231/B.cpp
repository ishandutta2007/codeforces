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

ifstream fin("input.txt");
ofstream fout("output.txt");

#define uint unsigned int
#define int64 long long
#define P pair<int, int>
#define Pss pair<string, string>
#define PLL pair<int64, int64>
#define Inf 1000000
#define Mod 1000000007LL
//#define cin fin
//#define cout fout

int n, d, mx;

void print(int l, int r){
	l -= (n + 1) / 2;
	r -= n / 2;
	for(int i = 0; i < n; i++){
		if(i % 2){
			cout << min(mx, r + 1) << ' ';
			r -= min(mx - 1, r);
		}
		else{
			cout << min(mx, l + 1) << ' ';
			l -= min(mx - 1, l);
		}
	}
	cout << endl;
}

int main(){
	cin >> n >> d >> mx;
	int l1 = (n + 1) / 2;
	int l2 = l1 * mx;
	int r1 = n / 2;
	int r2 = r1 * mx;
	if(d <= 0 && r2 - l1 >= -d)
		print(l1, l1 - d);
	else if(d > 0 && l2 - r1 >= d)
		print(r1 + d, r1);
	else cout << -1 << endl;
    return 0;
}
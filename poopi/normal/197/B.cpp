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

int n, m;
int a0, b0;

int gcd(int a, int b){
	return (b == 0 ? a : gcd(b, a % b));
}

int main(){
	int tmp;
	cin >> n >> m >> a0;
	for(int i = 0; i < n; i++)
		cin >> tmp;
	cin >> b0;
	for(int i = 0; i < m; i++)
		cin >> tmp;
	if(n < m)
		cout << "0/1" << endl;
	if(n > m){
		if(a0 * b0 < 0)
			cout << '-';
		cout << "Infinity" << endl;
	}
	if(n == m){
		if(a0 * b0 < 0)
			cout << '-';
		a0 = abs(a0), b0 = abs(b0);
		int d = gcd(a0, b0);
		cout << a0 / d << '/' << b0 / d << endl;
	}
    return 0;
}
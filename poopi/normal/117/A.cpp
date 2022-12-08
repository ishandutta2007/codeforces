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
int s, f, t;

int dist(int a, int b, int d){
	if((a <= b && d == 1) || (a >= b && d == -1))
		return abs(a - b);
	if(d == 1)
		return (m - a + m - b);
	return a + b - 2;
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> s >> f >> t;
		int cir = t / (2 * m - 2);
		int nt = t % (2 * m - 2);
		if(s == f)
			cout << t << endl;
		else if(nt > m - 1 + (m - s))
			cout << (cir + 1) * (2 * m - 2) + s - 1 + dist(s, f, 1) << endl;
		else if(nt > s - 1)
			cout << cir * (2 * m - 2) + m - 1 + (m - s) + dist(s, f, -1) << endl;
		else cout << cir * (2 * m - 2) + s - 1 + dist(s, f, 1) << endl;
	}
    return 0;
}
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

set <int> x, y;
set <P> p;
int X[3], Y[3];

int main(){
	int a, b;
	for(int i = 0; i < 8; i++){
		cin >> a >> b;
		x.insert(a);
		y.insert(b);
		p.insert(P(a, b));
	}
	string res = "respectable";
	if(x.size() != 3 || y.size() != 3){
		cout << "ugly" << endl;
		return 0;
	}
	int cnt = 0;
	for(set <int>::iterator it = x.begin(); it != x.end(); it++)
		X[cnt++] = *it;
	cnt = 0;
	for(set <int>::iterator it = y.begin(); it != y.end(); it++)
		Y[cnt++] = *it;
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			if((i != 1 || j != 1) && !p.count(P(X[i], Y[j])))
				res = "ugly";
	cout << res << endl;
}
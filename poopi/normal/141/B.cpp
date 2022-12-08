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
//#define cin fin
//#define cout fout

int a, x, y;

int main(){
	cin >> a >> x >> y;
	int b = (a + 1) / 2;
	if(y < a){
		if(y > 0 && x > -b && x < b)
			cout << 1 << endl;
		else cout << -1 << endl;
		return 0;
	}
	y -= a;
	int cnt = (y / (2 * a)) * 3 + 1;
	y %= 2 * a;
	if(y > 0 && y < a && x > -b && x < b)
		cout << cnt + 1 << endl;
	else if(y > a && y < 2 * a && x > -a && x < 0)
		cout << cnt + 2 << endl;
	else if(y > a && y < 2 * a && x > 0 && x < a)
		cout << cnt + 3 << endl;
	else cout << -1 << endl;
    return 0;
}
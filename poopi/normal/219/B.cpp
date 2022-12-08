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

int64 p, d;

int main(){
	cin >> p >> d;
	int64 nine = 0, res = p;
	int64 pw = 1;
	for(int i = 0; i < 18; i++){
		nine = nine * 10 + 9;
		pw *= 10;
		int64 rem = p - nine;
		int64 num = rem - rem % pw + nine;
		if(rem >= 0 && p - num <= d)
			res = num;
	}
	cout << res << endl;
    return 0;
}
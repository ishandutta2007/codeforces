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

int main(){
	string str;
	cin >> str;
	int cnt = str.length() - 1;
	int cr = 0;
	for(int i = str.length() - 1; i > 0; i--){
		int t = str[i] - '0';
		if(t + cr == 1)
			cnt++;
		if(t + cr >= 1)
			cr = 1;
	}
	cout << cnt + cr << endl;
    return 0;
}
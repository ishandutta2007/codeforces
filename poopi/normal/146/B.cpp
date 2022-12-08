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

int n, k;

int mask(int num){
	int ret = 0, p = 1;
	while(num){
		if(num % 10 == 4 || num % 10 == 7){
			ret += p * (num % 10);
			p *= 10;
		}
		num /= 10;
	}
	return ret;
}

int main(){
	cin >> n >> k;
	int res = n + 1;
	while(mask(res) != k)
		res++;
	cout << res << endl;
    return 0;
}
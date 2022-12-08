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

int s(int64 num){
	int res = 0;
	while(num){
		res += num % 10;
		num /= 10;
	}
	return res;
}

int main(){
	int64 n;
	cin >> n;
	int64 rt = sqrt((double)n) + 1e-9;
	for(int64 i = max(0LL, rt - 200); i <= rt; i++){
		int64 val = i * (i + s(i));
		if(val == n){
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
    return 0;
}
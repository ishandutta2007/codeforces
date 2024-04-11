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
#define cin fin
#define cout fout

int n;
string str;

int main(){
	cin >> n >> str;
	for(int i = 0, j = n / 2; i < n / 2; i++, j++){
		if(str[i] != 'R' || str[j] != 'L')
			cout << i + 1 << ' ' << j + 1 << endl;
		else cout << j + 1 << ' ' << i + 1 << endl;
	}
    return 0;
}
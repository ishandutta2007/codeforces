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

int k;
string str;

int main(){	
	cin >> str >> k;
	for(int i = 0; i < str.length(); i++){
		if(islower(str[i]) && str[i] < 'a' + k)
			str[i] += 'A' - 'a';
		if(isupper(str[i]) && str[i] >= 'A' + k)
			str[i] -= 'A' - 'a';
	}
	cout << str << endl;
}
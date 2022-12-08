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

char ch[8] = {'>', '<', '+', '-', '.', ',', '[', ']'};

int getId(char inp){
	for(int i = 0; i < 8; i++)
		if(ch[i] == inp)
			return i + 8;
	return -1;
}

int main(){
	string str;
	cin >> str;
	int res = 0;
	for(int i = 0; i < str.length(); i++)
		res = (res * 16 + getId(str[i])) % 1000003;
	cout << res << endl;
}
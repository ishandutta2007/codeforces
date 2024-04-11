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
#define PLL pair<int64, int64>
//#define cin fin
//#define cout fout

int n;
bool s[30], d[1000];

int main(){
	cin >> n;
	string str;
	for(int i = 0; i < n; i++){
		cin >> str;
		for(int j = 0; j < str.length(); j++){
			s[str[j] - 'a'] = true;
			if(j > 0)
				d[(str[j - 1] - 'a') * 26 + str[j] - 'a'] = true;
		}
	}
	for(int i = 0; i < 26; i++){
		if(!s[i]){
			cout << (char)('a' + i) << endl;
			return 0;
		}
	}
	for(int i = 0; i < 26; i++)
		for(int j = 0; j < 26; j++)
			if(!d[i * 26 + j]){
				cout << (char)('a' + i) << (char)('a' + j) << endl;
				return 0;
			}

    return 0;
}
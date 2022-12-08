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
	string s1, s2;
	cin >> s1 >> s2;
	sort(s1.begin(), s1.end());
	if(s1.length() > 1 && s1[0] == '0'){
		int p = 0;
		while(s1[p] == '0')
			p++;
		swap(s1[0], s1[p]);
	}
	cout << (s1 == s2 ? "OK" : "WRONG_ANSWER") << endl;
    return 0;
}
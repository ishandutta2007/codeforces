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
	bool sg = false, pnt = false;
	if(str[0] == '-'){
		sg = true;
		str[0] = ' ';
	}
	for(int i = 0; i < str.length(); i++){
		if(str[i] == '.'){
			str[i] = ' ';
			pnt = true;
		}
	}
	istringstream sin(str);
	string a, b = "00";
	sin >> a;
	if(pnt)
		sin >> b;
	while(b.length() < 2)
		b += '0';
	b = b.substr(0, 2);
	if(sg) cout << '(';
	cout << '$';
	for(int i = 0; i < a.length(); i++){
		if(i != 0 && i % 3 == a.length() % 3)
			cout << ',';
		cout << a[i];
	}
	cout << '.' << b;
	if(sg) cout << ')';
	cout << endl;
    return 0;
}
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

#define uint unsigned int
#define int64 long long
#define P pair<int, int>
#define Pss pair<string, string>
#define PLL pair<int64, int64>
#define Inf 1000000
#define Mod 1000000007LL

string str;
vector <string> v;

int main(){
	cin >> str;
	int cnt = 1;
	for(int i = 0; i < str.length(); i++){
		if(str[i] == '@' && cnt < 2){
			cout << "No solution" << endl;
			return 0;
		}
		if(str[i] == '@')
			cnt = 0;
		else cnt++;
	}
	if(cnt == 0 || cnt == str.length() + 1){
		cout << "No solution" << endl;
		return 0;
	}
	for(int i = 0; i < str.length(); i++)
		if(str[i] == '@')
			str[i] = ' ';
	istringstream sin(str);
	string s;
	while(sin >> s)
		v.push_back(s);
	for(int i = 1; i + 1 < v.size(); i++)
		v[i] = v[i].substr(0, 1) + ',' + v[i].substr(1);
	cout << v[0];
	for(int i = 1; i < v.size(); i++)
		cout << '@' << v[i];
	cout << endl;
	return 0;
}
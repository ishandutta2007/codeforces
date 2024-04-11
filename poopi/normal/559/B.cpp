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

string s1, s2;

string srt(string str){
	int len = str.length();
	if(len % 2)
		return str;
	string t1 = srt(str.substr(0, len / 2));
	string t2 = srt(str.substr(len / 2));
	if(t2 > t1)
		return t2 + t1;
	return t1 + t2;
}

int main(){
	cin >> s1 >> s2;
	s1 = srt(s1);
	s2 = srt(s2);
	cout << (s1 == s2 ? "YES" : "NO") << endl;
	return 0;
}
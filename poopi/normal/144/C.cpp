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
#define PLL pair<int64, int64>

int cnt[30];
string str, pat;

bool isok(){
	for(int j = 0; j < 26; j++)
		if(cnt[j] < 0)
			return false;
	return true;
}

int main(){
	cin >> str >> pat;
	if(pat.length() > str.length()){
		cout << 0 << endl;
		return 0;
	}
	for(int i = 0; i < pat.length(); i++){
		cnt[pat[i] - 'a']++;
		if(str[i] != '?')
			cnt[str[i] - 'a']--;
	}
	int res = 0;
	if(isok()) res++;
	for(int i = pat.length(); i < str.length(); i++){
		if(str[i] != '?')
			cnt[str[i] - 'a']--;
		if(str[i - pat.length()] != '?')
			cnt[str[i - pat.length()] - 'a']++;
		if(isok()) res++;
	}
	cout << res << endl;
	return 0;
}
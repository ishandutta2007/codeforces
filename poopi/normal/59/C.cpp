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

int n, k;
string str;
bool mark[30];
int st[110];

int main(){
	cin >> k >> str;
	n = str.length();
	for(int i = 0; i < (n + 1) / 2; i++){
		char ch1 = str[i], ch2 = str[n - 1 - i];
		if(ch1 != '?' && ch2 != '?'){
			if(ch1 != ch2){
				cout << "IMPOSSIBLE" << endl;
				return 0;
			}
			st[i] = ch1 - 'a';
		}
		if(ch1 == '?' && ch2 == '?')
			st[i] = -1;
		if(ch1 == '?' && ch2 != '?')
			st[i] = ch2 - 'a';
		if(ch1 != '?' && ch2 == '?')
			st[i] = ch1 - 'a';
		if(st[i] != -1)
			mark[st[i]] = true;
	}
	k--;
	for(int i = (n - 1) / 2; i >= 0; i--){
		while(mark[k])
			k--;
		if(st[i] == -1)
			st[i] = max(0, k--);
	}
	if(k >= 0)
		cout << "IMPOSSIBLE" << endl;
	else{
		for(int i = 0; i < n; i++)
			cout << (char)(st[min(i, n - 1 - i)] + 'a');
		cout << endl;
	}
	return 0;
}
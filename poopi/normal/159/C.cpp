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

int n, k;
string str;
bool mark[2010][110];
int cnt[2010][30];

int main(){
	cin >> k >> str >> n;
	for(int i = 0; i < str.length(); i++)
		cnt[0][str[i] - 'a']++;
	for(int i = 1; i < k; i++)
		for(int j = 0; j < 26; j++)
			cnt[i][j] = cnt[0][j];
	int rem;
	char ch;
	for(int i = 0; i < n; i++){
		cin >> rem >> ch;
		int p = 0, idx = -1;
		while(cnt[p][ch - 'a'] < rem)
			rem -= cnt[p++][ch - 'a'];
		while(rem){
			if(str[++idx] == ch && !mark[p][idx])
				rem--;
		}
		mark[p][idx] = true;
		cnt[p][ch - 'a']--;
	}
	for(int i = 0; i < k; i++)
		for(int j = 0; j < str.length(); j++)
			if(!mark[i][j])
				cout << str[j];
	cout << endl;
    return 0;
}
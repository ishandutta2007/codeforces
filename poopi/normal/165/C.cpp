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

int k;
string str;
int aft[1000010];
int bef[1000010];
int idx[1000010];
set <int> st;

int main(){
	cin >> k >> str;
	bef[0] = 1;
	for(int i = 1; i < str.length(); i++)
		bef[i] = (str[i - 1] == '1' ? 1 : bef[i - 1] + 1);
	aft[str.length() - 1] = 1;
	for(int i = str.length() - 2; i >= 0; i--)
		aft[i] = (str[i + 1] == '1' ? 1 : aft[i + 1] + 1);
	int n = 0;
	for(int i = 0; i < str.length(); i++)
		if(str[i] == '1')
			idx[n++] = i;
	int64 res = 0;
	if(k == 0){
		int cnt = 0;
		for(int i = 0; i < str.length(); i++){
			if(str[i] == '1')
				cnt = 0;
			else cnt++;
			res += cnt;
		}
	}
	else for(int i = 0; i + k <= n; i++)
		res += (int64)bef[idx[i]] * aft[idx[i + k - 1]];
	cout << res << endl;
	return 0;
}
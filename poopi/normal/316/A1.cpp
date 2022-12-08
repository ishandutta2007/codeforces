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

int alp, cnt;
bool mark[10];
string str;

int main(){
	cin >> str;
	for(int i = 0; i < str.length(); i++){
		if(str[i] >= 'A' && str[i] <= 'J' && !mark[str[i] - 'A']){
			mark[str[i] - 'A'] = true;
			alp++;
		}
		if(str[i] == '?')
			cnt++;
	}
	int way = 1;
	for(int i = 0; i < alp; i++)
		way *= (10 - i);
	if(str[0] >= 'A' && str[0] <= 'J')
		way = way / 10 * 9;
	if(str[0] == '?'){
		cnt--;
		way *= 9;
	}
	cout << way;
	for(int i = 0; i < cnt; i++)
		cout << 0;
	cout << endl;
	return 0;
}
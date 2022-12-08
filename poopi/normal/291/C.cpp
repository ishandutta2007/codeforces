										/* in the name of Allah */

#include <algorithm>
#include <iostream>
#include <memory.h>
#include <iomanip>
#include <sstream>
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
#define P pair<int, double>

int n, k;
int ip[100010];
set <int> st;

int main(){
	cin >> n >> k;
	string str;
	int a;
	for(int i = 0; i < n; i++){
		cin >> str;
		for(int j = 0; j < str.length(); j++)
			if(str[j] == '.')
				str[j] = ' ';
		istringstream sin(str);
		for(int j = 0; j < 4; j++){
			sin >> a;
			ip[i] = ip[i] * 256 + a;	
		}
	}
	uint val = 0;
	for(int i = 0; i < 32; i++){
		val += (1 << (31 - i));
		st.clear();
		for(int j = 0; j < n; j++)
			st.insert(val & ip[j]);
		if(st.size() >= k)
			break;
	}
	if(st.size() == k)
		cout << (val >> 24) % 256 << '.' << (val >> 16) % 256 << '.' << (val >> 8) % 256 << '.' << val % 256 << endl;
	else cout << -1 << endl;
	return 0;
}
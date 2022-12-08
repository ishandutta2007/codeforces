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

int n, m, k;
set <string> st;

int main(){
	std::ios::sync_with_stdio(false);
	cin >> n >> m;
	string str;
	for(int i = 0; i < n; i++){
		cin >> str;
		st.insert(str);
	}
	for(int i = 0; i < m; i++){
		cin >> str;
		if(st.count(str))
			k++;
	}
	n -= k, m -= k;
	n += k % 2;
	cout << (n > m ? "YES" : "NO") << endl;
	return 0;
}
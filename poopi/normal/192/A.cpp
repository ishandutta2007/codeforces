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

int n;
set <int> st;

int main(){
	cin >> n;
	string res = "NO";
	for(int i = 1; i * (i + 1) / 2 <= n; i++){
		int tmp = i * (i + 1) / 2;
		st.insert(tmp);
		if(st.count(n - tmp))
			res = "YES";
	}
	cout << res << endl;
	return 0;
}
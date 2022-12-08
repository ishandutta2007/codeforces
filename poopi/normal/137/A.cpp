								/* in the name of Allah */
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>

using namespace std;

#define P pair<int64, int64>
#define int64 long long

int main(){
	string str;
	while(cin >> str){
		str += 'a';
		int ret = 0, cnt = 0;
		for(int i = 0; i < str.length(); i++){
			if(i > 0 && str[i] != str[i - 1]){
				ret += (cnt + 4) / 5;
				cnt = 1;
			}
			else cnt++;
		}
		cout << ret << endl;
	}
	return 0;
}
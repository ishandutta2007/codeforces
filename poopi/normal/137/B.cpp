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

int n;
bool mark[10000];

int main(){
	while(cin >> n){
		int rem = n, a;
		memset(mark, false, sizeof mark);
		for(int i = 0; i < n; i++){
			cin >> a;
			if(!mark[a] && a <= n)
				rem--;
			mark[a] = true;
		}
		cout << rem << endl;
	}
	return 0;
}
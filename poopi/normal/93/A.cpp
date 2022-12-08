										/* in the name of Allah */
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

#define int64 long long
#define P pair<int, int>

int n, m, a, b;

int main(){
	while(cin >> n >> m >> a >> b){
		a--, b--;
		if(a / m == b / m){
			cout << 1 << endl;
			continue;
		}
		int res = 1;
		if(a % m != 0)
			res++;
		if(b % m != m - 1 && b != n - 1)
			res++;
		if(res == 3){
			if(a / m + 1 == b / m)
				cout << 2 << endl;
			else if(a % m == b % m + 1)
				cout << 2 << endl;
			else cout << 3 << endl;
		}
		else cout << res << endl;
	}
	return 0;
}
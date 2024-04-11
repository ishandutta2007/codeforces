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

int main(){
	std::ios::sync_with_stdio(false);
	cin >> n >> k;
	if(n <= 3)
		cout << -1 << endl;
	else if(k == 2){
		if(n == 4)
			cout << -1 << endl;
		else{
			cout << n - 1 << endl;
			for(int i = 1; i < n; i++)
				cout << i << ' ' << i + 1 << endl;
		}
	}
	else if(k == 3){
		cout << (n - 4) * 2 + 3 << endl;
		for(int i = 1; i < 4; i++)
			cout << i << ' ' << i + 1 << endl;
		for(int i = 5; i <= n; i++){
			cout << i << ' ' << 2 << endl;
			cout << i << ' ' << 3 << endl;
		}
	}
	else cout << -1 << endl;
	return 0;
}
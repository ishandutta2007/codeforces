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

int main(){
	std::ios::sync_with_stdio(false);
	int T;
	for(cin >> T; T--; ){
		int n, a, b;
		int ans = 0;

		cin >> n >> a;
		for(int i = 1; i < n; i++){
			cin >> b;
			int d = a - b;
			int cnt = 0;
			while(d > 0){
				d /= 2;
				cnt++;
			}
			ans = max(ans, cnt);

			a = max(a, b);
		}
		cout << ans << endl;
	}
	return 0;
}
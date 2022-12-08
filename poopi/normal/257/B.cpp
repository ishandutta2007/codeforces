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

int n[2];
int c1, c2;

int main(){
	cin >> n[0] >> n[1];
	int pre;
	if(n[0] > n[1])
		swap(n[0], n[1]);
	if(n[0] % 2)
		pre = 0, n[0]--;
	else pre = 1, n[1]--;
	int s = 1;
	while(n[0] || n[1]){
		if((s && n[1 - pre] > 0) || (!s && n[pre] == 0)){
			c2++;
			n[1 - pre]--;
			pre = 1 - pre;
		}
		else{
			n[pre]--;
			c1++;
		}
		s = 1 - s;
	}
	cout << c1 << ' ' << c2 << endl;
	return 0;
}
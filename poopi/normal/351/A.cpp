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

int n;
string str;

int main(){
	cin >> n;
	int a, b, sum = 0, nz = 0;
	for(int i = 0; i < 2 * n; i++){
		cin >> str;
		for(int j = 0; j < str.length(); j++)
			if(str[j] == '.')
				str[j] = ' ';
		istringstream sin (str);
		sin >> a >> b;
		sum += b;
		if(b != 0)
			nz++;
	}
	int x = sum / 1000;
	int t1 = max(min(x, min(n, nz)), nz - n);
	int t2 = max(min(x + 1, min(n, nz)), nz - n);
	int res = min(abs(t1 * 1000 - sum), abs(t2 * 1000 - sum));
	printf("%d.%03d\n", res / 1000, res % 1000);
	return 0;
}
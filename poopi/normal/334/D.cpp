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

int n, m;
int r[1010], c[1010];

int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		r[i] = c[i] = 1;
	int a, b;
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		r[a - 1] = 0;
		c[b - 1] = 0;
	}
	int res = 0;
	for(int i = 1; i < n / 2; i++)
		res += r[i] + r[n - 1 - i] + c[i] + c[n - 1 - i];
	if(n % 2 && (r[n / 2] || c[n / 2]))
		res++;
	cout << res << endl;
	return 0;
}
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

ifstream fin("input.txt");
ofstream fout("output.txt");

#define uint unsigned int
#define int64 long long
#define P pair<int, int>
#define Pss pair<string, string>
#define PLL pair<int64, int64>
//#define cin fin
//#define cout fout

int n;
int64 arr[2000010];

int main(){
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	reverse(arr, arr + n);
	for(int i = 1; i < n; i++)
		arr[i] += arr[i - 1];
	int64 res = 0;
	for(int i = 1; i <= n; i *= 4)
		res += arr[i - 1];
	cout << res << endl;
    return 0;
}
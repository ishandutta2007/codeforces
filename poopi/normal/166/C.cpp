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

int n, x, cnt;
int arr[1000];

int main(){
	cin >> n >> x;
	bool isin = false;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		if(arr[i] == x)
			isin = true;
	}
	if(!isin){
		arr[n++] = x;
		cnt = 1;
	}
	sort(arr, arr + n);
	int p = (n - 1) / 2;
	while(arr[p] != x){
		if(arr[p] < x)
			p++;
		else p--;
	}
	int a = p, b = n - 1 - p;
	if(b > a)
		cnt += b - a - 1;
	else cnt += a - b;
	cout << cnt << endl;
    return 0;
}
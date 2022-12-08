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

int n, p1, p2;
int c1, c2;
int arr[100010];

int main(){
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	p1 = 0, p2 = n - 1;
	for(int i = 0; i < n; i++){
		if(c1 <= c2)
			c1 += arr[p1++];
		else c2 += arr[p2--];
	}
	cout << p1 << ' ' << n - p1 << endl;
    return 0;
}
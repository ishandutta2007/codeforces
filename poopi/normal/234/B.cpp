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
#define PLL pair<int64, int64>
#define cin fin
#define cout fout

P arr[1001];

int main(){
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> arr[i].first;
		arr[i].second = i + 1;
	}
	sort(arr, arr + n);
	reverse(arr, arr + n);
	cout << arr[k - 1].first << endl;
	for(int i = 0; i < k; i++)
		cout << arr[i].second << ' ';
	cout << endl;
    return 0;
}
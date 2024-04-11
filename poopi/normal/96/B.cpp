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

vector <int64> v;

int main(){
	int arr[20];
	for(int i = 1; i <= 5; i++){
		for(int j = 0; j < i; j++)
			arr[j] = 4;
		for(int j = i; j < 2 * i; j++)
			arr[j] = 7;
		do{
			int64 tmp = 0;
			for(int j = 0; j < 2 * i; j++)
				tmp = tmp * 10 + arr[j];
			v.push_back(tmp);
		}while(next_permutation(arr, arr + 2 * i));
	}
	int n, p = 0;
	cin >> n;
	while(v[p] < n)
		p++;
	cout << v[p] << endl;
	return 0;
}
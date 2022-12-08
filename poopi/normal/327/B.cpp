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

#define Max 10000000

bool npr[Max];
vector <int> v;

void find_prime(){
	for(int i = 2; i < Max; i++){
		if(!npr[i]){
			v.push_back(i);
			for(int j = i + i; j < Max; j += i)
				npr[j] = true;
		}
	}
}

int main(){
	int n;
	find_prime();
	cin >> n;
	for(int i = 0; i < n; i++)
		cout << v[i] << ' ';
	cout << endl;
    return 0;
}
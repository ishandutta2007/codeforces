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

bool isPrime(int x){
	for(int i = 2; i < x; i++)
		if(x % i == 0)
			return false;
	return true;
}

int main(){
	std::ios::sync_with_stdio(false);
	int n, m = 1;
	cin >> n;
	while(isPrime(n * m + 1))
		m++;
	cout << m << endl;
	return 0;
}
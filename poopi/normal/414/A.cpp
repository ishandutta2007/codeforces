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
#define Max 2000000

int n, k;
vector <int> pr;
bool npr[Max];

void find_prime(){
	for(int i = 2; i < Max; i++){
		if(!npr[i]){
			pr.push_back(i);
			for(int j = i + i; j < Max; j += i)
				npr[j] = true;
		}
	}
}

int main(){
	find_prime();
	cin >> n >> k;
	if(n == 1){
		if(k == 0)
			cout << 1 << endl;
		else cout << -1 << endl;
		return 0;
	}
	if(n / 2 > k){
		cout << -1 << endl;
		return 0;
	}
	int val = n / 2 - 1;
	k -= val;
	for(int p = 2, i = 0; i < 2 * val; i++, p++){
		if(pr[p] == k)
			p++;
		cout << pr[p] << ' ';
	}
	cout << k << ' ' << 2 * k;
	if(n % 2)
		cout << ' ' << 3 * k;
	cout << endl;
	return 0;
}
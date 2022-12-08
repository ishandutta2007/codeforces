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

int n, k;
int a, b;
string name[2] = {"Stannis", "Daenerys"};

int main(){
	cin >> n >> k;
	int t;
	for(int i = 0; i < n; i++){
		cin >> t;
		if(t % 2)
			a++;
		else b++;
	}
	int md = (n - k) / 2;
	int ms = (n - k + 1) / 2;
	int ans;
	if(md >= a)
		ans = 1;
	else if(k % 2){
		if(ms >= b)
			ans = 0;
		else if((n - k) % 2)
			ans = 0;
		else ans = 1;
	}
	else{
		if(md >= b)
			ans = 1;
		else if((n - k) % 2)
			ans = 0;
		else ans = 1;
	}
	if(n == k)
		ans = 1 - a % 2;
	cout << name[ans] << endl;
	return 0;
}
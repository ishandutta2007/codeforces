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

int64 n, s, k;
int v[10000];
vector <int64> out;

int main(){
	cin >> s >> k;
	v[0] = 0;
	v[1] = n = 1;
	while(v[n] < s){
		for(int i = n; i > n - k && i >= 0; i--)
			v[n + 1] += v[i];
		n++;
	}
	while(n >= 0){
		if(v[n] <= s){
			out.push_back(v[n]);
			s -= v[n];
		}
		n--;
	}
	cout << out.size() << endl;
	for(int i = 0; i < out.size(); i++)
		cout << out[i] << ' ';
	cout << endl;
	return 0;
}
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

string n;
vector <int> v;

int main(){
	cin >> n;
	for(int j = 1; j < 10; j++){
		int t = 0;
		for(int i = 0; i < n.length(); i++){
			t = t * 10;
			if(n[i] > '0'){
				t++;
				n[i]--;
			}
		}
		if(t)
			v.push_back(t);
	}
	cout << v.size() << endl;
	for(int i = 0; i < v.size(); i++)
		cout << v[i] << ' ';
	cout << endl;
	return 0;
}
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

vector <int> v;

int main(){
	int n, m;
	cin >> n >> m;
	int fl = false;
	if(m % 2)
		v.push_back(m / 2 + 1);
	for(int i = m / 2; i > 0; i--){
		v.push_back(i);
		v.push_back(m - i + 1);
	}
	if(fl) v.push_back(++m);
	for(int i = 0; i < n; i++)
		cout << v[i % m] << endl;
    return 0;
}
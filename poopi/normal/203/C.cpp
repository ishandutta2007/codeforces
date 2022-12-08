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

int n, d, a, b;
P arr[100010];
vector <int> v;

int main(){
	cin >> n >> d >> a >> b;
	int x, y;
	for(int i = 0; i < n; i++){
		cin >> x >> y;
		arr[i] = P(a * x + b * y, i + 1);
	}
	sort(arr, arr + n);
	for(int i = 0; i < n; i++){
		if(arr[i].first <= d){
			d -= arr[i].first;
			v.push_back(arr[i].second);
		}
	}
	cout << v.size() << endl;
	for(int i = 0; i < v.size(); i++)
		cout << v[i] << ' ';
	cout << endl;
    return 0;
}
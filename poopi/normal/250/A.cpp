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

int n;
int64 arr[200];
vector <int> v;

int main(){
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	int neg = 0, cnt = 0;
	for(int i = 0; i < n; i++){
		if(neg == 2 && arr[i] < 0){
			v.push_back(cnt);
			neg = 0;
			cnt = 0;
		}
		if(arr[i] < 0) neg++;
		cnt++;
	}
	cout << v.size() + 1 << endl;
	for(int i = 0; i < v.size(); i++)
		cout << v[i] << ' ';
	cout << cnt << endl;
    return 0;
}
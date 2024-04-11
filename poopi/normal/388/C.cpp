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

int n, sum[2];
vector <int> v;
int arr[110];

int main(){
	cin >> n;
	int t;
	for(int i = 0; i < n; i++){
		cin >> t;
		for(int j = 0; j < t; j++)
			cin >> arr[j];
		int s = 0, e = t - 1;
		while(s < e){
			sum[0] += arr[s];
			sum[1] += arr[e];
			s++, e--;
		}
		if(s == e)
			v.push_back(arr[s]);
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	for(int i = 0; i < v.size(); i++)
		sum[i % 2] += v[i];
	cout << sum[0] << ' ' << sum[1] << endl;
	return 0;
}
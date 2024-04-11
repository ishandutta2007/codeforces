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
#define Max 1000010

int d, tot;
int arr[50];
int res[50];

int main(){
	cin >> d >> tot;
	int a, b;
	for(int i = 0; i < d; i++){
		cin >> a >> b;
		tot -= (res[i] = a);
		arr[i] = b - a;
	}
	if(tot < 0){
		cout << "NO" << endl;
		return 0;
	}
	for(int i = 0; i < d; i++){
		int t = min(arr[i], tot);
		tot -= t;
		res[i] += t;
	}
	if(tot == 0){
		cout << "YES" << endl;
		for(int i = 0; i < d; i++)
			cout << res[i] << ' ';
		cout << endl;
	}
	else cout << "NO" << endl;
    return 0;
}
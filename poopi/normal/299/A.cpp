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
int arr[100010];

int gcd(int a, int b){
	return (b == 0 ? a : gcd(b, a % b));
}


int main(){
	cin >> n;
	int d = 0;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		d = gcd(d, arr[i]);
	}
	for(int i = 0; i < n; i++){
		if(arr[i] == d){
			cout << arr[i] << endl;
			return 0;
		}
	}
	cout << -1 << endl;
    return 0;
}
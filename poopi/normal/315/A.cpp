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
int a[110], b[110];

int main(){
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i] >> b[i];
	int cnt = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i != j && a[i] == b[j]){
				cnt++;
				break;
			}
		}
	}
	cout << n - cnt << endl;
    return 0;
}
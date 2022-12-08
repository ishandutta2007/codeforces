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
#define cin fin
#define cout fout

int n;
int cnt[10010];

int main(){
	cin >> n;
	int a;
	for(int i = 0; i < n; i++){
		cin >> a;
		cnt[a]++;
	}
	for(int i = 2; i < 5001; i++)
		cnt[i] += cnt[i - 1];
	int mx = 0;
	for(int i = 1; i < 5001; i++)
		mx = max(mx, cnt[2 * i] - cnt[i - 1]);
	cout << n - mx << endl;
    return 0;
}
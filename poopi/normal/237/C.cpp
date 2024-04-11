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
#define Max 1000010

int a, b, k;
int cnt[Max];
bool npr[Max];

void find_prime(){
	npr[1] = true;
	for(int i = 2; i < Max; i++)
		if(!npr[i])
			for(int j = i + i; j < Max; j += i)
				npr[j] = true;
}

bool isok(int len){
	for(int i = a; i + len - 1 <= b; i++)
		if(cnt[i + len - 1] - cnt[i - 1] < k)
			return false;
	return true;
}

int main(){
	find_prime();
	for(int i = 1; i < Max; i++)
		cnt[i] = cnt[i - 1] + (npr[i] ? 0 : 1);
	cin >> a >> b >> k;
	int l = 1, r = b - a + 1;
	while(l < r){
		int mid = (l + r) / 2;
		if(isok(mid))
			r = mid;
		else l = mid + 1;
	}
	if(!isok(r))
		cout << -1 << endl;
	else cout << r << endl;
    return 0;
}
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
#define Inf 1000000
#define Mod 1000000007LL
//#define cin fin
//#define cout fout

int n, cnt[3];
string s1, s2;

int gcd(int a, int b){
	return (b == 0 ? a : gcd(b, a % b));
}

void calc(char c1, char c2){
	if(c1 == c2)
		return;
	if((c1 == 'R' && c2 == 'S') || (c1 == 'S' && c2 == 'P') || (c1 == 'P' && c2 == 'R'))
		cnt[1]++;
	else cnt[0]++;
}

int main(){
	cin >> n >> s1 >> s2;
	int a = s1.length();
	int b = s2.length();
	int d = a * b / gcd(a, b);
	for(int i = 0; i < d; i++)
		calc(s1[i % a], s2[i % b]);
	int cyc = n / d;
	n %= d;
	cnt[0] *= cyc, cnt[1] *= cyc;
	for(int i = 0; i < n; i++)
		calc(s1[i % a], s2[i % b]);
	cout << cnt[0] << ' ' << cnt[1] << endl;
    return 0;
}
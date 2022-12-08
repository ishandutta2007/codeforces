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

int64 a, b, n, m;
char s1[1000010];
char s2[1000010];
int64 c1[30], c2[30];

int64 gcd(int64 a, int64 b){
	return (b == 0 ? a : gcd(b, a % b));
}

int main(){
	cin >> a >> b;
	scanf("%s", s1);
	n = strlen(s1);
	scanf("%s", s2);
	m = strlen(s2);

	int64 tot = a * n;
	int64 d = gcd(n, m);
	int64 len = n * m / d;
	int64 rep = tot / len;
	int64 cnt = 0;
	for(int i = 0; i < d; i++){
		memset(c1, 0, sizeof c1);
		memset(c2, 0, sizeof c2);
		for(int j = i; j < n; j += d)
			c1[s1[j] - 'a']++;
		for(int j = i; j < m; j += d)
			c2[s2[j] - 'a']++;
		for(int j = 0; j < 26; j++)
			cnt += c1[j] * (m / d - c2[j]);
	}
	cout << rep * cnt << endl;
	return 0;
}
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

int n, k, cnt;
string str;

int main(){
	cin >> n >> k >> str;
	if(k == 2){
		int A[2] = {};
		for(int i = 0; i < n; i++)
			if(str[i] == 'A')
				A[i % 2]++;
		char ch[2] = {'A', 'B'};
		int t1 = (n + 1) / 2 - A[0] + A[1];
		int t2 = A[0] + n / 2 - A[1];
		cnt = min(t1, t2);
		if(t1 > t2)
			swap(ch[0], ch[1]);
		cout << cnt << endl;
		for(int i = 0; i < n; i++)
			cout << ch[i % 2];
		cout << endl;
		return 0;
	}
	for(int i = 1; i < n; i++){
		if(str[i] != str[i - 1])
			continue;
		char p = 'A';
		while(str[i - 1] == p || (i + 1 < n && str[i + 1] == p))
			p++;
		cnt++;
		str[i] = p;
	}
	cout << cnt << endl << str << endl;
    return 0;
}
										/* in the name of Allah */
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

#define int64 long long
#define P pair<int, int>


int diff(string s1, string s2){
	int n = s1.length();
	int res = 0;
	for(int i = 0; i < n; i++)
		if(s1[i] != s2[i])
			res++;
	return res;
}

int main(){
	string s1, s2;
	while(cin >> s1 >> s2){
		int res = 1000000;
		int m = s2.length();
		for(int i = 0; i < m; i++)
			s1 = 'A' + s1;
		for(int i = 0; i < m; i++)
			s1 = s1 + 'A';
		int n = s1.length();
		for(int i = 0; i <= n - m; i++){
			int tmp = diff(s1.substr(i, m), s2);
			res = min(res, tmp);
		}
		cout << res << endl;
	}
	return 0;
}
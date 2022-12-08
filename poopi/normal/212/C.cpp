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

string s;
int64 arr[100];

int main(){
	arr[0] = 1, arr[1] = 2;
	for(int i = 2; i < 100; i++)
		arr[i] = arr[i - 1] + arr[i - 2];
	cin >> s;
	int n = s.length(), idx;
	bool inv = true;
	for(int i = 0; i < n; i++)
		if(s[i] == s[(i + 1) % n])
			inv = false, idx = (i + 1) % n;
	if(inv){
		int t = n / 2;
		if(t == 1) cout << 1 << endl;
		else if(t == 2) cout << 3 << endl;
		else cout << arr[t - 1] + arr[t - 3] << endl;
		return 0;
	}
	s = s.substr(idx) + s.substr(0, idx);
	idx = 0;
	int64 res = 1;
	while(idx < n){
		int ptr = idx;
		while(++idx < n && s[idx] != s[idx - 1]);
		int len = idx - ptr;
		if(len >= 2){
			if(len % 2)
				res *= arr[(len - 3) / 2];
			else if(s[ptr] == 'B')
				res *= arr[len / 2];
			else{
				if(len == 2)
					res = 0;
				else if(len > 4)
					res *= arr[(len - 6) / 2];
			}
		}
	}
	cout << res << endl;
	return 0;
}
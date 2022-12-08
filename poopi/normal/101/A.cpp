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

int k;
string s;
P cnt[30];
bool mark[30];

int main(){
	while(cin >> s >> k){
		int n = s.length();
		int rem = n - k;
		for(int i = 0; i < n; i++)
			cnt[s[i] - 'a'].first++;
		for(int i = 0; i < 26; i++)
			cnt[i].second = i;
		sort(cnt, cnt + 26);
		reverse(cnt, cnt + 26);
		int p = 0;
		while(p < 26 && rem > 0){
			rem -= cnt[p].first;
			p++;
		}
		memset(mark, false, sizeof mark);
		for(int i = 0; i < p; i++)
			mark[cnt[i].second] = true;
		cout << p << endl;

		for(int i = 0; i < n; i++)
			if(mark[s[i] - 'a'])
				printf("%c", s[i]);
		cout << endl;
	}
	return 0;
}
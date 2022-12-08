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

string s1, s2;
vector <int> v[30];

int bs(int alph, int p){
	if(v[alph].size() == 0)
		return -1;
	int l = 0, r = v[alph].size();
	while(l < r){
		int mid = (l + r) / 2;
		if(v[alph][mid] < p)
			l = mid + 1;
		else r = mid;
	}
	if(l == v[alph].size())
		return v[alph][0];
	return v[alph][l];
}

int main(){
	while(cin >> s1 >> s2){
		for(int i = 0; i < 30; i++)
			v[i].clear();
		for(int i = 0; i < s1.length(); i++)
			v[s1[i] - 'a'].push_back(i);
		int cnt = 0, pnt = s1.length();
		for(int i = 0; i < s2.length(); i++){
			int idx = bs(s2[i] - 'a', pnt);
			if(idx == -1){
				cnt = -1;
				break;
			}
			if(idx < pnt)
				cnt++;
			pnt = idx + 1;
		}
		cout << cnt << endl;
	}
	return 0;
}
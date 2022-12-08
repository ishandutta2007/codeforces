								/* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <map>
#include <set>

using namespace std;

#define int64 long long

int64 n, cost[3];
int64 mn = -1, mx;
bool like[10][10];
string name[7] = {"Anka", "Chapay", "Cleo", "Troll", "Dracul", "Snowy", "Hexadecimal"};
int64 st[7], cnt[3];

int getid(string s){
	for(int i = 0; i < 7; i++)
		if(s == name[i])
			return i;
	return 0;
}

void bt(int idx){
	if(idx == 7){
		int64 tmn, tmx = 0;
		for(int i = 0; i < 7; i++)
			for(int j = 0; j < 7; j++)
				if(st[i] == st[j] && like[i][j])
					tmx++;
		for(int i = 0; i < 3; i++)
			if(cnt[i] == 0)
				return;
		int64 l = cost[0] / cnt[0], r = cost[0] / cnt[0];
		l = min(l, cost[1] / cnt[1]), r = max(r, cost[1] / cnt[1]);
		l = min(l, cost[2] / cnt[2]), r = max(r, cost[2] / cnt[2]);
		tmn = r - l;
		if(mn == -1 || mn > tmn || (mn == tmn && mx < tmx))
			mn = tmn, mx = tmx;
		return;
	}
	for(int i = 0; i < 3; i++){
		st[idx] = i;
		cnt[i]++;
		bt(idx + 1);
		cnt[i]--;
	}
}

int main(){
	cin >> n;
	string a, b, c;
	for(int i = 0; i < n; i++){
		cin >> a >> b >> c;
		like[getid(a)][getid(c)] = true;
	}
	for(int i = 0; i < 3; i++)
		cin >> cost[i];
	bt(0);
	cout << mn << ' ' << mx << endl;
	return 0;
}
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
#define Max 1000010

int n, m;
int a[Max], b[Max];
int mp[Max], idx[Max];

int main(){
	cin >> n >> m;
	memset(idx, -1, sizeof idx);
	memset(mp, -1, sizeof mp);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		mp[a[i]] = i;
	}
	for(int i = 0; i < m; i++){
		scanf("%d", &b[i]);
		if(mp[b[i]] != -1)
			idx[mp[b[i]]] = i;
	}
	int mx = 0;
	for(int str = 0, end = 1; str < n; str++){
		if(idx[str] == -1){
			end = (str + 2) % n;
			continue;
		}
		int pend = (end == 0 ? n - 1 : end - 1);
		while(idx[end] != -1 && end != str){
			if(idx[pend] >= idx[str] && idx[end] < idx[pend] && idx[end] > idx[str])
				break;
			if(idx[pend] < idx[str] && (idx[end] < idx[pend] || idx[end] > idx[str]))
				break;
			pend = end;
			end = (end == n - 1 ? 0 : end + 1);
		}
		int dif = end - str;
		if(end <= str)
			dif = end + n - str;
		mx = max(mx, dif);
	}
	cout << mx << endl;
	return 0;
}
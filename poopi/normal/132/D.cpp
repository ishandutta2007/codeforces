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

int n;
int dp[1000010][2];
int way[1000010][2];
int num[1000010][2];
char ch[1000010];

int mem(int idx, int st){
	if(idx == n)
		return 0;
	if(dp[idx][st] != -1)
		return dp[idx][st];
	int &ref = dp[idx][st];
	int cur = num[idx][st];
	if(cur == 0)
		ref = mem(idx + 1, st);
	else{
		int t1 = mem(idx + 1, st) + 1;
		int t2 = mem(idx + 1, 1 - st) + 1;
		if(t1 <= t2){
			ref = t1;
			way[idx][st] = 0;
		}
		else{
			ref = t2;
			way[idx][st] = 1;
		}
	}
	return ref;
}

int main(){
	gets(ch);
	n = strlen(ch);
	int cnt = 0;
	for(int i = 0; i < n; i++){
		num[i][0] = ch[i] - '0';
		cnt += num[i][0];
		num[i][1] = 1 - num[i][0];
	}
	if(cnt == 0){
		cout << 0 << endl;
		return 0;
	}
	int p = n - 1;
	while(num[p][1] == 1)
		num[p--][1] = 0;
	num[p][1] = 1;
	memset(dp, -1, sizeof dp);
	int res = mem(0, 0);
	cout << res << endl;
	int st = 0;
	for(int idx = 0; idx < n; idx++){
		int cur = num[idx][st];
		if(cur == 0)
			continue;
		cout << (st ? "-2^" : "+2^");
		if(way[idx][st] == 0)
			cout << n - idx - 1 << endl;
		else{
			cout << n - idx << endl;
			st = 1 - st;
		}
	}
	return 0;
}
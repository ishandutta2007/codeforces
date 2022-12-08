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
#define Mod 1000000007
#define P pair<int, int>
#define B 30

int n;
char ch[200];
int64 dp[110][3000];

int64 mem(int len, int sum){
	if(len == 0)
		return (sum == 0 ? 1 : 0);
	if(dp[len][sum] != -1)
		return dp[len][sum];
	int64 &ref = dp[len][sum];
	ref = 0;
	for(int i = 0; i < 26; i++){
		ref += mem(len - 1, sum - i);
		if(ref >= Mod)
			ref -= Mod;
	}
	return ref;
}

int main(){
	string str;
	memset(dp, -1, sizeof dp);
	int T;
	for(cin >> T; T--; ){
		scanf("%s", &ch);
		n = strlen(ch);
		int sum = 0;
		for(int i = 0; i < n; i++)
			sum += ch[i] - 'a';
		int64 res = mem(n, sum);
		res = (res - 1 + Mod) % Mod;
		cout << res << endl;
	}
	return 0;
}
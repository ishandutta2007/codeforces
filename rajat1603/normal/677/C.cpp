#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
char str[N];
int n;
map < char , int > mp;
int ans;
int calc[64];
void pre(){
	mp.clear();
	for(int i = 0 ; i < 10 ; ++i){
		mp[char('0' + i)] = i;
	}
	int cnt = 9;
	for(char i = 'A' ; i <= 'Z' ; ++i){
		mp[i] = ++cnt;
	}
	for(char i = 'a' ; i <= 'z' ; ++i){
		mp[i] = ++cnt;
	}
	mp['-'] = ++cnt;
	mp['_'] = ++cnt;
	memset(calc , 0 , sizeof(calc));
	for(int i = 0 ; i < 64 ; ++i){
		for(int j = 0 ; j < 64 ; ++j){
			++calc[i & j];
		}
	}
}
void solve(int val){
	ans = (1LL * ans * calc[val]) % mod;
}
int main(){
	pre();
	scanf("%s" , str);
	n = strlen(str);
	ans = 1;
	for(int i = 0 ; i < n ; ++i){
		solve(mp[str[i]]);
	}
	printf("%d\n" , ans);
}
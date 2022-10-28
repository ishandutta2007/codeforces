#include "bits/stdc++.h"
using namespace std;
const int B = 11;
int t;
int b;
long long l , r;
vector < int > v;
long long dp[B][70][1 << B][2];
long long solve(int pos , int mask , int started){
	if(pos < 0){
		return !mask;
	}
	if(dp[b][pos][mask][started] != -1){
		return dp[b][pos][mask][started];
	}
	long long res = 0;
	if(started){
		res += solve(pos - 1 , mask ^ 1 , 1);
	}
	else{
		res += solve(pos - 1 , 0 , 0);
	}
	for(int i = 1 ; i < b ; ++i){
		res += solve(pos - 1 , mask ^ (1 << i) , 1);
	}
	return dp[b][pos][mask][started] = res;
}
long long solve(long long n , int base){
	if(n == 0){
		return 1;
	}
	v.clear();
	long long tmp = n;
	while(tmp){
		v.push_back(tmp % base);
		tmp /= base;
	}
	int mask = 0;
	long long res = 0;
	bool start = 0;
	for(int i = v.size() - 1 ; i >= 0 ; --i){
		for(int j = 0 ; j < v[i] ; ++j){
			if(start){
				res += solve(i - 1 , mask ^ (1 << j) , 1);
			}
			else{
				if(j){
					res += solve(i - 1 , 1 << j , 1);
				}
				else{
					res += solve(i - 1 , 0 , 0);
				}
			}
		}
		start = 1;
		mask ^= 1 << v[i];
	}
	res += !mask;
	return res;
}
int main(){
	scanf("%d" , &t);
	memset(dp , -1 , sizeof(dp));
	while(t--){
		scanf("%d" , &b);
		scanf("%lld %lld" , &l , &r);
		printf("%lld\n" , solve(r , b) - solve(l - 1 , b));
	}
}
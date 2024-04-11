#include "bits/stdc++.h"
using namespace std;
const int N = 2005;
const int mod = 998244353;
int t;
int n;
int arr[N];
int len[N];
int fact[N];
int tot;
int idx;
int dp[N][11][N];
int when[N][11][N];
int tc;
int pascal[N][N];
int get(int x){
	int res = 0;
	while(x){
		++res;
		x /= 10;
	}
	return res;
}
pair < int , int > a[N];
int oddpos , evenpos;
//ateven + evenpos - 1 C ateven
//atodd + oddpos - 1 C atodd
int solve(int pos , int num , int atodd , int ateven){
	int m1 = atodd;
	int mult = 1;
	if(pos == idx + 1){
		mult = (1LL * mult * fact[atodd]) % mod;
		mult = (1LL * mult * fact[ateven]) % mod;
		mult = (1LL * mult * pascal[ateven + evenpos - 1][ateven]) % mod;
		if(atodd && !oddpos){
			mult = 0;
		}
		else{
			if(oddpos){
				mult = (1LL * mult * pascal[atodd + oddpos - 1][atodd]) % mod;
			}
		}
		atodd = 0;
		ateven = 0;
	}
	if(pos > n){
		if(num){
			return 0;
		}
		if(ateven - atodd != (tot & 1)){
			return 0;
		}
		mult = (1LL * mult * fact[atodd]) % mod;
		mult = (1LL * mult * fact[ateven]) % mod;
		return mult;
	}
	if(when[pos][num][m1] == tc){
		return dp[pos][num][m1];
	}
	int res = 0;
	res += solve(pos + 1 , (num + a[pos].first) % 11 , atodd , ateven + 1);
	res += solve(pos + 1 , (((num - a[pos].first) % 11) + 11) % 11 , atodd + 1 , ateven);
	res = (1LL * res * mult) % mod;
	when[pos][num][m1] = tc;
	return dp[pos][num][m1] = res;
}
/*
int brute(){
	vector < int > v;
	v.clear();
	for(int i = 1 ; i <= n ; ++i){
		v.emplace_back(i);
	}
	int ans = 0;
	do{
		string str = "";
		for(int x : v){
			str += to_string(arr[x]);
		}
		int num = 0;
		for(char c : str){
			num = (num * 10 + c - '0') % 11;
		}
		ans += num == 0;
	}
	while(next_permutation(v.begin() , v.end()));
	return ans;
}*/
int main(){
	fact[0] = 1;
	for(int i = 1 ; i < N ; ++i){
		fact[i] = (1LL * fact[i - 1] * i) % mod;
	}
	for(int i = 0 ; i < N ; ++i){
		pascal[i][0] = 1;
		for(int j = 1 ; j <= i ; ++j){
			pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
			pascal[i][j] -= (pascal[i][j] >= mod) * mod;
		}
	}
	scanf("%d" , &t);
	while(t--){
		scanf("%d" , &n);
		for(int i = 1 ; i <= n ; ++i){
			scanf("%d" , arr + i);
		}
		tot = 0;
		for(int i = 1 ; i <= n ; ++i){
			len[i] = get(arr[i]);
			tot += len[i];
		}
		for(int i = 1 ; i <= n ; ++i){
			a[i] = make_pair(arr[i] , len[i]);
		}
		sort(a + 1 , a + 1 + n , [](pair < int , int > x , pair < int , int > y){
			if((x.second & 1) == (y.second & 1)){
				return x.first < y.first;
			}
			return (x.second & 1) < (y.second & 1);
		});
		idx = 0;
		oddpos = 0;
		evenpos = 0;
		int cnt = 0;
		for(int i = 1 ; i <= n ; ++i){
			if((a[i].second & 1) == 0){
				idx = i;
			}
			else{
				++cnt;
			}
		}
		evenpos = cnt + 1 >> 1;
		oddpos = cnt >> 1;
		if(cnt & 1){
			++oddpos;
		}
		else{
			++evenpos;
		}
		++tc;
		int tmp = solve(1 , 0 , 0 , 0);
		printf("%d\n" , tmp);
		//printf("Brute : %d\n" , brute());
	}
}
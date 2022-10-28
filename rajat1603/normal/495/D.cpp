#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
const int LN = 19;
char s[N];
char t[N];
int n , m;
char str[N + N];
int who[N + N];
int len;
int lcp[N + N];
int sa[LN][N + N];
int finalsa[N + N];
pair < pair < int , int > , int > tmp[N + N];
int start[N];
void build(){
	for(int i = 1 ; i <= len ; ++i){
		sa[0][i] = str[i];
	}
	for(int i = 1 ; i < LN ; ++i){
		for(int j = 1 ; j <= len ; ++j){
			int x = j + (1 << (i - 1));
			tmp[j] = {{sa[i - 1][j] , (x <= len) ? sa[i - 1][x] : -1} , j};
		}
		sort(tmp + 1 , tmp + 1 + len);
		int cur = 0;
		tmp[0] = {{-5 , -6} , -1};
		for(int j = 1 ; j <= len ; ++j){
			cur += tmp[j - 1].first != tmp[j].first;
			sa[i][tmp[j].second] = cur;
		}
	}
	for(int i = 1 ; i <= len ; ++i){
		finalsa[sa[LN - 1][i]] = i;
	}
	for(int i = 1 ; i < len ; ++i){
		int x = finalsa[i];
		int y = finalsa[i + 1];
		for(int j = LN - 1 ; j >= 0 ; --j){
			if(sa[j][x] == sa[j][y]){
				x += 1 << j;
				y += 1 << j;
				lcp[i] += 1 << j;
			}
		}
	}
}
int add(int a , int b){
	int res = a + b;
	if(res >= mod){
		return res - mod;
	}
	return res;
}
int mult(int a , int b){
	long long res = a;
	res *= b;
	if(res >= mod){
		return res % mod;
	}
	return res;
}
int dp1[N];
int dp2[N];
int getsum(int pos);
int solve(int pos){
	if(pos > n){
		return 1;
	}
	if(dp1[pos] != -1){
		return dp1[pos];
	}
	int res = solve(pos + 1);
	int idx = start[pos] + m - 1;
	res = add(res , getsum(idx + 1));
	return dp1[pos] = res;
}
int getsum(int idx){
	if(idx > n + 1){
		return 0;
	}
	if(dp2[idx] != -1){
		return dp2[idx];
	}
	return dp2[idx] = add(getsum(idx + 1) , solve(idx));
}
int main(){
	scanf("%s" , s + 1);
	n = strlen(s + 1);
	scanf("%s" , t + 1);
	m = strlen(t + 1);
	len = 0;
	for(int i = 1 ; i <= n ; ++i){
		++len;
		str[len] = s[i];
		who[len] = i;
	}
	++len;
	str[len] = '$';
	who[len] = 0;
	++len;
	str[len] = t[1];
	who[len] = n + 1;
	for(int i = 2 ; i <= m ; ++i){
		++len;
		str[len] = t[i];
		who[len] = 0;
	}
	build();
	for(int i = 1 ; i <= n ; ++i){
		start[i] = n + 1;
	}
	for(int i = 1 ; i <= len ; ++i){
		int x = finalsa[i];
		if(who[x] == n + 1){
			for(int j = i - 1 ; j >= 1 ; --j){
				if(lcp[j] < m){
					break;
				}
				if(who[finalsa[j]] >= 1 && who[finalsa[j]] <= n){
					start[who[finalsa[j]]] = who[finalsa[j]]; 
				}
			}
			for(int j = i ; j < len ; ++j){
				if(lcp[j] < m){
					break;
				}
				if(who[finalsa[j + 1]] >= 1 && who[finalsa[j + 1]] <= n){
					start[who[finalsa[j + 1]]] = who[finalsa[j + 1]];
				}
			}
			break;
		}
	}
	for(int i = n - 1 ; i >= 1 ; --i){
		start[i] = min(start[i] , start[i + 1]);
	}
	memset(dp1 , -1 , sizeof(dp1));
	memset(dp2 , -1 , sizeof(dp2));
	cout << add(solve(1) , mod - 1);
}
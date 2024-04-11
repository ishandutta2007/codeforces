#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , m;
char a[N];
char b[N];
int findwtf[N][26];
int suf[N];
int ahocorasick(int idx , int c){
	if(findwtf[idx][c] != -1){
		return findwtf[idx][c];
	}
	if(idx < m && b[idx + 1] - 'a' == c){
		return findwtf[idx][c] = idx + 1;
	}
	return findwtf[idx][c] = ahocorasick(suf[idx] , c);
}
vector < int > dp[N];
vector < int > v[N];
int solve(int pos , int idx){
	if(pos > n){
		return idx == m;
	}
	if(dp[pos][idx] != -1){
		return dp[pos][idx];
	}
	int res = idx == m;
	if(a[pos] == '?'){
		int tmp = 0;
		for(int next : v[idx]){
			tmp = max(tmp , solve(pos + 1 , next));
		}
		res += tmp;
	}
	else{
		res += solve(pos + 1 , findwtf[idx][a[pos] - 'a']);
	}
	return dp[pos][idx] = res;
}
int main(){
	scanf("%s" , a + 1);
	scanf("%s" , b + 1);
	n = strlen(a + 1);
	m = strlen(b + 1);
	memset(findwtf , -1 , sizeof(findwtf));
	memset(suf , 0 , sizeof(suf));
	for(int i = 0 ; i < 26 ; ++i){
		findwtf[0][i] = findwtf[1][i] = 0;
	}
	findwtf[0][b[1] - 'a'] = 1;
	findwtf[1][b[1] - 'a'] = 1;
	if(m > 1){
		findwtf[1][b[2] - 'a'] = 2;
	}
	suf[1] = 0;
	for(int i = 2 ; i <= m ; ++i){
		int idx = suf[i - 1];
		while(idx){
			if(b[idx + 1] == b[i]){
				break;
			}
			idx = suf[idx];
		}
		if(b[idx + 1] == b[i]){
			suf[i] = idx + 1;
		}
		else{
			suf[i] = 0;
		}
		if(i < m){
			findwtf[i][b[i + 1] - 'a'] = i + 1;
		}
		for(int j = 0 ; j < 26 ; ++j){
			findwtf[i][j] = ahocorasick(i , j);
		}
	}
	for(int i = 0 ; i <= n + 1 ; ++i){
		dp[i].clear();
		dp[i].resize(m + 2 , -1);
	}
	for(int i = 0 ; i <= m ; ++i){
		v[i].clear();
		for(int j = 0 ; j < 26 ; ++j){
			v[i].emplace_back(findwtf[i][j]);
		}
		sort(v[i].begin() , v[i].end());
		v[i].resize(unique(v[i].begin() , v[i].end()) - v[i].begin());
	}
	printf("%d\n" , solve(1 , 0));
}
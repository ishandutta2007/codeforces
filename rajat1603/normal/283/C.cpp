#include "bits/stdc++.h"
using namespace std;
const int N = 305;
const int T = 1e5 + 5;
const int mod = 1e9 + 7;
int n , q , t;
int arr[N];
int nxt[N];
int prv[N];
int a , b;
bool visited[N];
vector < int > v;
int dp[T];
int add(int a , int b){
	int res = a + b;
	if(res >= mod){
		return res - mod;
	}
	return res;
}
int main(){
	scanf("%d %d %d" , &n , &q , &t);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
		nxt[i] = -1;
		prv[i] = -1;
		visited[i] = 0;
	}
	for(int i = 1 ; i <= q ; ++i){
		scanf("%d %d" , &a , &b);
		nxt[a] = b;
		prv[b] = a;
	}
	v.clear();
	for(int i = 1 ; i <= n ; ++i){
		if(prv[i] == -1){
			int node = i;
			int sum = 0;
			do{
				visited[node] = 1;
				sum += arr[node];
				node = nxt[node];
				t -= sum * (node > 0);
				t = max(t , -1);
				v.emplace_back(sum);
			}while(node != -1);
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		if(!visited[i]){
			t = -1;
		}
	}
	if(t < 0){
		printf("0\n");
		return 0;
	}
	dp[0] = 1;
	for(auto it : v){
		for(int i = it ; i <= t ; ++i){
			dp[i] = add(dp[i] , dp[i - it]);
		}
	}
	printf("%d\n" , dp[t]);
}
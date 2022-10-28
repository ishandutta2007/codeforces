#include "bits/stdc++.h"
using namespace std;
const int N = 5e5 + 5;
const int M = 75;
int n;
double dp[N][M];
vector < int > v[N];
int type , node;
int cur;
int parent[N];
void insert(int par){
	int node = ++cur;
	parent[node] = par;
	for(int i = 0 ; i < M ; ++i){
		dp[node][i] = 1;
	}
	int last = node;
	node = parent[node];
	int cur = 1;
	double old = 1;
	double tmp;
	double old2 = 1;
	double tmp2;
	while(node && cur < M){
		tmp = dp[node][cur];
		dp[node][cur] /= (old + 1) / 2;
		dp[node][cur] *= (dp[last][cur - 1] + 1) / 2;
		tmp2 = dp[node][cur - 1];
		dp[node][cur - 1] /= (old2 + 1) / 2;
		dp[node][cur - 1] *= (((cur > 1) ? dp[last][cur - 2] : 0) + 1) / 2;
		last = node;
		node = parent[node];
		++cur;
		old = tmp;
		old2 = tmp2;
	}
}
double query(int node){
	double ans = 0;
	for(int i = 1 ; i < M ; ++i){
		ans += (dp[node][i] - dp[node][i - 1]) * i;
	}
	return ans;
}
int main(){
	scanf("%d" , &n);
	cur = 1;
	for(int i = 0 ; i < M ; ++i){
		dp[1][i] = 1;
	}
	while(n--){
		scanf("%d %d" , &type , &node);
		if(type == 1){
			insert(node);
		}
		else{
			printf("%.9lf\n" , query(node));
		}
	}
}
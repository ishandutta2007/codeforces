#include "bits/stdc++.h"
using namespace std;
const int N = 34;
const int M = 70;
int n;
int arr[N];
int dp[N][M * M][M];
int find(int pos , int sum , int cnt){
	if(pos > n){
		return (sum * 2 == cnt * (cnt - 1)) ? cnt : M;
	}
	if(dp[pos][sum][cnt] != -1){
		return dp[pos][sum][cnt];
	}
	int res = M;
	int cur = sum;
	int tot = cnt;
	for(int i = 1 ; tot < 65 ; ++i){
		++tot;
		cur += arr[pos];
		if(cur * 2 >= tot * (tot - 1)){
			res = min(res , find(pos + 1 , cur , tot));
		}
	}
	return dp[pos][sum][cnt] = res;
}
int deg[M];
void go(int pos , int sum , int cnt){
	if(pos > n){
		return;
	}
	int cur = sum;
	int tot = cnt;
	for(int i = 1 ; tot < 65 ; ++i){
		++tot;
		cur += arr[pos];
		deg[tot] = arr[pos];
		if(cur * 2 >= tot * (tot - 1)){
			if(find(pos + 1 , cur , tot) == find(pos , sum , cnt)){
				go(pos + 1 , cur , tot);
				return;
			}
		}
	}
}
int graph[M][M];
pair < int , int > out[M];
int main(){
	cin >> n;
	for(int i = 1 ; i <= n ; ++i){
		cin >> arr[i];
	}
	sort(arr + 1 , arr + 1 + n);
	memset(dp , -1 , sizeof(dp));
	int m = find(1 , 0 , 0);
	go(1 , 0 , 0);
	for(int i = 1 ; i <= m ; ++i){
		out[i] = make_pair(deg[i] , i);
	}
	sort(out + 1 , out + 1 + m);
	for(int i = 1 ; i <= m ; ++i){
		for(int j = i + 1 ; j <= i + out[i].first ; ++j){
			graph[out[i].second][out[j].second] = 1;
		}
		for(int j = i + out[i].first + 1 ; j <= m ; ++j){
			graph[out[j].second][out[i].second] = 1;
			--out[j].first;
		}
		out[i].first = 0;
		sort(out + i + 1 , out + 1 + m);
	}
	printf("%d\n" , m);
	for(int i = 1 ; i <= m ; ++i){
		for(int j = 1 ; j <= m ; ++j){
			printf("%d" , graph[i][j]);
		}
		printf("\n");
	}
}
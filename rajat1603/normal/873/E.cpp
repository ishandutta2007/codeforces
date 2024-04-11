#include "bits/stdc++.h"
using namespace std;
const int N = 3e3 + 3;
int n;
pair < int , int > arr[N];
pair < int , pair < int , int > > ans;
int ansi , ansj , ansk;
int cost[N];
int mini[N][N];
int who[N][N];
void solve(int one , int two){
	if(one > two * 2 || two > one * 2){
		return;
	}
	int l1 = 1;
	int r1 = one;
	int l2 = r1 + 1;
	int r2 = l2 + two - 1;
	int l3 = r2 + 1;
	int start = l3 + min(one , two) - 1;
	int finish = l3 + min(one , two) * 2 - 1;
	finish = min(finish , n);
	if(finish - start + 1 > 0){
		pair < int , pair < int , int > >  tot = {cost[r1] , {cost[r2] , mini[start][finish]}};
		if(tot > ans){
			ans = tot;
			ansi = r1;
			ansj = r2;
			ansk = who[start][finish];
		}
	}
	int three = (max(one , two) + 1) / 2;
	start = l3 + three - 1;
	finish = l3 + min(one , two) - 1;
	finish = min(finish , n);
	if(finish - start + 1 > 0){
		pair < int , pair < int , int > >  tot = {cost[r1] , {cost[r2] , mini[start][finish]}};
		if(tot > ans){
			ans = tot;
			ansi = r1;
			ansj = r2;
			ansk = who[start][finish];
		}
	}
}
int print[N];
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , &arr[i].first);
		arr[i].second = i;
	}
	sort(arr + 1 , arr + 1 + n);
	reverse(arr + 1 , arr + 1 + n);
	arr[n + 1].first = 0;
	for(int i = 1 ; i <= n ; ++i){
		cost[i] = arr[i].first - arr[i + 1].first;
	}
	for(int i = 1 ; i <= n ; ++i){
		mini[i][i] = cost[i];
		who[i][i] = i;
		for(int j = i + 1 ; j <= n ; ++j){
			mini[i][j] = max(mini[i][j - 1] , cost[j]);
			who[i][j] = who[i][j - 1];
			if(cost[j] == mini[i][j]){
				who[i][j] = j;
			}
		}
	}
	ans = {-1 , {-1 , -1}};
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= n ; ++j){
			solve(i , j);
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		if(i <= ansi){
			print[arr[i].second] = 1;
		}
		else if(i <= ansj){
			print[arr[i].second] = 2;
		}
		else if(i <= ansk){
			print[arr[i].second] = 3;
		}
		else{
			print[arr[i].second] = -1;
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		printf("%d%c" , print[i] , " \n"[i == n]);
	}
}
#include "bits/stdc++.h"
using namespace std;
const int inf = 1e9 + 9;
int n , m , a , b;
int solve(int x , int y){
	if(x % a){
		return inf;
	}
	if(y % b){
		return inf;
	}
	int stepa = x / a;
	int stepb = y / b;
	if((stepa % 2) != (stepb % 2)){
		return inf;
	}
	if(stepb == 0 && stepa > 0 && b >= m - y){
		return inf;
	}
	if(stepa == 0 && stepb > 0 && a >= n - x){
		return inf;
	}
	return max(stepa , stepb);
}
int main(){
	int x , y;
	cin >> n >> m;
	cin >> x >> y;
	cin >> a >> b;
	int ans = inf;
	ans = min(ans , solve(x - 1 , y - 1));
	ans = min(ans , solve(x - 1 , m - y));
	ans = min(ans , solve(n - x , y - 1));
	ans = min(ans , solve(n - x , m - y));
	if(ans == inf){
		printf("Poor Inna and pony!\n");
	}
	else{
		printf("%d\n" , ans);
	}
}
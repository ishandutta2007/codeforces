#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int ax , ay;
int bx , by;
int tx , ty;
int n;
int x[N];
int y[N];
double prebest[N];
double sufbest[N];
double sum = 0;
double ans = 1e18;
long long sqr(int x){
	return 1LL * x * x;
}
int main(){
	scanf("%d %d %d %d %d %d" , &ax , &ay , &bx , &by , &tx , &ty);
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d %d" , x + i , y + i);
	}
	for(int i = 1 ; i <= n ; ++i){
		sum += sqrt(sqr(tx - x[i]) + sqr(ty - y[i]));
	}
	sum *= 2;
	for(int i = 1 ; i <= n ; ++i){
		ans = min(ans , sum + sqrt(sqr(ax - x[i]) + sqr(ay - y[i])) - sqrt(sqr(tx - x[i]) + sqr(ty - y[i])));
	}
	for(int i = 1 ; i <= n ; ++i){
		ans = min(ans , sum + sqrt(sqr(bx - x[i]) + sqr(by - y[i])) - sqrt(sqr(tx - x[i]) + sqr(ty - y[i])));
	}
	for(int i = 1 ; i <= n ; ++i){
		prebest[i] = sufbest[i] = sqrt(sqr(bx - x[i]) + sqr(by - y[i])) - sqrt(sqr(tx - x[i]) + sqr(ty - y[i]));
	}
	for(int i = 2 ; i <= n ; ++i){
		prebest[i] = min(prebest[i] , prebest[i - 1]);
	}
	for(int i = n - 1 ; i >= 1 ; --i){
		sufbest[i] = min(sufbest[i] , sufbest[i + 1]);
	}
	prebest[0] = 1e18;
	sufbest[n + 1] = 1e18;
	for(int i = 1 ; i <= n ; ++i){
		ans = min(ans , sqrt(sqr(ax - x[i]) + sqr(ay - y[i])) + sum - sqrt(sqr(tx - x[i]) + sqr(ty - y[i])) + min(prebest[i - 1] , sufbest[i + 1]));
	}
	printf("%.9lf\n" , ans);
}
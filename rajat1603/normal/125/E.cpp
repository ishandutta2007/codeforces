#include "bits/stdc++.h"
using namespace std;
const int N = 5e3 + 3;
const int M = 1e5 + 5;
int n , m , k;
int a[M] , b[M] , c[M];
pair < pair < double , int > , pair < int , int > > arr[M];
int parent[N];
int find(int node){
	if(parent[node] == node){
		return node;
	}
	return parent[node] = find(parent[node]);
}
bool join(int a , int b){
	int x = find(a);
	int y = find(b);
	if(x == y){
		return 0;
	}
	parent[y] = x;
	return 1;
}
int ans[N];
int siz;
int check(double bonus , bool print){
	for(int i = 1 ; i <= m ; ++i){
		arr[i].second.first = a[i];
		arr[i].second.second = b[i];
		arr[i].first.second = i;
		if(a[i] == 1 || b[i] == 1){
			arr[i].first.first = c[i] + bonus;
		}
		else{
			arr[i].first.first = c[i];
		}
	}
	sort(arr + 1 , arr + 1 + m);
	int tot = 0 , totk = 0;
	for(int i = 1 ; i <= n ; ++i){
		parent[i] = i;
	}
	for(int i = 1 ; i <= m ; ++i){
		if(join(arr[i].second.first , arr[i].second.second)){
			if(arr[i].second.first == 1 || arr[i].second.second == 1){
				++totk;
			}
			++tot;
			if(print){
				ans[++siz] = arr[i].first.second;
			}
		}
	}
	if(tot < n - 1){
		printf("-1\n");
		exit(0);
	}
	return totk;
}
int main(){
	scanf("%d %d %d" , &n , &m , &k);
	for(int i = 1 ; i <= m ; ++i){
		scanf("%d %d %d" , &a[i] , &b[i] , &c[i]);
	}
	double l = -1e6;
	double r = 1e6;
	for(int i = 0 ; i < 100 ; ++i){
		double mid = (l + r) / 2;
		if(check(mid , 0) < k){
			r = mid;
		}
		else{
			l = mid;
		}
	}
	if(check(l , 1) == k){
		printf("%d\n" , n - 1);
		for(int i = 1 ; i < n ; ++i){
			printf("%d " , ans[i]);
		}
		printf("\n");
	}
	else{
		printf("-1\n");
	}
}
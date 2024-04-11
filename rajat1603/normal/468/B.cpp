#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , a , b;
int arr[N];
int parent[N];
int mask[N];
vector < pair < int , int > > v;
int find(int node){
	if(parent[node] == node){
		return node;
	}
	return parent[node] = find(parent[node]);
}
void merge(int a , int b){
	int x = find(a);
	int y = find(b);
	if(x != y){
		parent[y] = x;
		mask[x] &= mask[y];
	}
}
int main(){
	scanf("%d %d %d" , &n , &a , &b);
	v.resize(n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
		v[i - 1] = {arr[i] , i};
	}
	sort(v.begin() , v.end());
	for(int i = 1 ; i <= n ; ++i){
		parent[i] = i;
		mask[i] = 3;
	}
	for(int i = 1 ; i <= n ; ++i){
		int vala = a - arr[i];
		int valb = b - arr[i];
		auto ita = lower_bound(v.begin() , v.end() , make_pair(vala , -1));
		auto itb = lower_bound(v.begin() , v.end() , make_pair(valb , -1));
		if(ita == v.end() || ita -> first != vala){
			mask[find(i)] &= ~1;
		}
		else{
			merge(i , ita -> second);
		}
		if(itb == v.end() || itb -> first != valb){
			mask[find(i)] &= ~2;
		}
		else{
			merge(i , itb -> second);
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		if(mask[i] == 0){
			printf("NO\n");
			return 0;
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		if(mask[i] == 3){
			mask[i] = 1 + (rand() & 1);
		}
	}
	printf("YES\n");
	for(int i = 1 ; i <= n ; ++i){
		printf("%d%c" , mask[find(i)] - 1 , " \n"[i == n]);
	}
}
#include "bits/stdc++.h"
using namespace std;
const int N = 105;
int n , m;
int a[N] , b[N];
vector < int > v[N];
int color[N];
int intersect(int l , int r , int ql , int qr){
	if(l >= qr || r <= ql){
		return 0;
	}
	if(l >= ql && r <= qr){
		return 0;
	}
	if(ql >= l && qr <= r){
		return 0;
	}
	return 1;
}
void dfs(int node){
	for(int next : v[node]){
		if(color[next] == -1){
			color[next] = !color[node];
			dfs(next);
		}
		if(color[next] == color[node]){
			cout << "Impossible\n";
			exit(0);
		}
	}
}
int main(){
	//bc denial of judgement mat de
	cin >> n >> m;
	for(int i = 1 ; i <= m ; ++i){
		cin >> a[i] >> b[i];
	}
	for(int i = 1 ; i <= m ; ++i){
		for(int j = 1 ; j <= m ; ++j){
			if(intersect(min(a[i] , b[i]) , max(a[i] , b[i]) , min(a[j] , b[j]) , max(a[j] , b[j]))){
				v[i].emplace_back(j);
			}
		}
	}
	memset(color , -1 , sizeof(color));
	for(int i = 1 ; i <= m ; ++i){
		if(color[i] == -1){
			color[i] = 0;
			dfs(i);
		}
	}
	for(int i = 1 ; i <= m ; ++i){
		if(color[i]){
			cout << "o";
		}
		else{
			cout << "i";
		}
	}
}
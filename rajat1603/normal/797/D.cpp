#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
int val[N] , lft[N] , rgt[N];
int root;
int mark[N];
int ql[N] , qr[N];
void dfs(int node , int l , int r){
	ql[node] = l;
	qr[node] = r;
	if(lft[node] > 0){
		dfs(lft[node] , l , min(val[node] - 1 , r));
	}
	if(rgt[node] > 0){
		dfs(rgt[node] , max(l , val[node] + 1) , r);
	}
}
pair < int , int > arr[N];
bool ok(int node){
	if(val[node] >= ql[node] && val[node] <= qr[node]){
		return 1;
	}
	return 0;
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d %d %d" , val + i , lft + i , rgt + i);
		if(lft[i] > 0){
			mark[lft[i]] = 1;
		}
		if(rgt[i] > 0){
			mark[rgt[i]] = 1;
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		if(!mark[i]){
			root = i;
		}
	}
	dfs(root , 0 , 1000000000);
	for(int i = 1 ; i <= n ; ++i){
		arr[i] = make_pair(val[i] , i);
	}
	sort(arr + 1 , arr + 1 + n);
	int ans = 0;
	for(int i = 1 ; i <= n ; ++i){
		int j = i;
		bool done = ok(arr[j].second);
		while(j < n && arr[j + 1].first == arr[j].first){
			++j;
			done |= ok(arr[j].second);
		}
		if(done){
			ans += j - i + 1;
		}
		i = j;
	}
	printf("%d\n" , n - ans);
}
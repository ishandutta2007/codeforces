#include "bits/stdc++.h"
using namespace std;
const int N = 4e4 + 4;
const int K = 55;
const int SN = 1 << 17;
int n , k;
int arr[N];
int nxt[N];
int lst[N];
int dp[K][N];
int segtree[SN];
int lazy[SN];
void build(int l , int r , int node , int cur){
	lazy[node] = 0;
	if(l == r){
		segtree[node] = dp[cur - 1][r + 1];
	}
	else{
		int mid = l + r >> 1;
		build(l , mid , node + node , cur);
		build(mid + 1 , r , node + node + 1 , cur);
		segtree[node] = max(segtree[node + node] , segtree[node + node + 1]);
	}
}
void push(int l , int r , int node){
	if(lazy[node]){
		segtree[node] += lazy[node];
		if(l != r){
			lazy[node + node] += lazy[node];
			lazy[node + node + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}
void update(int l , int r , int node , int ql , int qr){
	push(l , r , node);
	if(l > qr || r < ql){
		return;
	}
	if(l >= ql && r <= qr){
		++lazy[node];
		push(l , r , node);
		return;
	}
	int mid = l + r >> 1;
	update(l , mid , node + node , ql , qr);
	update(mid + 1 , r , node + node + 1 , ql , qr);
	segtree[node] = max(segtree[node + node] , segtree[node + node + 1]);
}
int query(int l , int r , int node , int ql , int qr){
	push(l , r , node);
	if(l > qr || r < ql){
		return 0;
	}
	if(l >= ql && r <= qr){
		return segtree[node];
	}
	int mid = l + r >> 1;
	return max(query(l , mid , node + node , ql , qr) , query(mid + 1 , r , node + node + 1 , ql , qr));
}
int main(){
	scanf("%d %d" , &n , &k);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	for(int i = 1 ; i <= n ; ++i){
		lst[i] = n + 1;
	}
	for(int i = n ; i >= 1 ; --i){
		nxt[i] = lst[arr[i]];
		lst[arr[i]] = i;
	}
	memset(lst , 0 , sizeof(lst));
	dp[1][n + 1] = 0;
	for(int i = n ; i >= 1 ; --i){
		dp[1][i] = dp[1][i + 1] + (!lst[arr[i]]);
		lst[arr[i]] = i;
	}
	/*for(int i = 1 ; i <= n ; ++i){
		cout << dp[1][i] << " ";
	}
	cout << endl;*/
	for(int i = 2 ; i <= k ; ++i){
		build(1 , n , 1 , i);
		for(int j = n ; j >= 1 ; --j){
			update(1 , n , 1 , j , nxt[j] - 1);
			dp[i][j] = query(1 , n , 1 , j , n);
		}
		/*for(int j = 1 ; j <= n ; ++j){
			cout << dp[i][j] << " ";
		}
		cout << endl;*/
	}
	printf("%d\n" , dp[k][1]);
}
#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int LN = 17;
int n;
int inp;
vector < int > v[N];
int treeroot;
int depth[N];
int tin[N];
int tout[N];
int rev[N];
int timer = 0;
int dp[LN][N];
void dfs(int node){
	tin[node] = ++timer;
	rev[timer] = node;
	for(int next : v[node]){
		depth[next] = depth[node] + 1;
		dp[0][next] = node;
		dfs(next);
	}
	tout[node] = timer;
}
int lca(int a , int b){
	if(depth[a] < depth[b]){
		swap(a , b);
	}
	int dif = depth[a] - depth[b];
	for(int i = 0 ; i < LN ; ++i){
		if(dif & (1 << i)){
			a = dp[i][a];
		}
	}
	if(a != b){
		for(int i = LN - 1 ; i >= 0 ; --i){
			if(dp[i][a] != dp[i][b]){
				a = dp[i][a];
				b = dp[i][b];
			}
		}
		a = dp[0][a];
	}
	return a;
}
struct node{
	int sum;
	int left;
	int right;
	node(){
		sum = 0;
		left = 0;
		right = 0;
	}
};
node st[N * LN * 2];
int root[N];
int cur = 0;
int newnode(int sum , int left , int right){
	++cur;
	st[cur].sum = sum;
	st[cur].left = left;
	st[cur].right = right;
	return cur;
}
void build(int l , int r , int &node){
	node = newnode(0 , 0 , 0);
	if(l == r){
		st[node].sum = depth[rev[l]] - depth[rev[l - 1]];
	}
	else{
		int mid = l + r >> 1;
		build(l , mid , st[node].left);
		build(mid + 1 , r , st[node].right);
		st[node].sum = st[st[node].left].sum + st[st[node].right].sum;
	}
}
int q;
int type;
int a , b , c , d;
void update(int old , int &node , int l , int r , int idx , int val){
	node = newnode(st[old].sum + val , 0 , 0);
	if(l < r){
		int mid = l + r >> 1;
		if(idx <= mid){
			update(st[old].left , st[node].left , l , mid , idx , val);
			st[node].right = st[old].right;
		}
		else{
			update(st[old].right , st[node].right , mid + 1 , r , idx , val);
			st[node].left = st[old].left;
		}
	}
}
int query(int l , int r , int node , int ql , int qr){
	if(l > qr || r < ql){
		return 0;
	}
	if(l >= ql && r <= qr){
		return st[node].sum;
	}
	int mid = l + r >> 1;
	return query(l , mid , st[node].left , ql , qr) + query(mid + 1 , r , st[node].right , ql , qr);
}
int sum(int top , int bottom , int idx){
	int ret = query(1 , n , root[idx] , 1 , tin[bottom]);
	if(top != treeroot){
		ret -= query(1 , n , root[idx] , 1 , tin[dp[0][top]]);
	}
	return ret;
}
int getsum(int top , int bottom , int idx1 , int idx2){
	int ret = sum(top , bottom , idx2);
	ret -= sum(top , bottom , idx1 - 1);
	ret += depth[bottom] - depth[top] + 1;
	return ret;
}
void solveup(int bottom , int top , int k , int y , int idx){
	//cout << bottom << " " << top << " " << k << " " << y << " " << idx << endl;
	for(int i = LN - 1 ; i >= 0 ; --i){
		int nd = dp[i][bottom];
		if(!nd){
			continue;	
		}
		int tmp = getsum(nd , bottom , y , idx) - getsum(nd , nd , y , idx);
		if(tmp < k){
			//cout << bottom << " " << nd << " " << tmp << " " << k << endl;
			k -= tmp;
			bottom = nd;
		}
	}
	if(bottom == b){
		bottom = -1;
	}
	printf("%d\n" , bottom);
}
void solve(int a , int b , int k , int y , int idx){
	int lc = lca(a , b);
	if(getsum(a , a , y , idx)){
		++k;
	}
	int tmp1 = getsum(lc , a , y , idx);
	if(tmp1 >= k){
		solveup(a , lc , k , y , idx);
	}
	else{
		int tmp2 = getsum(lc , b , y , idx);
		int lcaval = getsum(lc , lc , y , idx);
		if(tmp1 + tmp2 - lcaval < k){
			printf("-1\n");
			return;
		}
		int tot = tmp1 + tmp2 - lcaval - (tmp1 - lcaval);
		k -= (tmp1 - lcaval);
		solveup(b , lc , tmp2 - k + 1 , y , idx);
	}
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , &inp);
		v[inp].emplace_back(i);
		if(!inp){
			treeroot = i;
		}
	}
	depth[treeroot] = 1;
	dfs(treeroot);
	for(int i = 1 ; i < LN ; ++i){
		for(int j = 1 ; j <= n ; ++j){
			dp[i][j] = dp[i - 1][dp[i - 1][j]];
		}
	}
	build(1 , n , root[0]);
	scanf("%d" , &q);
	for(int i = 1 ; i <= q ; ++i){
		scanf("%d" , &type);
		if(type == 1){
			scanf("%d" , &a);
			update(root[i - 1] , root[i] , 1 , n , tin[a] , -1);
			if(tout[a] + 1 <= n){
				update(root[i] , root[i] , 1 , n , tout[a] + 1 , 1);
			}
		}
		else{
			scanf("%d %d %d %d" , &a , &b , &c , &d);
			root[i] = root[i - 1];
			solve(a , b , c , d + 1 , i);
		}
	}
}
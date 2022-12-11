#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ll,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ab(x) ((x) < 0 ? -(x) : (x))

const int N = (int)2e5 + 12345;
vector<int>T[N];
int in[N];
int out[N];
int p;
const int TREE_SIZE = N * 2;
int lazy[TREE_SIZE * 2];
int value[TREE_SIZE * 2];

void dfs(int u){
	in[u] = ++p;
	for(auto x : T[u])
		dfs(x);
	out[u] = p;
}

void LazyUpdate(int node,int a,int b){
	if(lazy[node] == 0)
		return;
	lazy[node] = 0;
	value[node] = (b-a+1) - value[node];
	if(a!=b){
		lazy[node * 2] ^= 1;
		lazy[(node * 2) + 1] ^= 1;
	}
}

void upd(int node,int a,int b,int l,int r){
	LazyUpdate(node,a,b);
	if(a > r)
		return;
	if(b < l)
		return;
	if(a>b)
		return;
	if(a >= l and b <= r){
		lazy[node] ^= 1;
		LazyUpdate(node,a,b);
		return;
	}
	int m = (a+b)/2;
	upd(node*2,a,m,l,r);
	upd((node*2)+1,m+1,b,l,r);
	value[node] = value[node*2] + value[(node * 2) + 1];
}

int query(int node,int a,int b,int l,int r){
	LazyUpdate(node,a,b);
	if(a > r)
		return 0;
	if(b < l)
		return 0;
	if(a >= l and b <= r){
		return value[node];
	}
	return query(node*2,a,(a+b)/2,l,r) + query(node * 2 + 1,1+(a+b)/2,b,l,r);
	
}

int main(){
	fastIO;
	int n;
	cin >> n;
	int p ;
	for(int i =2 ;i<=n;i++){
		cin >> p;
		T[p].push_back(i);
	}	
	dfs(1);
	int x;
	for(int i = 1;i<=n;i++){
		cin >> x;
		if(x == 1){
			upd(1,1,n,in[i],in[i]);
		}
	}
	int q;
	cin >> q;
	string s;
	int u;
	for(int i = 0;i<q;i++){
		cin >> s >> u;
		if(s == "get")
			cout << query(1,1,n,in[u],out[u]) << "\n";
		else
			upd(1,1,n,in[u],out[u]);
	}
	return 0;
}
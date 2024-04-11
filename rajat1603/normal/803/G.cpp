#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int K = 1e4 + 4;
const int inf = 1e9 + 9;
const int SZ = 3e7 + 7;
int n , k;
int b[N];
struct data{
	int lft;
	int rgt;
	int ans;
	int laz;
	data(){
		lft = 0;
		rgt = 0;
		ans = inf;
		laz = -1;
	}
};
data segtree[SZ];
int cur;
int broot;
int mainroot;
void buildb(int l , int r , int &node){
	node = ++cur;
	if(l == r){
		segtree[node].ans = b[l];
	}
	else{
		int mid = l + r >> 1;
		buildb(l , mid , segtree[node].lft);
		buildb(mid + 1 , r , segtree[node].rgt);
		segtree[node].ans = min(segtree[segtree[node].lft].ans , segtree[segtree[node].rgt].ans);
	}
}
void buildmain(int l , int r , int &node){
	node = ++cur;
	if(l == r){
		segtree[node].lft = segtree[broot].lft;
		segtree[node].rgt = segtree[broot].rgt;
		segtree[node].ans = segtree[broot].ans;
		segtree[node].laz = segtree[broot].laz;
	}
	else{
		int mid = l + r >> 1;
		buildmain(l , mid , segtree[node].lft);
		buildmain(mid + 1 , r , segtree[node].rgt);
		segtree[node].ans = min(segtree[segtree[node].lft].ans , segtree[segtree[node].rgt].ans);
	}
}
void pre(){
	cur = 0;
	buildb(1 , n , broot);
	buildmain(1 , k , mainroot);
}
int q;
int type , l , r , x;
inline void pushb(int l , int r , int node){
	if(segtree[node].laz == -1){
		return;
	}
	segtree[node].ans = segtree[node].laz;
	if(l < r){
		int old = segtree[node].lft;
		segtree[node].lft = ++cur;
		segtree[cur].ans = segtree[old].ans;
		segtree[cur].lft = segtree[old].lft;
		segtree[cur].rgt = segtree[old].rgt;
		segtree[cur].laz = segtree[node].laz;
		old = segtree[node].rgt;
		segtree[node].rgt = ++cur;
		segtree[cur].ans = segtree[old].ans;
		segtree[cur].lft = segtree[old].lft;
		segtree[cur].rgt = segtree[old].rgt;
		segtree[cur].laz = segtree[node].laz;
	}
	segtree[node].laz = -1;
}
void updateb(int l , int r , int &node , int oldnode , int ql , int qr , int val){
	node = ++cur;
	segtree[node].ans = segtree[oldnode].ans;
	segtree[node].lft = segtree[oldnode].lft;
	segtree[node].rgt = segtree[oldnode].rgt;
	segtree[node].laz = segtree[oldnode].laz;
	pushb(l , r , node);
	if(l > qr || r < ql){
		return;
	}
	if(l >= ql && r <= qr){
		segtree[node].laz = val;
		pushb(l , r , node);
		return;
	}
	int mid = l + r >> 1;
	updateb(l , mid , segtree[node].lft , segtree[node].lft , ql , qr , val);
	updateb(mid + 1 , r , segtree[node].rgt , segtree[node].rgt , ql , qr , val);
	segtree[node].ans = min(segtree[segtree[node].lft].ans , segtree[segtree[node].rgt].ans);
}
inline void pushmain(int l , int r , int node){
	if(segtree[node].laz == -1){
		return;
	}
	segtree[node].ans = segtree[node].laz;
	if(l == r){
		int old = segtree[node].lft;
		segtree[node].lft = ++cur;
		segtree[cur].ans = segtree[old].ans;
		segtree[cur].lft = segtree[old].lft;
		segtree[cur].rgt = segtree[old].rgt;
		segtree[cur].laz = segtree[node].laz;
		old = segtree[node].rgt;
		segtree[node].rgt = ++cur;
		segtree[cur].ans = segtree[old].ans;
		segtree[cur].lft = segtree[old].lft;
		segtree[cur].rgt = segtree[old].rgt;
		segtree[cur].laz = segtree[node].laz;
	}
	else{
		segtree[segtree[node].lft].laz = segtree[node].laz;
		segtree[segtree[node].rgt].laz = segtree[node].laz;
	}
	segtree[node].laz = -1;
}
void updatemain(int l , int r , int &node , int ql , int qr , int val){
	pushmain(l , r , node);
	int lb = (l - 1) * n + 1;
	int rb = r * n;
	if(l == r){
		updateb(lb , rb , node , node , ql , qr , val);
	}
	else{
		if(lb > qr || rb < ql){
			return;
		}
		if(lb >= ql && rb <= qr){
			segtree[node].laz = val;
			pushmain(l , r , node);
			return;
		}
		int mid = l + r >> 1;
		updatemain(l , mid , segtree[node].lft , ql , qr , val);
		updatemain(mid + 1 , r , segtree[node].rgt , ql , qr , val);
		segtree[node].ans = min(segtree[segtree[node].lft].ans , segtree[segtree[node].rgt].ans);
	}
}
int queryb(int l , int r , int node , int ql , int qr , int laz){
	if(l > qr || r < ql){
		return inf;
	}
	if(laz == -1){
		laz = segtree[node].laz;
	}
	if(laz != -1){
		return laz;
	}
	if(l >= ql && r <= qr){
		return segtree[node].ans;
	}
	int mid = l + r >> 1;
	return min(queryb(l , mid , segtree[node].lft , ql , qr , laz) , queryb(mid + 1 , r , segtree[node].rgt , ql , qr , laz));
}
int querymain(int l , int r , int node , int ql , int qr , int laz){
	int lb = (l - 1) * n + 1;
	int rb = r * n;
	if(l == r){
		return queryb(lb , rb , node , ql , qr , laz);
	}
	if(lb > qr || rb < ql){
		return inf;
	}
	if(laz == -1){
		laz = segtree[node].laz;
	}
	if(laz != -1){
		return laz;
	}
	if(lb >= ql && rb <= qr){
		return segtree[node].ans;
	}
	int mid = l + r >> 1;
	return min(querymain(l , mid , segtree[node].lft , ql , qr , laz) , querymain(mid + 1 , r , segtree[node].rgt , ql , qr , laz));
}
int main(){
	scanf("%d %d" , &n , &k);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , b + i);
	}
	pre();
	scanf("%d" , &q);
	while(q--){
		scanf("%d %d %d" , &type , &l , &r);
		if(type == 1){
			scanf("%d" , &x);
			updatemain(1 , k , mainroot , l , r , x);
		}
		else{
			printf("%d\n" , querymain(1 , k , mainroot , l , r , -1));
		}
	}
}
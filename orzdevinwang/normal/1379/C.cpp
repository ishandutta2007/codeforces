#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m,splx,sply,root,a[100009],b[100009];
struct node {
	int son[2],siz,val,key,sizz;
} q[100009];
void upd(int x) {
	q[x].siz=q[q[x].son[0]].siz+q[q[x].son[1]].siz+q[x].val;
	q[x].sizz=q[q[x].son[0]].sizz+q[q[x].son[1]].sizz+1;
}
int new_root(int value,int now) {q[now].sizz=1,q[now].siz=q[now].val=value,q[now].key=rand();return now;}
int merge(int x,int y) { //x < y 
	if(!x||!y) return x+y;
	if(q[x].key<q[y].key) {
		q[x].son[1]=merge(q[x].son[1],y),upd(x);
		return x;
	}
	else {
		q[y].son[0]=merge(x,q[y].son[0]),upd(y);
		return y;
	}
}
void split(int now,int k,int &x,int &y) {
	if(!now) x=y=0;
	else {
		if(q[now].val<=k) x=now,split(q[now].son[1],k,q[now].son[1],y);
		else y=now,split(q[now].son[0],k,x,q[now].son[0]);
		upd(now);
	}
} 
int kth(int now,int k) {
	while(1) {
		if(k<=q[q[now].son[0]].siz) now=q[now].son[0];
		else if(k==q[q[now].son[0]].siz+1) return q[now].val;
		else k-=q[q[now].son[0]].siz+1,now=q[now].son[1];
	}
}
int ans;
signed main() {
	srand(1919810);
	scanf("%lld",&T);
	while(T--) {
		scanf("%lld%lld",&n,&m),swap(n,m);
		ans = 0;
		for(int i = 1; i <= n; i++) {
			scanf("%lld%lld",&a[i],&b[i]);
			split(root,a[i]-1,splx,sply);
			root = merge(merge(splx,new_root(a[i],i)),sply);
		}
		for(int i = 1; i <= n; i++) {
			split(root,b[i]-1,splx,sply);
			if(q[sply].sizz >= m) {
				root = merge(splx,sply);
				continue;
			}
			if(a[i] >= b[i]) ans = max(ans,q[sply].siz+(m-q[sply].sizz)*b[i]);
			else ans = max(ans,a[i]+q[sply].siz+(m-q[sply].sizz-1)*b[i]);
			root = merge(splx,sply);
		} 
		sort(a+1,a+n+1);
		int sum = 0;
		for(int i = n; i >= max(n-m+1,1ll); i--) sum += a[i];
		ans = max(ans,sum);
		printf("%lld\n",ans);
		root = 0;
		for(int i = 1; i <= n; i++) q[i].key = q[i].siz = q[i].son[0] = q[i].son[1] = q[i].val = 0;
	}
	return 0;
}
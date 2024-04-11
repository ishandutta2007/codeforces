#include<iostream>
#include<string>
#include<string.h>
#define lson rt<<1
#define rson rt<<1|1
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int maxn=3e5+10;
int tree[maxn<<2],lazy[maxn<<2],a[maxn],p[maxn],tong[maxn];
void pushdown(int rt) {
	tree[lson]+=lazy[rt];
	tree[rson]+=lazy[rt];
	lazy[lson]+=lazy[rt];
	lazy[rson]+=lazy[rt];
	lazy[rt]=0;
}
void pushup(int rt) {
	tree[rt]=max(tree[lson],tree[rson]);
}
void update(int L,int R,int x,int l,int r,int rt) {
	if(L<=l&&r<=R) {
		tree[rt]+=x;
		lazy[rt]+=x;
		return;
	}
	pushdown(rt);
	int mid=(l+r)/2;
	if(L<=mid)
		update(L, R, x,l, mid, lson);
	if(mid<R)
		update(L, R, x,mid+1, r, rson);
	pushup(rt);
}
int q(int L,int R,int l,int r,int rt) {
	pushdown(rt);
	if(L<=l&&r<=R) {
		return tree[rt];
	}
	int mid=(l+r)/2;
	int ans=0;
	if(L<=mid){
		ans=max(ans,q(L,R,l,mid,lson));
	}
	if(mid<R){
		ans=max(ans,q(L,R,mid+1,r,rson));
	}
	return ans;
}
int lowbit(int x){
	return x&(-x);
}
int n;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		tong[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	int now=n;
	update(1,tong[n],1,1,n,1);
	for(int i=1;i<=n;i++){
		cout<<now<<" ";
		if(i==n){
			break;
		}
		update(1,p[i],-1,1,n,1);
		while(q(1,n,1,n,1)<=0){
			now--;
			update(1,tong[now],1,1,n,1);
		}
	}
	return 0;
}
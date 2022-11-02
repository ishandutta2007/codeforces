#include<bits/stdc++.h>
#define LL long long
#define inf 2000000000000LL
using namespace std;
struct tree{
	int sum,s[2];
}tr[6000060];
int n,q,root[200020],tot;
LL ans;
void ins(int wh1,int wh2,int x,int y,int z){
	if (x==y){
		tr[wh1].sum++;
		return;
	}
	int mid=(x+y)/2;
	if (z<=mid){
		tr[wh1].s[0]=++tot;
		tr[wh1].s[1]=tr[wh2].s[1];
		ins(tr[wh1].s[0],tr[wh2].s[0],x,mid,z);
	}
	else{
		tr[wh1].s[0]=tr[wh2].s[0];
		tr[wh1].s[1]=++tot;
		ins(tr[wh1].s[1],tr[wh2].s[1],mid+1,y,z);
	}
	tr[wh1].sum=tr[tr[wh1].s[0]].sum+tr[tr[wh1].s[1]].sum;
}
void build(int wh,int l,int r){
	if (l==r) return;
	int mid=(l+r)/2;
	tr[wh].s[0]=++tot;
	tr[wh].s[1]=++tot;
	build(tr[wh].s[0],l,mid);
	build(tr[wh].s[1],mid+1,r);
}
LL count(int x){
	return 1LL*x*(x-1)/2;
}
int get(int wh,int l,int r,int x,int y){
	if (y<l||x>r||x>y) return 0;
	if (x<=l&&r<=y) return tr[wh].sum;
	int mid=(l+r)/2;
	return get(tr[wh].s[0],l,mid,x,y)+get(tr[wh].s[1],mid+1,r,x,y);
}
int main(){
	scanf("%d%d",&n,&q);
	root[0]=++tot;
	build(1,1,n);
	for (int i=1;i<=n;i++){
		root[i]=++tot;
		int o;
		scanf("%d",&o);
		ins(root[i],root[i-1],1,n,o);
	}
	for (int i=0;i<q;i++){
		int l,d,r,u;
		scanf("%d%d%d%d",&l,&d,&r,&u);
		ans=count(n)-count(l-1)-count(n-r)-count(d-1)-count(n-u);
		//cout<<ans<<endl;
		ans+=count(get(root[l-1],1,n,u+1,n));
		ans+=count(get(root[l-1],1,n,1,d-1));
		ans+=count(get(root[n],1,n,u+1,n)-get(root[r],1,n,u+1,n));
		ans+=count(get(root[n],1,n,1,d-1)-get(root[r],1,n,1,d-1));
		printf("%lld\n",ans);
	}
}
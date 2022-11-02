#include<bits/stdc++.h>
#define LL long long
#define mo 1000000007
using namespace std;
struct tree{
	LL sum,w;
}tr[1600080];
int n,q,a[200020],w[200020];
void insert(int wh,int l,int r,int x,LL sum,LL w){
	if (l==r){
		tr[wh].sum=sum;
		tr[wh].w=w;
		return;
	}
	int mid=(l+r)/2;
	if (x<=mid) insert(wh<<1,l,mid,x,sum,w);
	else insert(wh<<1|1,mid+1,r,x,sum,w);
	tr[wh].sum=(tr[wh<<1].sum+tr[wh<<1|1].sum)%mo;
	tr[wh].w=tr[wh<<1].w+tr[wh<<1|1].w;
}
pair<LL,LL> get(int wh,int l,int r,int x,int y){
	if (x>r||y<l||r<l) return make_pair(0LL,0LL);
	if (x<=l&&r<=y) return make_pair(tr[wh].sum,tr[wh].w);
	pair<LL,LL> res,tmp;
	int mid=(l+r)/2;
	res=get(wh<<1,l,mid,x,y);
	tmp=get(wh<<1|1,mid+1,r,x,y);
	return make_pair((res.first+tmp.first)%mo,res.second+tmp.second);
}
int ques(int wh,int l,int r,LL x){
	if (l==r) return l;
	int mid=(l+r)/2;
	if (tr[wh<<1].w>=x) return ques(wh<<1,l,mid,x);
	return ques(wh<<1|1,mid+1,r,x-tr[wh<<1].w); 
}
int main(){
	//freopen("A.in","r",stdin);
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d",&w[i]);
	for (int i=1;i<=n;i++) insert(1,1,n,i,1LL*(a[i]-i)*w[i],w[i]);
	for (int i=0;i<q;i++){
		int o,p;
		scanf("%d%d",&o,&p);
		if (o<0) insert(1,1,n,-o,1LL*(a[-o]+o)*p,p);
		else{
			//printf("gg\n");
			//if (o==p) printf("0\n");
			//else{
			pair<LL,LL> tl,tr;
			LL wmid,res;
			tl=get(1,1,n,1,o-1);
			tr=get(1,1,n,1,p);
			//printf("%lld %lld\n",tl.first,tl.second);
			//printf("%lld %lld\n",tr.first,tr.second);
			wmid=(tl.second+tr.second+1)/2;
			int ind;
			ind=ques(1,1,n,wmid);
			//printf("%d\n",ind);
			pair<LL,LL> tmid;
			tmid=get(1,1,n,1,ind);
			//printf("%lld %lld\n",tmid.first,tmid.second);
			res=(tr.first-tmid.first)-(tmid.first-tl.first)-(tr.second-tmid.second)%mo*(a[ind]-ind)%mo+(tmid.second-tl.second)%mo*(a[ind]-ind)%mo;
			res=(res%mo+mo)%mo;
			printf("%lld\n",res);
			//}
		}
	}
}
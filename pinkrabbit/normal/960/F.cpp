#include<bits/stdc++.h>
#define F(i,a,b) for(int i=a;i<=(b);++i)
using namespace std;

int n,m,Ans;
int a[100001],b[100001];
int u[100001],v[100001],w[100001];
int f[100001];

int dat[8000001],ls[8000001],rs[8000001],cnt;

int Maxi(int rt,int l,int r,int a,int b) {
	if(a>b) return 0;
	if(r<a||b<l) return 0;
	if(a<=l&&r<=b) return dat[rt];
	if(!ls[rt]) ls[rt]=++cnt;
	if(!rs[rt]) rs[rt]=++cnt;
	int mid=l+r>>1;
	return max(Maxi(ls[rt],l,mid,a,b),Maxi(rs[rt],mid+1,r,a,b));
}

void Ins(int rt,int l,int r,int p,int x) {
	if(l==r) {dat[rt]=x; return;}
	if(!ls[rt]) ls[rt]=++cnt;
	if(!rs[rt]) rs[rt]=++cnt;
	int mid=l+r>>1;
	if(p<=mid) Ins(ls[rt],l,mid,p,x);
	else Ins(rs[rt],mid+1,r,p,x);
	dat[rt]=max(dat[ls[rt]],dat[rs[rt]]);
}

int main() {
	scanf("%d%d",&n,&m);
	cnt=n;
	F(i,1,m) scanf("%d%d%d",u+i,v+i,w+i), ++w[i];
	F(i,1,m) {
		f[i]=Maxi(u[i],1,100001,1,w[i]-1)+1;
		Ins(v[i],1,100001,w[i],f[i]);
	}
	F(i,1,m) Ans=max(Ans,f[i]);
	printf("%d",Ans);
	return 0;
}
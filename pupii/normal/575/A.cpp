#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int mod;
struct matrix{
	int s[2][2];
	matrix(){memset(s,0,sizeof s);}
}seg[200010];
matrix operator*(const matrix&a,const matrix&b){
	matrix c;
	for(int j=0;j<2;++j)
		for(int i=0;i<2;++i)
			for(int k=0;k<2;++k)
				c.s[i][k]=(c.s[i][k]+1ll*a.s[i][j]*b.s[j][k])%mod;
	return c;
}
matrix operator^(matrix a,ll b){
	matrix c;c.s[0][0]=c.s[1][1]=1;
	while(b){
		if(b&1)c=c*a;
		a=a*a,b>>=1;
	}
	return c;
}
int n,A[50010];
#define mid ((l+r)>>1)
void build(int x,int l,int r){
	if(l==r){seg[x].s[0][1]=seg[x].s[1][1]=A[l],seg[x].s[1][0]=1;return;}
	build(x<<1,l,mid),build(x<<1|1,mid+1,r);
	seg[x]=seg[x<<1]*seg[x<<1|1];
}
void update(int x,int l,int r,int p){
	if(l==r){seg[x].s[0][1]=seg[x].s[1][1]=A[l],seg[x].s[1][0]=1;return;}
	if(p<=mid)update(x<<1,l,mid,p);
	else update(x<<1|1,mid+1,r,p);
	seg[x]=seg[x<<1]*seg[x<<1|1];
}
matrix query(int x,int l,int r,int L,int R){
	if(L<=l&&r<=R)return seg[x];
	if(L<=mid)
		if(mid<R)return query(x<<1,l,mid,L,R)*query(x<<1|1,mid+1,r,L,R);
		else return query(x<<1,l,mid,L,R);
	else return query(x<<1|1,mid+1,r,L,R);
}
#undef mid
struct data{ll x,y;}s[50010];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	ll K=gi();mod=gi();
	n=gi();
	for(int i=0;i<n;++i)A[i]=gi();
	int m=gi();
	for(int i=1;i<=m;++i){
		s[i].x=gi(),s[i].y=gi();
		if(s[i].x>=K)--i,--m;
	}
	if(K<=1)return printf("%d\n",K%mod),0;
	std::sort(s+1,s+m+1,[&](data a,data b){return a.x<b.x;});
	if(s[m].x!=K-1)s[++m]={K-1,A[(K-1)%n]};
	build(1,0,n-1);
	if(K<n){
		matrix S=query(1,0,n-1,1,K-1);
		printf("%d\n",(S.s[0][0]+S.s[0][1])%mod);
		return 0;
	}
	s[0].x=1;
	matrix now;
	if(n==1&&s[1].x==1)now.s[0][1]=s[1].y;
	else now.s[0][1]=A[1%n];
	for(int i=1;i<=m;++i){
		if(n==1&&s[i].x==n)continue;
		ll from=s[i-1].x,to=s[i].x-1,p=from%n,q=to%n;
		if(p<q)now=now*query(1,0,n-1,p+1,q);
		else if(p>q){
			if(p<n-1)now=now*query(1,0,n-1,p+1,n-1);
			now=now*query(1,0,n-1,0,q);
		}
		matrix S=query(1,0,n-1,0,q);
		if(q!=n-1)S=query(1,0,n-1,q+1,n-1)*S;
		now=now*(S^((to-from)/n));
		S=matrix();S.s[0][1]=S.s[1][1]=s[i].y%mod,S.s[1][0]=1;
		now=now*S;
	}
	printf("%d\n",(now.s[0][0]+now.s[0][1])%mod);
	return 0;
}
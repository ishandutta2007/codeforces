#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
char _[1000010];
bool s[1000010];
int n;
int yes[2000010];
int A[1000010];
bool check0(){
	int now=1000005;yes[now]=1;
	for(int i=1;i<=n;++i){
		if(s[i])++now;else--now;
		A[i]=now-1000005;
		++yes[now];
	}
	return yes[now]==1;
}
struct fuck{
	int mn,_mn,mx,_mx;
}seg[4000010];
int tag[4000010];
fuck operator+(const fuck&a,const fuck&b){
	fuck c;
	if(a.mn<=b.mn)c.mn=a.mn,c._mn=a._mn;
	else c.mn=b.mn,c._mn=b._mn;
	if(a.mx>=b.mx)c.mx=a.mx,c._mx=a._mx;
	else c.mx=b.mx,c._mx=b._mx;
	return c;
}
#define mid ((l+r)>>1)
void Upd(int x,int d){seg[x].mn+=d;seg[x].mx+=d;tag[x]+=d;}
void down(int x){if(tag[x])Upd(x<<1,tag[x]),Upd(x<<1|1,tag[x]),tag[x]=0;}
void build(int x,int l,int r){
	if(l==r){seg[x]={A[l],l,A[l],l};return;}
	build(x<<1,l,mid),build(x<<1|1,mid+1,r);
	seg[x]=seg[x<<1]+seg[x<<1|1];
}
void update(int x,int l,int r,int L){
	if(L<=l)return Upd(x,1);
	down(x);
	if(L<=mid)update(x<<1,l,mid,L);
	update(x<<1|1,mid+1,r,L);
	seg[x]=seg[x<<1]+seg[x<<1|1];
}
int query(int x,int l,int r,int p){
	if(l==r)return seg[x].mn;
	down(x);
	if(p<=mid)return query(x<<1,l,mid,p);
	else return query(x<<1|1,mid+1,r,p);
}
#undef mid
int main(){
	scanf("%s",_+1);n=strlen(_+1);
	for(int i=1;i<=n;++i)s[i]=_[i]==_[n];
	if(check0())return puts("1"),0;
	build(1,1,n);
	int ans=0;
	for(int i=-n;i;++i){
		if(seg[1].mn==i)update(1,1,n,seg[1]._mn);
		if(seg[1]._mx==n&&seg[1].mx>0)++ans;
		//for(int j=1;j<=n;++j)printf("%d ",query(1,1,n,j));puts("");
	}
	printf("%d\n",ans);
	return 0;
}
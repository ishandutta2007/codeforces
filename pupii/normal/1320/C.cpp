#include<bits/stdc++.h>
typedef long long ll;
#define int ll
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
template<class T>void cxk(T&a,T b){a=a>b?a:b;}
template<class T>void cnk(T&a,T b){a=a<b?a:b;}
#ifdef mod
template<class Ta,class Tb>void inc(Ta&a,Tb b){a=a+b>=mod?a+b-mod:a+b;}
template<class Ta,class Tb>void dec(Ta&a,Tb b){a=a>=b?a-b:a+mod-b;}
#endif
struct wep{int a,b;}A[200010],B[200010];
struct jiz{int x,y,z;}s[200010];
int start[1000010];
int seg[4000010],tag[4000010];
#define mid ((l+r)>>1)
void build(int x,int l,int r){
	if(l==r){seg[x]=start[l];return;}
	build(x<<1,l,mid),build(x<<1|1,mid+1,r);
	seg[x]=std::max(seg[x<<1],seg[x<<1|1]);
}
void upd(int x,int d){tag[x]+=d;seg[x]+=d;}
void down(int x){if(tag[x])upd(x<<1,tag[x]),upd(x<<1|1,tag[x]),tag[x]=0;}
void update(int x,int l,int r,int p,int d){
	if(p<=l)return upd(x,d);
	down(x);
	if(p<=mid)update(x<<1,l,mid,p,d);
	update(x<<1|1,mid+1,r,p,d);
	seg[x]=std::max(seg[x<<1],seg[x<<1|1]);
}
#undef mid
signed main(){
#ifdef LOCAL
	freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
#endif
	int n=gi(),m=gi(),p=gi();
	for(int i=1;i<=n;++i)A[i].a=gi(),A[i].b=gi();
	for(int i=1;i<=m;++i)B[i].a=gi(),B[i].b=gi();
	for(int i=1;i<=p;++i){
		s[i].x=gi()+1,s[i].y=gi()+1,s[i].z=gi();
		if(s[i].y>1000000||s[i].x>1000000){--i;--p;}
	}
	std::sort(A+1,A+n+1,[](wep a,wep b){return a.a<b.a;});
	std::sort(B+1,B+m+1,[](wep a,wep b){return a.a<b.a;});
	std::sort(s+1,s+p+1,[](jiz a,jiz b){return a.x<b.x;});
	for(int i=1;i<=1000000;++i)start[i]=-2e9;
	for(int i=1;i<=m;++i)start[B[i].a]=std::max(start[B[i].a],-B[i].b);
	build(1,1,1000000);int ans=-1e18;
	for(int i=1,j=1;i<=n;++i){
		while(j<=p&&s[j].x<=A[i].a)update(1,1,1000000,s[j].y,s[j].z),++j;
		ans=std::max(ans,seg[1]-A[i].b);
	}
	printf("%lld\n",ans);
	return 0;
}
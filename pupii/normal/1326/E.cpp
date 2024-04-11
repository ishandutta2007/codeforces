#include<bits/stdc++.h>
typedef long long ll;
#define mod 998244353
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
std::mt19937 rnd(time(NULL));
#define rand rnd
template<class T>void cxk(T&a,T b){a=a>b?a:b;}
template<class T>void cnk(T&a,T b){a=a<b?a:b;}
#ifdef mod
int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
template<class Ta,class Tb>void inc(Ta&a,Tb b){a=a+b>=mod?a+b-mod:a+b;}
template<class Ta,class Tb>void dec(Ta&a,Tb b){a=a>=b?a-b:a+mod-b;}
#endif
int p[300010],q[300010];
#define mid ((l+r)>>1)
struct data{int sum,mns;}seg[1200010];
data operator+(const data&a,const data&b){
	return{a.sum+b.sum,std::min(b.mns,a.mns+b.sum)};
}
void update(int x,int l,int r,int p,int d){
	if(l==r){seg[x].sum+=d,seg[x].mns=std::min(0,seg[x].sum);return;}
	if(p<=mid)update(x<<1,l,mid,p,d);
	else update(x<<1|1,mid+1,r,p,d);
	seg[x]=seg[x<<1]+seg[x<<1|1];
}
int main(){
#ifdef LOCAL
	freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
#endif
	int n=gi();
	for(int i=1;i<=n;++i)p[gi()]=i;
	for(int i=1;i<=n;++i)q[i]=gi();
	for(int i=1,j=n;i<=n;++i){
		printf("%d ",j);
		update(1,1,n,q[i],1);
		while(j&&seg[1].mns>=0)update(1,1,n,p[j],-1),--j;
		++j,update(1,1,n,p[j],1);
	}
	return 0;
}
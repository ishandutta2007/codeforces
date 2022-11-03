#include<bits/stdc++.h>
typedef long long ll;
#define inf 1000000000
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
std::mt19937 rnd(time(NULL));
#define rand rnd
#define pr std::pair<int,int>
#define fi first
#define se second
template<class T>void cxk(T&a,T b){a=a>b?a:b;}
template<class T>void cnk(T&a,T b){a=a<b?a:b;}
#ifdef mod
int mod;
int pow(int x,ll y){
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
int a[200010],from[200010],ch[10000010][2];
struct data{
	int a,b,c,d;
	void insert(int e,int f){
		if(f==b||f==d){
			f==b?cxk(a,e):cxk(c,e);
			if(a<c)std::swap(a,c),std::swap(b,d);
		}else if(e>a)c=a,d=b,a=e,b=f;
		else if(e>c)c=e,d=f;
	}
	data get(int x){return b==x?data{c,d,-inf,0}:data{a,b,-inf,0};}
};
data operator+(data a,const data&b){a.insert(b.a,b.b);a.insert(b.c,b.d);return a;}
data operator*(data a,int b){a.a+=b,a.c+=b;return a;}
int FA[200010];
data s[262147],mx[200010];
int hd(int x){return FA[x]==x?FA[x]:FA[x]=hd(FA[x]);}
int main(){
#ifdef LOCAL
	freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
#endif
	int n=gi()+1,U=262143;
	ll ans=0;
	for(int i=1;i<n;++i)a[i]=gi(),ans-=a[i];
	for(int i=1;i<=n;++i)FA[i]=i;
	while(1){
		int c=0;
		for(int i=1;i<=n;++i)c+=FA[i]==i;
		if(c==1)break;
		for(int i=0;i<=U;++i)s[i]={-inf,0,-inf,0};
		for(int i=1;i<=n;++i)s[a[i]].insert(a[i],hd(i));
		for(int i=1;i<U;i<<=1)for(int j=0;j<=U;++j)if(~j&i)s[j|i]=s[j|i]+s[j];
		for(int i=1;i<=n;++i)mx[i]={-inf,0,-inf,0};
		for(int i=1;i<=n;++i)mx[hd(i)]=mx[hd(i)]+(s[U^a[i]].get(hd(i))*a[i]);
		for(int i=1;i<=n;++i)if(FA[i]==i&&hd(mx[i].b)!=i)ans+=mx[i].a,FA[i]=hd(mx[i].b);
	}
	printf("%lld\n",ans);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 200005
#define MS 524288
#define inf 0x7fffffff
#define ll long long
#define mod 998244353
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
int n,q;
int a[MN];
struct x{
	int t,m,s;
	x(){t=m=s=0;}
	x(int t,int m,int s):t(t),m(m),s(s){}
	x(int v){t=1,m=v,s=inf;}
	inline friend x operator+(x a,x b){
		if(!a.t)return b;
		if(!b.t)return a;
		return x(2,min(a.m,b.m),min(min(a.s,b.s),a.m+b.m));
	}
};
int T;
struct sgt{
	x a[MS];
	inline void mdf(int p,int v){
		for(a[p+=T]=v?x(v):x();p>>=1;)a[p]=a[p<<1]+a[p<<1|1];
	}
	inline int qur(int l,int r){
		x ans;
		for(l+=T-1,r+=T+1;l^r^1;l>>=1,r>>=1){
			if(~l&1)ans=ans+a[l^1];
			if(r&1)ans=ans+a[r^1];
		}
		return ans.t==2?ans.s:inf;
	}
}s[10];
int main(){
	scanf("%d%d",&n,&q);
	for(T=1;T<n+2;T<<=1);
	F(i,1,n){
		scanf("%d",a+i);
		int z=a[i];
		F(j,1,9){
			int o=z%10!=0?a[i]:0;
			s[j].mdf(i,o);
			z/=10;
		}
	}
	while(q--){
		int op,x,y;
		scanf("%d%d%d",&op,&x,&y);
		if(op==1){
			int z=y;
			F(j,1,9){
				int o=z%10!=0?y:0;
				s[j].mdf(x,o);
				z/=10;
			}
			a[x]=y;
		}
		else{
			int ans=inf;
			F(j,1,9)ans=min(ans,s[j].qur(x,y));
			printf("%d\n",ans==inf?-1:ans);
		}
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 500005
#define MM 500005
#define ll long long
#define mod 998244353
#define inv2 ((mod+1)/2)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
inline int qpow(int b,int e,int m=mod){int a=1;for(;e;e>>=1,b=(ll)b*b%m)if(e&1)a=(ll)a*b%m;return a;}
int n,k,m,Ans,ql[MM],qr[MM],qx[MM],qt[MM];
struct dat{int l,r;}q[MM];
inline int Solve(int o){
//	printf("o=%d\n",o);
	static int a[MN];
	F(i,1,m)qt[i]=qx[i]>>o&1;
	F(i,1,n)a[i]=0;
	F(i,1,m)if(qt[i])++a[ql[i]],--a[qr[i]+1];
	F(i,1,n)a[i]+=a[i-1];
	F(i,1,n)a[i]=!a[i];
	F(i,1,n)a[i]+=a[i-1];
	int l=a[n],c=0,d=0;
	F(i,1,m)if(!qt[i])q[++c]=(dat){a[ql[i]-1]+1,a[qr[i]]};
	sort(q+1,q+c+1,[](dat x,dat y){return x.r==y.r?x.l>y.l:x.r<y.r;});
	if(!c)return qpow(2,l);
	q[d=1]=q[1];
	F(i,2,c)if(q[i].l>q[d].l)q[++d]=q[i];
	c=d;
//	printf("l=%d\n",l);
//	F(i,1,c)printf("[%d-%d]\n",q[i].l,q[i].r);
	static int pw[MN],ipw[MN];
	pw[0]=ipw[0]=1;
	F(i,1,l)pw[i]=2ll*pw[i-1]%mod,ipw[i]=(ll)inv2*ipw[i-1]%mod;
	static int f[MN],sf[MN],sg[MN];
	int j=0;
	F(i,1,c){
		while(j<i-1&&q[j+1].r<q[i].l)++j;
		int len=q[i].r-q[i].l+1;
		f[i]=(ll)(mod-sf[j]-1)*ipw[len]%mod;
		f[i]=(f[i]+(ll)(sg[j]-sg[i-1]+mod)*ipw[q[i].r])%mod;
		sf[i]=(sf[i-1]+f[i])%mod;
		sg[i]=(sg[i-1]+(ll)f[i]*pw[q[i].r])%mod;
	}
	return (ll)(sf[c]+1)*pw[l]%mod;
}
int main(){
	scanf("%d%d%d",&n,&k,&m),Ans=1;
	F(i,1,m)scanf("%d%d%d",ql+i,qr+i,qx+i);
	F2(i,0,k)Ans=(ll)Ans*Solve(i)%mod;
	printf("%d\n",Ans);
	return 0;
}
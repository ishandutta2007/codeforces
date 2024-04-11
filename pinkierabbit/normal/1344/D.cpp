#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 300005
#define MM 600005
#define ll long long
#define LL __int128
void pr(LL x){
	if(x<0)putchar('-'),x=-x;
	if(x<10)return putchar('0'+x),void();
	pr(x/10),putchar('0'+(x%10));
}
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int n;ll k;
int a[MN],b[MN];ll nx[MN];
LL f(LL c,LL x){return x*(c-x*x);}
LL g(LL c,LL x){return x==c?-infll:f(c,x+1)-f(c,x);}
inline LL calc(LL c,int tp=0){
	LL num=0;
	F(i,1,n){
		LL t=a[i]+c;
		LL x=sqrt((long double)t/3);
		if(x>a[i])x=a[i];
		if(x<0)x=0;
		while(x<a[i]&&f(t,x+1)>f(t,x))++x;
		while(x>0&&f(t,x-1)>=f(t,x))--x;
		num+=x;
		if(tp)b[i]=x;
	}
	return num;
}
priority_queue<pli>pq;
int main(){
	scanf("%d%lld",&n,&k);
	F(i,1,n)scanf("%d",a+i);
	LL l=-1.1e9,r=3.1e18,mid,ans=l;
	while(l<=r){
		mid=(l+r)/2;
		LL num=calc(mid);
		if(num<=k)ans=mid,l=mid+1;
		else r=mid-1;
	}
	ll num=calc(ans,1);
	F(i,1,n)pq.push({g(a[i],b[i]),i});
	while(num<k){
		pli x=pq.top();pq.pop();
		++num;
		pq.push({g(a[x.se],++b[x.se]),x.se});
	}
	F(i,1,n)printf("%d%c",b[i]," \n"[i==n]);
//	LL z=0;
//	F(i,1,n)z+=f(a[i],b[i]);
//	pr(z);
	return 0;
}
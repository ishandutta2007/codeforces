#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define MN 500005
#define ll long long
#define mod 998244353
int n,m,q,k;
int a[MN],b[MN],p[MN];
ll qu[MN]; int qp[MN];
int ans[MN];
int B[MN];
inline void add(int i){for(;i<=m;i+=i&-i)++B[i];}
inline int bs(int x){
	int i=0;
	for(int j=18;~j;--j){
		if(i+(1<<j)<=m&&x>=B[i+(1<<j)])
			x-=B[i+=1<<j];
	}
	return i;
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	F(i,1,n)scanf("%d",a+i),++b[a[i]];
	F(i,1,m)p[i]=i;
	sort(p+1,p+m+1,[](int i,int j){return b[i]<b[j];});
	F(i,1,q)scanf("%lld",qu+i),qu[i]-=n+1,qp[i]=i;
	sort(qp+1,qp+q+1,[](int i,int j){return qu[i]<qu[j];});
	int j=1;ll s=0;
	add(p[1]);
	F(I,1,q){
		ll v=qu[qp[I]];
		while(j<m&&s+(ll)j*(b[p[j+1]]-b[p[j]])<=v)s+=(ll)j*(b[p[j+1]]-b[p[j]]),add(p[++j]);
		(v-=s)%=j;
		ans[qp[I]]=bs(v)+1;
	}
	F(i,1,q)printf("%d\n",ans[i]);
	return 0;
}
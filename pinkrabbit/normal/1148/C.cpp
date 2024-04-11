#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define MN 300005
#define MM 600005
#define ll long long
#define mod 998244353
int n,m,q,k;
int a[MN],b[MN],f[MN*5],g[MN*5];
int dis(int x,int y){return x-y<0?y-x:x-y;}
inline void swp(int x,int y){
	swap(a[x],a[y]);
	swap(b[a[x]],b[a[y]]);
	f[++k]=x,g[k]=y;
}
int main(){
	scanf("%d",&n);
	F(i,1,n)scanf("%d",a+i),b[a[i]]=i;
	F(i,n/2+1,n){
		int p=b[i];
		int d=dis(p,i);
		if(d==0)continue;
		if(d>=n/2)swp(p,i);
		else if(p>n/2)swp(1,p),swp(1,i),swp(1,p);
		else swp(p,n),swp(1,n),swp(1,i),swp(1,n),swp(p,n);
	}
	dF(i,n/2,1){
		int p=b[i];
		if(p==i)continue;
		swp(p,n),swp(i,n),swp(p,n);
	}
	printf("%d\n",k);
	F(i,1,k)printf("%d %d\n",f[i],g[i]);
	return 0;
}
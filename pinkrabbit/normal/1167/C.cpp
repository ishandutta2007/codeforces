#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define MN 500005
#define MM 600005
#define ll long long
#define mod 998244353
int n,m,q,k;
int fa[MN];int ff(int x){return fa[x]?fa[x]=ff(fa[x]):x;}
int b[MN];
int main(){
	scanf("%d%d",&n,&m);
	F(i,1,m){
		int x,y,z;scanf("%d",&x);
		if(!x)continue;
		scanf("%d",&y);
		while(--x)scanf("%d",&z),(ff(y)!=ff(z)?fa[ff(y)]=ff(z):0),y=z;
	}
	F(i,1,n)++b[ff(i)];
	F(i,1,n)printf("%d ",b[ff(i)]);
	return 0;
}
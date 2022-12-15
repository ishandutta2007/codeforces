#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define ref(i,x,y)for(int i=x;i<=y;++i)
#define def(i,x,y)for(int i=x;i>=y;--i)
int n,k,f[200002],F[200002];
struct xint{int a,b;}s[200002];
bool cmp(xint a,xint b){return a.a-a.b<b.a-b.b;}
int main()
{
	scanf("%d%d",&n,&k);
	ref(i,1,n)scanf("%d",&s[i].a);
	ref(i,1,n)scanf("%d",&s[i].b);
	sort(s+1,s+n+1,cmp);
	ref(i,1,n)f[i]=f[i-1]+s[i].a;
	def(i,n,1)F[i]=F[i+1]+s[i].b;
	int ans=2e9+1;
	ref(i,k,n)ans=min(ans,f[i]+F[i+1]);
	cout<<ans<<endl;
}
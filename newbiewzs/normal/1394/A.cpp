#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LI;

const int N=100005;
int n,d,m,cmx,cmi;
int mx[N],mi[N];
LI ans;
LI smx[N],smi[N];
int main()
{
	int a;
	scanf("%d%d%d",&n,&d,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		if(a>m)mx[++cmx]=a;
		else mi[++cmi]=a;
	}
	sort(mx+1,mx+cmx+1);reverse(mx+1,mx+cmx+1);
	sort(mi+1,mi+cmi+1);reverse(mi+1,mi+cmi+1);
	for(int i=1;i<=cmx;i++)smx[i]=smx[i-1]+mx[i];
	for(int i=1;i<=cmi;i++)smi[i]=smi[i-1]+mi[i];
	for(int i=0;i<=cmx;i++)
	{
		LI lst=min((LI)cmi,cmi+cmx-i-1ll*d*(i-1));
		if(lst>=0)ans=max(ans,smx[i]+smi[lst]);
	}
	printf("%lld\n",ans);
	return 0;
}
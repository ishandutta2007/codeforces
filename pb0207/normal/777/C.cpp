#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+1;
int a[N],f[N],b[N],mi[N];
int n,m,tmp;
pair<int,int>q[N*10];
void get(int *a)
{
	f[1]=1;int last=1;
	for(int i=2;i<=n;++i)
	{
		if(a[i-1]>a[i])last=i;
		f[i]=last;
	}
	for(int i=1;i<=n;++i)mi[i]=min(f[i],mi[i]);
}



int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	for(int j=1;j<=m;++j)
	scanf("%d",&a[(i-1)*m+j]);
	for(int i=1;i<=n;++i)
	for(int t=1;t<=m;++t)
	b[(t-1)*n+i]=a[(i-1)*m+t];
	memset(mi,0x3f,sizeof(mi));
	for(int i=1;i<=m;++i)get(b+(i-1)*n);
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		if(mi[r]<=l)printf("Yes\n");
		else	printf("No\n");
	}
}
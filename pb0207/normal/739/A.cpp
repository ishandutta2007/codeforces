#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e5+1e3+7;

int n,m,l[N],r[N],w[N],mn=N+1;

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&l[i],&r[i]),mn=min(mn,r[i]-l[i]+1);
	cout<<mn<<endl;
	int tx=0;
	for(int i=1;i<=n;i++)
	{
		printf("%d ",tx);
		tx=(tx+1)%mn;
	}
}
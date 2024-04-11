#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e6+1e3+7; 

int n,a[N],vis[N];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int ans=0;
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			int tot=0;
			vis[i]=1;
			int x=i;
			tot=1;
			while(!vis[a[x]])
				vis[a[x]]=1,tot++,x=a[x];
			ans+=tot-1;
		}
	puts((ans%2==(n*3)%2)?"Petr":"Um_nik");
}
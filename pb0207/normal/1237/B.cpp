#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int n,a[N],b[N],in[N],out[N];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),in[a[i]]=i;
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]),out[b[i]]=i; 
	int fs=n+1,ans=0;
	for(int i=n;i>=1;i--)
	{
		if(in[b[i]]>fs)
			ans++;
		fs=min(fs,in[b[i]]);
	}
	printf("%d",ans);
}
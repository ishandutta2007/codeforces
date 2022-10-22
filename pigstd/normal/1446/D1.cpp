#include<bits/stdc++.h>
using namespace std;

const int M=2e5+10;
int n,a[M],t[M<<1],b[M],maxn,p,ans;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

int main()
{
	n=read();
	for (int i=1;i<=n;i++)a[i]=read(),t[a[i]]++,maxn=max(maxn,t[a[i]]);
	for (int i=1;i<=n;i++)
		if (t[a[i]]==maxn)
		{
			if (p==0)p=a[i];
			else if (p==a[i])continue;
			else {cout<<n<<endl;return 0;}
		}
	for (int i=1;i<=100;i++)
	{
		if (i==p)continue;
		memset(t,0,sizeof(t));
		for (int j=1;j<=n;j++)
		{
			b[j]=b[j-1];
			if (a[j]==i)b[j]++;
			if (a[j]==p)b[j]--; 
			t[b[j]+n]=j;
		}
		for (int j=0;j<=n;j++)
			ans=max(ans,t[b[j]+n]-j);
	}
	cout<<ans<<endl;
}
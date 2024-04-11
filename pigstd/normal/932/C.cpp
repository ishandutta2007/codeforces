#include<bits/stdc++.h>
using namespace std;

const int M=1e6+10;
int n,a,b,ans[M];

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

struct edge{int to,next;}e[M<<1];int cnt,head[M];
void add(int u,int to){e[++cnt].to=to,e[cnt].next=head[u],head[u]=cnt;}

int f(int k)
{
	int sum=1;
	while(k)sum*=(k%10==0?1:k%10),k/=10;
	return sum;
}

signed main()
{
	n=read(),a=read(),b=read();
	if (n%__gcd(a,b)!=0){puts("-1");return 0;}
	int k1=-1,k2=-1;
	for (int i=0;i*a<=n;i++)
	{
		int p=n-(i*a);
		if (p%b==0){k1=i,k2=p/b;break;}
	}
	if (k1==-1){puts("-1");return 0;}
	int now=1;
//	cout<<k1<<' '<<k2<<endl;
	for (int i=1;i<=k1;i++)
	{
		int p=now;
		for (int j=1;j<a;j++,now++)ans[now]=now+1;
//		cout<<now<<'a';
		ans[now]=p;now++;
	}
//	for (int i=1;i<=n;i++)cout<<ans[i]<<' ';
	for (int i=1;i<=k2;i++)
	{
		int p=now;
		for (int j=1;j<b;j++,now++)ans[now]=now+1;
		ans[now]=p;now++;
	}
	for (int i=1;i<=n;i++)cout<<ans[i]<<' ';
	return 0;
}
#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define WT int T=read();while(T--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=1e5+10;
int l,r;
struct edge{int u,to,w;}e[M];int cnt;

void add(int u,int to,int w){e[++cnt].u=u,e[cnt].to=to,e[cnt].w=w;}

signed main()
{
	l=read(),r=read();YES int n=1;
	int p=r-l+1,k=log2(p-1);
	for (int i=2;i<=k+2;i++)
	{
		n++;
		for (int j=2;j<i;j++)
			add(j,i,1<<(j-2));
		add(1,i,1);
	}int sum=1;n++,p--,add(1,n,1);
	for (int i=0;i<=k+1;i++)
		if ((1<<i)&p)
		{
			add(i+2,n,sum);
			sum+=(1<<i);
		}
	if (l!=1)
		n++,add(n-1,n,l-1);
	cout<<n<<' '<<cnt<<endl;
	for (int i=1;i<=cnt;i++)
		cout<<e[i].u<<' '<<e[i].to<<' '<<e[i].w<<endl;
	return 0;
}
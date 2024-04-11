//AFO countdown:8 Days
#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int TT=read();while(TT--) 
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

const int M=210;
int u[M],n,k,v[M],t[M];

signed main()
{
	WT
	{
		n=read(),k=read();
		memset(t,0,sizeof(t));
		int res=(n-k)*(n-k-1)/2;
		for (int i=1;i<=k;i++)
		{
			u[i]=read(),v[i]=read();
			if (u[i]>v[i])swap(u[i],v[i]);
			t[u[i]]=t[v[i]]=1;
		}
		for (int i=1;i<=k;i++)
			for (int j=1;j<=k;j++)
				if (i!=j&&u[i]<u[j]&&u[j]<v[i]&&v[i]<v[j])res++;
		for (int i=1;i<=k;i++)
		{
			int res1=0,res2=0;
			for (int j=u[i];j<=v[i];j++)
				res1+=t[j]^1;
			for (int j=v[i];j<=2*n;j++)
				res2+=t[j]^1;
			for (int j=1;j<=u[i];j++)
				res2+=t[j]^1;
			res+=min(res1,res2);
		}cout<<res<<endl;
	}
	return 0;
}
#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int inf=1e18;
const int M=2e5+10;
int T,n,m;
int a1[M],a2[M],a[M],b[M],cnt1,cnt2,sum[M];

bool cmp(int a,int b){return a>b;}

signed main()
{
	T=read();
	while(T--)
	{
		n=read(),m=read(),cnt1=cnt2=0;int tot=0;int ans=inf;
		for (int i=1;i<=n;i++)a[i]=read(),tot+=a[i];
		for (int i=1;i<=n;i++)
		{
			b[i]=read();
			if (b[i]==1)a1[++cnt1]=a[i];
			else a2[++cnt2]=a[i];
		}
		if (tot<m){puts("-1");continue;}
		sort(a1+1,a1+1+cnt1,cmp);tot=0;
		sort(a2+1,a2+1+cnt2,cmp);
		for (int i=1;i<=cnt2;i++)sum[i]=sum[i-1]+a2[i];
		for (int i=0;i<=cnt1;i++)
		{
			tot+=a1[i];
			if (tot+sum[cnt2]<m)continue;
			int tl=0,tr=cnt2,p;
			while(tl<=tr)
			{
				int Mid=(tl+tr)>>1;
				if (sum[Mid]+tot>=m)p=Mid,tr=Mid-1;
				else tl=Mid+1;
			}
			ans=min(ans,i+p*2);
		}
		cout<<ans<<endl;
	}
	return 0;
}
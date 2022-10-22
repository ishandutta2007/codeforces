#include<bits/stdc++.h>
#define int long long
using namespace std;

const int inf=1145141919180;
const int M=2e5+10;
int T,n,q,l,r,a[M],maxl[M],maxr[M],minl[M],minr[M];
string s;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

struct edge{int to,next;}e[M<<1];int cnt,head[M];
void add(int u,int to){e[++cnt].to=to,e[cnt].next=head[u],head[u]=cnt;}

signed main()
{
	cin>>T;;
	while(T--)
	{
		cin>>n>>q>>s;minl[0]=minr[n+1]=inf,maxl[0]=maxr[n+1]=-inf;
		for (int i=1;i<=n;i++)a[i]=a[i-1]+(s[i-1]=='+'?1:-1);
		for (int i=1;i<=n;i++)
			maxl[i]=max(maxl[i-1],a[i]),minl[i]=min(minl[i-1],a[i]);
		for (int i=n;i>=1;i--)
			maxr[i]=max(maxr[i+1],a[i]),minr[i]=min(minr[i+1],a[i]);
//		for (int i=1;i<=n;i++)cout<<a[i]<<' ';puts("");
//		for (int i=1;i<=n;i++)cout<<minl[i]<<' ';puts("");
//		for (int i=1;i<=n;i++)cout<<maxl[i]<<' ';puts("");
//		for (int i=1;i<=n;i++)cout<<minr[i]<<' ';puts("");
//		for (int i=1;i<=n;i++)cout<<maxr[i]<<' ';puts("");
		for (int i=1;i<=q;i++)
		{
			cin>>l>>r;l--,r++;
//			if (l==0&&r==n+1){puts("1");continue;}
			int Min=0,Max=0;
			if (r!=n+1)Max=max(Max,maxr[r]-(a[r-1]-a[l])),Min=min(Min,minr[r]-(a[r-1]-a[l]));
			if (l!=0)Max=max(Max,maxl[l]),Min=min(Min,minl[l]);
//			cout<<Min<<' '<<Max<<endl;
			cout<<Max-Min+1<<endl;
		}
		for (int i=0;i<=n+1;i++)
			maxl[i]=maxr[i]=minl[i]=minr[i]=a[i]=0;
	}return 0;
}
/*
1
2 1
--
1 1

*/
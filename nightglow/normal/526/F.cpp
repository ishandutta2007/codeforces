#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>
#include<set>
#include<vector>
#include<map>
#include<queue>

#define N 1000005
#define M 8000005

#define ls (t<<1)
#define rs ((t<<1)|1)
#define mid ((l+r)>>1)

#define mk make_pair
#define pb push_back
#define fi first
#define se second

using namespace std;

int i,j,m,n,k,p[N],A[N*4],B[N*4],C[N*4],D[N*4],Max[N],Min[N];

long long ans;

int read()
{
		int x; char c;
		while (c=getchar(),c<'0'||c>'9');
		x=c-'0';
		while (c=getchar(),c>='0'&&c<='9') x=(x<<1)+(x<<3)+c-'0';
		return x;
}

void Fen(int l,int r)
{
		if (l==r) 
		{
				++ans;
				return;
		}
		Fen(l,mid); Fen(mid+1,r);
		Max[mid]=Min[mid]=p[mid];
		Max[mid+1]=Min[mid+1]=p[mid+1];
		for (i=mid-1;i>=l;--i) Max[i]=max(Max[i+1],p[i]),Min[i]=min(Min[i+1],p[i]);
		for (i=mid+2;i<=r;++i) Max[i]=max(Max[i-1],p[i]),Min[i]=min(Min[i-1],p[i]);
		int L1=mid,L2=mid;
		for (i=l;i<=mid;++i) A[Max[i]-Min[i]+i]++; 
		for (i=mid+1;i<=r;++i)
		{
				while (L2>=l&&(Min[i]<=Min[L2]||Max[i]>=Max[L2]))
					A[Max[L2]-Min[L2]+L2]--,B[Min[L2]-L2+N]++,C[Max[L2]+L2]++,--L2;
				while (L1>=l&&Min[i]<=Min[L1]&&Max[i]>=Max[L1])  
					B[Min[L1]-L1+N]--,C[Max[L1]+L1]--,D[L1]++,--L1;
				if (i-Max[i]+Min[i]>=0)
				ans+=D[i-Max[i]+Min[i]];
				ans+=A[i];
				if (L2<mid)
				{
						if (Max[L2+1]>Max[i])
						{
								ans+=C[Min[i]+i];
						}
						if (Min[L2+1]<Min[i])
						{
								ans+=B[Max[i]-i+N];
						}
				}
		}
		for (i=l;i<=mid;++i)
			A[Max[i]-Min[i]+i]=B[Min[i]-i+N]=C[Max[i]+i]=D[i]=0;
}

int main()
{
		scanf("%d",&n);
		for (i=1;i<=n;++i) 
		{
			int x,y;
			x=read(); y=read();
			p[x]=y;
			//p[i]=read();
		}
		Fen(1,n);
		cout<<ans<<endl;
}
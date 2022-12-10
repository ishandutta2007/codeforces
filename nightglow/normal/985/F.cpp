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

#define N 300005
#define M 8000005

#define ls (t<<1)
#define rs ((t<<1)|1)
#define mid ((l+r)>>1)

#define mk make_pair
#define pb push_back
#define fi first
#define se second

#define Seed 233333
#define Mo 998244353

using namespace std;

int i,j,m,n,p,k,pos[N],t[N],next[N][26],Hash[N],Pow[N];

char c[N];

int gethash(int x,int len)
{
		int s=(Hash[x+len-1]-1ll*Hash[x-1]*Pow[len]%Mo+Mo)%Mo,i;
		for (i=0;i<26;++i) 
			if (next[x][i]<=x+len-1)
				s=(s-1ll*t[next[x][i]]*Pow[x+len-1-next[x][i]]%Mo+Mo)%Mo;
		return s;
}

int main()
{
		Pow[0]=1; for (i=1;i<N;++i) Pow[i]=1ll*Pow[i-1]*Seed%Mo;
		scanf("%d%d",&n,&m);
		scanf("%s",c+1);
		for (i=1;i<=n;++i)
		{
				if  (!pos[c[i]]) t[i]=0; else t[i]=i-pos[c[i]];
				pos[c[i]]=i;
		}
		for (i=0;i<26;++i) next[n+1][i]=n+1;
		for (i=n;i>=1;--i)
		{
				for (j=0;j<26;++j) next[i][j]=next[i+1][j];
				next[i][c[i]-'a']=i;
		}
		for (i=1;i<=n;++i) Hash[i]=(1ll*Hash[i-1]*Seed%Mo+t[i])%Mo;
		for (;m--;)
		{
				int x,y,len;
				scanf("%d%d%d",&x,&y,&len);
				if (gethash(x,len)==gethash(y,len)) puts("YES");
				else puts("NO");
		}
}
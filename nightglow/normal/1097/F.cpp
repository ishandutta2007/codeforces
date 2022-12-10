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
#include<bitset>

#define N 100005
#define M 8000005

#define ls (t<<1)
#define rs ((t<<1)|1)
#define mid ((l+r)>>1)

#define mk make_pair
#define pb push_back
#define fi first
#define se second

using namespace std;

int i,j,m,n,p,k,cnt,ID[N],q,ty,x,y,z,v;

bitset<7005>bit[N],pre[7005];

int read()
{
		int x; char c;
		while (c=getchar(),c<'0'||c>'9');
		x=c-'0';
		while (c=getchar(),c>='0'&&c<='9')x=(x<<1)+(x<<3)+c-'0';
		return x;
}

int main()
{
		scanf("%d%d",&n,&q); 
		for (i=7000;i>=1;--i)
		{
				pre[i][i]=1;
				for (j=i+i;j<=7000;j+=i) pre[i]^=pre[j];
		}
		for (;q--;)
		{
				ty=read();
				if (ty==1)
				{
						x=read(); v=read();
						bit[x]=bit[0];
						for (i=1;i*i<=v;++i)
								if (v%i==0)
						{
								bit[x][i]=1;
								if (i*i!=v) bit[x][v/i]=1;
						}
				}
				else if (ty==2)
				{
						x=read();y=read();z=read();
						bit[x]=bit[y]^bit[z];
				}
				else if (ty==3)
				{
						x=read(); y=read(); z=read();
						bit[x]=bit[y]&bit[z]; 
				}
				else
				{
						x=read(); v=read();
						printf("%d",(bit[x]&pre[v]).count()&1);
				}
		}
}
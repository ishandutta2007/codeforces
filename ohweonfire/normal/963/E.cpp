#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;

const int dx[]={-1,0,1,0};
const int dy[]={0,-1,0,1};
const int mod=1e9+7;
int qpow(int x,int y)
{
	int ret=1;
	while(y)
	{
		if(y&1)ret=(LL)ret*x%mod;
		x=(LL)x*x%mod;
		y>>=1;
	}
	return ret;
}

struct vec
{
	int a[111];
	vec(){memset(a,0,sizeof(a));}
	vec(int x){memset(a,0,sizeof(a));a[x]=1;}
	vec operator +(const vec&b)const
	{
		vec ret;
		for(int i=0;i<111;i++)
		{
			ret.a[i]=a[i]+b.a[i];
			if(ret.a[i]>=mod)ret.a[i]-=mod;
		}
		return ret;
	}
	vec operator *(const int&b)const
	{
		vec ret;
		for(int i=0;i<111;i++)ret.a[i]=(LL)a[i]*b%mod;
		return ret;
	}
	vec operator -(const vec&b)const
	{
		vec ret;
		for(int i=0;i<111;i++)
		{
			ret.a[i]=a[i]-b.a[i];
			if(ret.a[i]<0)ret.a[i]+=mod;
		}
		return ret;
	}
};

int id[111][111],tot;
bool in[111][111];
int r,a[4],ia[4],all,b[111][111],m;

vec v[111][111];

void get_down(int x,int y)
{
	vec cur=(v[x][y]-vec(tot+1))*all;
	for(int i=0;i<4;i++)if(dx[i]!=1)cur=cur-v[x+dx[i]][y+dy[i]]*a[i];
	cur=cur*ia[2];
	v[x+1][y]=cur;
}
void get_func(int x,int y)
{
	m++;
	vec cur=(v[x][y]-vec(tot+1))*all;
	for(int i=0;i<4;i++)cur=cur-v[x+dx[i]][y+dy[i]]*a[i];
	for(int i=1;i<=tot+1;i++)b[m][i]=cur.a[i];
	b[m][tot+1]=(mod-b[m][tot+1])%mod;
}
void gauss()
{
	for(int i=1;i<=tot;i++)
	{
		if(!b[i][i])
		{
			for(int j=i;j<=tot;j++)if(b[j][i])
			{
				for(int k=1;k<=tot+1;k++)swap(b[i][k],b[j][k]);
				break;
			}
		}
		if(!b[i][i])
		{
			puts("baojing");
			exit(0);
		}
		int inv=qpow(b[i][i],mod-2);
		for(int j=1;j<=tot+1;j++)b[i][j]=(LL)b[i][j]*inv%mod;
		for(int j=1;j<=tot;j++)if(i!=j)
		{
			int tmp=mod-b[j][i];
			for(int k=1;k<=tot+1;k++)b[j][k]=(b[j][k]+(LL)tmp*b[i][k])%mod;
		}
	}
}

int main()
{
	scanf("%d",&r);for(int i=0;i<4;i++)scanf("%d",a+i);
	
	all=a[0]+a[1]+a[2]+a[3];
	for(int i=0;i<4;i++)ia[i]=qpow(a[i],mod-2);
	for(int i=1;i<=101;i++)
	{
		for(int j=1;j<=101;j++)if((i-51)*(i-51)+(j-51)*(j-51)<=r*r)
		{
			if(!in[i-1][j])
			{
				id[i][j]=++tot;
				//printf("tot= %d i= %d j= %d\n",tot,i-50,j-50);
			}
			in[i][j]=1;
		}
	}
	for(int i=1;i<=101;i++)for(int j=1;j<=101;j++)if(in[i][j])
	{
		if(id[i][j])v[i][j]=vec(id[i][j]);
		else get_down(i-1,j);
		//printf("i= %d j= %d\n",i-50,j-50);
		//for(int k=1;k<=tot+1;k++)printf("%d ",v[i][j].a[k]);puts("");
	}
	for(int i=1;i<=101;i++)for(int j=1;j<=101;j++)if(in[i][j])
	{
		if(!in[i+1][j])get_func(i,j);
	}
	gauss();
	
	int ans=v[51][51].a[tot+1];
	for(int i=1;i<=tot;i++)ans=(ans+(LL)v[51][51].a[i]*b[i][tot+1])%mod;
	printf("%d\n",ans);
	
	return 0;
}
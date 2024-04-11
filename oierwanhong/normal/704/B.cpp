#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
typedef long long ll;
typedef std::pair<int,int> pii;
int read()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll min(ll a,ll b){return a<b?a:b;}
ll max(ll a,ll b){return a>b?a:b;}
template<typename T> bool umin(T& a,T t){if(a>t)return a=t,1;return 0;}
template<typename T> bool umax(T& a,T t){if(a<t)return a=t,1;return 0;}
/**********/
const int MAXN = 5011;
ll f[MAXN][MAXN],X[MAXN],a[MAXN],b[MAXN],c[MAXN],d[MAXN];
ll goLeft(int i){return X[i]+c[i];}
ll goRight(int i){return -X[i]+d[i];}
ll fromLeft(int i){return X[i]+a[i];}
ll fromRight(int i){return -X[i]+b[i];}
int main()
{
	int n=read(),s=read(),t=read();
	for(int i=1;i<=n;++i)X[i]=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=n;++i)b[i]=read();
	for(int i=1;i<=n;++i)c[i]=read();
	for(int i=1;i<=n;++i)d[i]=read();
	//f[i,j]: go right * j
	memset(f,0x3f,sizeof f);
	if(s==1)f[1][1]=goRight(1);
	else if(t==1)f[1][1]=fromRight(1);
	else f[1][2]=goRight(1)+fromRight(1);
	for(int i=2;i<=n;++i)
	{
		if(i==s)
		{
			for(int j=0;j<=n;++j)
			{
				if(j)umin(f[i][j],f[i-1][j-1]+goRight(i));
				umin(f[i][j],f[i-1][j+1]+goLeft(i));
			}
		
		}
		else if(i==t)
		{
			for(int j=0;j<=n;++j)
			{
				if(j)umin(f[i][j],f[i-1][j-1]+fromRight(i));
				umin(f[i][j],f[i-1][j+1]+fromLeft(i));
			}
		}
		else
		{
			for(int j=0;j<=n;++j)
			{
				if(j>2)umin(f[i][j],f[i-1][j-2]+fromRight(i)+goRight(i));
				umin(f[i][j],f[i-1][j+2]+fromLeft(i)+goLeft(i));
				if(j==0)continue;
				if(j>1)umin(f[i][j],f[i-1][j]+min(fromRight(i)+goLeft(i),fromLeft(i)+goRight(i)));
				else
				{
					if(i>s&&i>t)continue;
					if(i>s)umin(f[i][j],f[i-1][j]+fromLeft(i)+goRight(i));
					else if(i>t)umin(f[i][j],f[i-1][j]+fromRight(i)+goLeft(i));
					else umin(f[i][j],f[i-1][j]+min(fromRight(i)+goLeft(i),fromLeft(i)+goRight(i)));
				}
			}
		}
	}
	printf("%lld\n",f[n][0]);
	return 0;
}
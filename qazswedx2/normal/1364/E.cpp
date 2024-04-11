#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;
int n,a[100005],vis[100005],f[100005][2],g[100005][3];
int b[100005],c[100005],ct[105],lim=1,len=0,tct[105],h[100005];
int d[100005],cnt,e[100005];
int query(int x,int y)
{
	int ans=0;
	printf("? %d %d\n",x,y);
	fflush(stdout);
	scanf("%d",&ans);
	return ans;
}
/*int query(int x,int y)
{
	//printf("query:x=%d,y=%d,ans=%d,c=%d,%d\n",x,y,d[x]|d[y],d[x],d[y]);
	cnt++;
	return d[x]|d[y];
}*/
void init()
{
	for(int i=1;i<=n;i++)
		d[i]=i-1;
	for(int i=1;i<=n;i++)
		swap(d[i],d[rand()%i+1]);
//	for(int i=1;i<=n;i++)
//		printf("%d ",d[i]);
//	printf("\n");
}
bool cmp(const int x,const int y)
{
	return b[x]+c[x]<b[y]+c[y];
}
int main()
{
	srand(time(0));
	scanf("%d",&n);
	//init();
	while(lim<n) lim<<=1,len++;
	for(int i=1;i<=n;i++)
		a[i]=i;
	for(int i=1;i<=n;i++)
		swap(a[i],a[rand()%i+1]);
	for(int i=1;i+2<=n;i+=3)
	{
		int x=a[i],y=a[i+1],z=a[i+2],ans1,ans2,ans3;
		for(int i=0;i<len;i++)
			ct[i]=0;
		ans1=query(x,y);
		for(int i=0;i<len;i++)
			if(ans1&(1<<i)) ct[i]++;
		ans2=query(x,z);
		for(int i=0;i<len;i++)
			if(ans2&(1<<i)) ct[i]++;
		ans3=query(y,z);
		for(int i=0;i<len;i++)
			if(ans3&(1<<i)) ct[i]++;
		if(i==1) memcpy(tct,ct,sizeof(ct));
		for(int i=0;i<len;i++)
			if(ct[i]==2)
			{
			//	printf("i=%d,ans=%d,%d,%d\n",i,ans1,ans2,ans3);
				if(!(ans1&(1<<i))) b[z]+=(1<<i);
				if(!(ans2&(1<<i))) b[y]+=(1<<i);
				if(!(ans3&(1<<i))) b[x]+=(1<<i);
			}
			else if(ct[i]==3)
			{
			//	printf("i=%d,ans=%d,%d,%d,ct=%d\n",i,ans1,ans2,ans3,ct[i]);
				c[x]+=(1<<i),c[y]+=(1<<i),c[z]+=(1<<i);
			}
	}
	for(int i=n;i%3;i--)
	{
		memset(ct,0,sizeof(ct));
		int x=a[1],y=a[2],z=a[3],w=a[i],ans1,ans2,ans3;
		ans1=query(x,w);
		for(int i=0;i<len;i++)
			if(ans1&(1<<i)) ct[i]++;
		ans2=query(y,w);
		for(int i=0;i<len;i++)
			if(ans2&(1<<i)) ct[i]++;
		ans3=query(z,w);
		for(int i=0;i<len;i++)
			if(ans3&(1<<i)) ct[i]++;
		for(int i=0;i<len;i++)
			if(ct[i]<3)
			{
				if(tct[i]==3)
				{
					c[x]-=(1<<i),c[y]-=(1<<i),c[z]-=(1<<i);
					b[x]+=(1<<i),b[y]+=(1<<i),b[z]+=(1<<i);
					if(!(ans1&(1<<i))) b[x]-=(1<<i);
					if(!(ans2&(1<<i))) b[y]-=(1<<i);
					if(!(ans3&(1<<i))) b[z]-=(1<<i);
					tct[i]=0;
				}
			}
			else
			{
				if(tct[i]<3)
					b[w]+=(1<<i);
				else c[w]+=(1<<i);
			}
	}
	//for(int i=1;i<=n;i++)
	//	printf("i=%d,b=%d,c=%d\n",i,b[i],c[i]);
	for(int i=1;i<=n;i++)
		e[i]=i;
	sort(e+1,e+n+1);
	for(int i=1;i<=n;i++)
	{
		int v=(1<<len)-1-(b[i]+c[i]);
		vis[v]=i;
		h[i]=v;
	}
	for(int i=1;i<(1<<len);i++)
		if(vis[i])
			for(int j=i;j;j=(j-1)&i)
				if(!vis[j])
					vis[j]=vis[i];
	for(int i=1;i<(1<<len);i++)
		for(int j=i;j;j=(j-1)&i)
			if(vis[j]&&vis[i-j])
				f[i][0]=vis[j],f[i][1]=vis[i-j];
	for(int i=1;i<(1<<len);i++)
		for(int j=i;j;j=(j-1)&i)
			if(vis[j]&&f[i-j][0])
				g[i][0]=vis[j],g[i][1]=f[i-j][0],g[i][2]=f[i-j][1];
	for(int i=1;i<=n;i++)
	{
		int nwi=i;
		i=e[i];
		if(!c[i])
		{
			i=nwi;
			continue;
		}
		int x=0;
		if(vis[c[i]])
		{
			x=query(i,vis[c[i]]);
			b[i]+=(c[i]&x);
		}
		else if(f[c[i]][0])
		{
		//	printf("i=%d\n",i);
			int u=f[c[i]][0],nw=c[i];
			x=query(i,u);
			b[i]+=(h[u]&x&nw);
			nw-=(h[u]&c[i]);
			u=f[c[i]][1];
			x=query(i,u);
			b[i]+=(h[u]&x&nw);
		}
		else if(g[c[i]][0])
		{
			int u=g[c[i]][0],nw=c[i];
			x=query(i,u);
			b[i]+=(h[u]&x&nw);
			nw-=(h[u]&nw);
			u=g[c[i]][1];
			x=query(i,u);
			b[i]+=(h[u]&x&nw);
			nw-=(h[u]&nw);
			u=g[c[i]][2];
			x=query(i,u);
			b[i]+=(h[u]&x&nw);
		}
		h[i]=(1<<len)-1-b[i];
		vis[h[i]]=i;
		for(int j=h[i];j;j=(j-1)&h[i])
			if(!vis[j])
				vis[j]=i;
		i=nwi;
	}
	/*int fl=1;
	for(int i=1;i<=n;i++)
		if(d[i]!=b[i])
		{
			printf("Wrong Answer\n");
			fl=0;
			break;
		}
	if(!fl)
	{
		for(int i=1;i<=n;i++)
			printf("%d ",b[i]);
		printf("\n");
		for(int i=1;i<=n;i++)
			printf("%d ",d[i]);
		return 0;
	}
	printf("cnt=%d\n",cnt);*/
	printf("! ");
	for(int i=1;i<=n;i++)
		printf("%d ",b[i]);
	printf("\n");
	return 0;
}
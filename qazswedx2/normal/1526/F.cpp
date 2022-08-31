#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime> 
using namespace std;
int t,n,p[100005],a[100005],c[100005],q[100005],tans[100005];
#ifndef DEBUG
int query(int x,int y,int z)
{
	x=p[x],y=p[y],z=p[z];
	printf("? %d %d %d\n",x,y,z);
	fflush(stdout);
	int ans;
	scanf("%d",&ans);
	return ans;
}
#else
int b[100005];
inline int F(int x)
{
	return x>=0?x:-x;
}
int query(int x,int y,int z)
{
	x=p[x],y=p[y],z=p[z];
	int v[3];
	v[0]=F(b[x]-b[y]),v[1]=F(b[y]-b[z]),v[2]=F(b[z]-b[x]);
	sort(v,v+3);
//	printf("query:x=%d,y=%d,z=%d,v=%d\n",x,y,z,v[1]);
	return v[1];
}
#endif
int main()
{
#ifdef DEBUG
	freopen("CF1526F.in","r",stdin);
	freopen("CF1526F.out","w",stdout);
#endif
	srand(time(0));
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
#ifdef DEBUG
		for(int i=1;i<=n;i++)
			scanf("%d",&b[i]);
#endif
		for(int i=1;i<=n;i++)
			p[i]=i;
		while(1)
		{
			random_shuffle(p+1,p+n+1);
			for(int i=1;i<=n;i++)
				c[i]=0;
			int fl=1,qfl=0;
			for(int i=3;i<=n;i++)
			{
				q[i]=query(1,2,i);
				c[q[i]]++;
				if(c[q[i]]>=3) qfl=1;
				if(c[q[i]]>=3&&q[i]>=n/3-2)
				{
					fl=0;
					break;
				}
				if(i==30&&qfl==0)
				{
					int nw=0;
					for(int j=1;j<n/3-1;j++)
						if(c[j]) nw=1;
					if(!nw)
					{
						fl=0;
						break;
					}
				}
			}
			if(qfl==0)
			{
				int nw=0;
				for(int j=1;j<n/3-1;j++)
					if(c[j]) nw=1;
				if(!nw)
					fl=0;
			}
			if(fl) break;
		}
		int mx=-1,id=-1,id2=-1,id3=-1;
		for(int i=n;i;i--)
			if(c[i])
			{
				mx=i;
				break;
			}
		for(int i=1;i<=n;i++)
		{
			if(q[i]==mx) id=i;
			if(q[i]==mx-1)
			{
				if(id2==-1) id2=i;
				else id3=i;
			}
		}
/*#ifdef DEBUG
		printf("mx=%d,id=%d,id2=%d,id3=%d\n",mx,id,id2,id3);
		for(int i=1;i<=n;i++)
			printf("%d ",c[i]);
		printf("\n");
#endif */
		if(id3!=-1)
		{
			int q2=query(1,id,id2),q3=query(1,id,id3);
			if(q2>q3) id2=id3;
		}
		a[id]=1,a[id2]=2;
		for(int i=1;i<=n;i++)
		{
			if(i==id||i==id2) continue;
			a[i]=query(id,id2,i)+2;
		}
		for(int i=1;i<=n;i++)
			tans[p[i]]=a[i];
		if(tans[1]>tans[2])
		{
			for(int i=1;i<=n;i++)
				tans[i]=n+1-tans[i];
		}
		printf("! ");
		for(int i=1;i<=n;i++)
			printf("%d ",tans[i]);
		printf("\n");
		fflush(stdout);
		int q;
		scanf("%d",&q);
	}
	return 0;
}
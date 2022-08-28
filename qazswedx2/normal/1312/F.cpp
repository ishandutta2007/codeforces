#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
struct pt
{
	int x,y,z;
	pt(int x=0,int y=0,int z=0):x(x),y(y),z(z){} 
	bool operator<(const pt a) const
	{
		if(x!=a.x) return x<a.x;
		if(y!=a.y) return y<a.y;
		return z<a.z;
	}
};
map<pt,int> mp;
int t,n,g[15][15][15][2];
ll a[1000005];
vector<pt> f[15][15][15];
inline int getmex(int a=-1,int b=-1,int c=-1)
{
	if(a!=0&&b!=0&&c!=0) return 0;
	if(a!=1&&b!=1&&c!=1) return 1;
	if(a!=2&&b!=2&&c!=2) return 2;
	return 3;
}
inline int getval(int x,int id)
{
	return (x>>((id-1)*2))&3;
}
pt getnxt(pt p,int a,int b,int c)
{
	int nwx,nwy,nwz;
	nwx=getmex(getval(p.x,a),getval(p.y,b),getval(p.z,c));
	nwy=getmex(getval(p.x,a),getval(p.z,c));
	nwz=getmex(getval(p.x,a),getval(p.y,b));
//	if(a==1&&b==3&&c==4) printf("nxt:x=%d,y=%d,z=%d\n",nwx,nwy,nwz);
	p.x=((p.x<<2)+nwx)&4095;
	p.y=((p.y<<2)+nwy)&4095;
	p.z=((p.z<<2)+nwz)&4095;
	return p;
}
int getway(pt p,int a,int b,int c,int to)
{
	a++,b++,c++;
//	printf("nw=%d,%d,%d,to=%d\n",nwx,nwy,nwz,to);
	return (getval(p.x,a)==to)+(getval(p.y,b)==to)+(getval(p.z,c)==to);
}
void print(pt x)
{
	printf("x=");
	for(int i=5;i;i--)
		printf("%d",getval(x.x,i));
	printf(",y=");
	for(int i=5;i;i--)
		printf("%d",getval(x.y,i));
	printf(",z=");
	for(int i=5;i;i--)
		printf("%d",getval(x.z,i));
	printf("\n");
}
int main()
{
	for(int i=1;i<=5;i++)
		for(int j=1;j<=5;j++)
			for(int k=1;k<=5;k++)
			{
				mp.clear();
				f[i][j][k].push_back(pt());
				mp[pt()]=0;
				//printf("i=%d,j=%d,k=%d\n",i,j,k);
				pt nw;
			//	if(i==1&&j==3&&k==4) print(nw);
				int ct=0;
				while(1)
				{
					ct++;
					nw=getnxt(nw,i,j,k);
			//	if(i==1&&j==3&&k==4) print(nw);
					if(mp.count(nw))
					{
						g[i][j][k][0]=mp[nw];
						g[i][j][k][1]=ct-mp[nw];
						break;
					}
					f[i][j][k].push_back(nw);
					mp[nw]=ct;
				}
			}
	scanf("%d",&t);
	while(t--)
	{
		int x,y,z;
		scanf("%d%d%d%d",&n,&x,&y,&z);
		for(int i=1;i<=n;i++)
			scanf("%I64d",&a[i]);
		int s=g[x][y][z][0],len=g[x][y][z][1],ans=0;
		for(int i=1;i<=n;i++)
		{
			int nw;
			if(a[i]<s) nw=a[i];
			else nw=(a[i]-s)%len+s;
			ans^=getval(f[x][y][z][nw].x,1);
		//	printf("i=%d,ans=%d\n",i,ans);
		}
		if(!ans)
		{
			printf("0\n");
			continue;
		}
		int ct=0;
		for(int i=1;i<=n;i++)
		{
			int nw;
			if(a[i]<s) nw=a[i];
			else nw=(a[i]-s)%len+s;
			ct+=getway(f[x][y][z][nw],x,y,z,getval(f[x][y][z][nw].x,1)^ans);
		//	printf("i=%d,ct=%d\n",i,ct);
		}
		printf("%d\n",ct);
	}
	return 0;
}
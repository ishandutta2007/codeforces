#include<cstdio>
#include<cstring>
#include<algorithm>
#include<random>
#include<ctime>
#include<vector>
using namespace std;
const int mod[55]={983436799,983436809,983436821,983436841,983436851,983436911,983436931,983436973,983436983,983436991,983437003,983437019,983437027,983437031,983437051,983437123,983437127,983437141,983437163,983437177,983437187,983437223,983437249,983437261,983437271,983437309,983437331,983437333,983437339,983437363,983437387,983437421,983437423,983437487,983437489,983437501,983437577,983437579,983437613,983437619,983437667,983437687,983437699,983437711,983437747,983437753,983437771,983437787,983437813,983437877,983437921};
const int B=40,bs=28373;
int n,m1,m2,m3;
int pw1[1000005],pw2[1000005],pw3[1000005],pn=1e6;
char s[1000005],s2[1000005];
struct pt
{
	int v1,v2,v3;
	pt(int v1=0,int v2=0,int v3=0):v1(v1),v2(v2),v3(v3){}
	bool operator==(const pt x) const
	{
		return v1==x.v1&&v2==x.v2&&v3==x.v3;
	}
};
vector<pt> val[2000005];
pt getlink(pt x,pt y,int len)
{
	return pt((1ll*x.v1*pw1[len]+y.v1)%mod[m1],
			  (1ll*x.v2*pw2[len]+y.v2)%mod[m2],
			  (1ll*x.v3*pw3[len]+y.v3)%mod[m3]);
}
mt19937 rnd(time(0));
void build(int x,int l,int r)
{
	if(l==r)
	{
		val[x].push_back(pt(s[l],s[l],s[l]));
		return;
	}
	int mid=(l+r)/2;
	build(x*2,l,mid);
	build(x*2+1,mid+1,r);
	int len=r-l+1;
	for(int i=0;i<len/2;i++)
	{
		val[x].push_back(getlink(val[x*2][i],val[x*2+1][i],len/2));
	}
	for(int i=0;i<len/2;i++)
	{
		val[x].push_back(getlink(val[x*2+1][i],val[x*2][i],len/2));
	}
//	printf("x=%d,l=%d,r=%d,len=%d\n",x,l,r,len);
}
int getcmp(int len,int x,int y,int a,int b)
{
	if(val[x][a&(len-1)]==val[y][b&(len-1)]) return 0;
	if(len==1)
	{
		return s[x-n]-s[y-n];
	}
//	int xmid=(xl+xr)/2,ymid=(yl+yr)/2;
	int q=len/2;
	int nw=getcmp(q,x*2+(a&q?1:0),y*2+(b&q?1:0),a,b);
	if(nw) return nw;
	return getcmp(q,x*2+(a&q?0:1),y*2+(b&q?0:1),a,b);
}
int main()
{
	m1=rnd()%B;
	m2=rnd()%B;
	m3=rnd()%B;
	while(m1==m2||m1==m3||m2==m3)
	{
		m1=rnd()%B;
		m2=rnd()%B;
		m3=rnd()%B;
	}
	pw1[0]=pw2[0]=pw3[0]=1;
	for(int i=1;i<=pn;i++)
	{
		pw1[i]=1ll*pw1[i-1]*bs%mod[m1];
		pw2[i]=1ll*pw2[i-1]*bs%mod[m2];
		pw3[i]=1ll*pw3[i-1]*bs%mod[m3];
	}
	scanf("%d",&n);
	scanf("%s",s);
	n=strlen(s);
/*	for(int i=n;i<2*n;i++)
	{
		val[i].push_back(pt(s[i],s[i],s[i]));
	}*/
	build(1,0,n-1);
/*	for(int i=0;i<2*n;i++)
	{
		printf("i=%d,val=",i);
		for(int j=0;j<val[i].size();j++)
		{
			printf("%d,%d,%d ",val[i][j].v1,val[i][j].v2,val[i][j].v3);
		}
		printf("\n");
	}*/
	int mn=0;
	for(int i=1;i<n;i++)
	{
		int nw=getcmp(n,1,1,mn,i);
	//	printf("i=%d,mn=%d,nw=%d\n",i,mn,nw);
		if(nw>0) mn=i;
	}
	for(int i=0;i<n;i++)
		s2[i]=s[i^mn];
	printf("%s\n",s2);
	return 0;
}
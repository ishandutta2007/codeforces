#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n,bl=1<<8,f[100005],ft,m,a[100005],b[100005],ct,tans[2500005][2],tt;
int tmp[100005],qans[100005];
vector<vector<int>> val[20];
int merge(int x,int y)
{
	if(!x||!y) return x+y;
	ct++;
	tans[++tt][0]=x;
	tans[tt][1]=y;
	return ct;
}
vector<vector<int>> solve(int l,int r)
{
	vector<vector<int>> ans,lans,rans;
//	printf("solve:l=%d,r=%d\n",l,r);
	int len=r-l+1;
	ans.resize(len+1);
	for(int i=1;i<=len;i++)
		ans[i].resize(len+1);
	if(l==r)
	{
		ans[1][1]=b[l];
		return ans;
	}
	int mid=(l+r)/2;
	lans=solve(l,mid);
	rans=solve(mid+1,r);
	for(int i=l;i<=r;i++)
		tmp[i]=b[i];
	sort(tmp+l,tmp+r+1);
	for(int i=l;i<=r;i++)
		for(int j=i;j<=r;j++)
		{
			int ll=lower_bound(b+l,b+mid+1,tmp[i])-b-l+1,q1=0,q2=0;
			int rr=upper_bound(b+l,b+mid+1,tmp[j])-b-l;
			if(ll<=rr) q1=lans[ll][rr];
			ll=lower_bound(b+mid+1,b+r+1,tmp[i])-b-mid;
			rr=upper_bound(b+mid+1,b+r+1,tmp[j])-b-mid-1;
			if(ll<=rr) q2=rans[ll][rr];
			ans[i-l+1][j-l+1]=merge(q1,q2);
//			printf("i=%d,j=%d,ans=%d,q1=%d,q2=%d\n",i,j,ans[i-l+1][j-l+1],q1,q2);
		}
	for(int i=l;i<=r;i++)
		b[i]=tmp[i];
//	printf("solve:l=%d,r=%d\n",l,r);
	return ans;
}
int query(int x,int L,int R,int l,int r)
{
	int ll=lower_bound(b+L,b+R+1,l)-b-L+1,rr=upper_bound(b+L,b+R+1,r)-b-L;
//	printf("query:L=%d,R=%d,ll=%d,rr=%d\n",L,R,ll,rr);
	if(ll>rr) return 0;
	return val[x][ll][rr];
}
int main()
{
	scanf("%d%d",&n,&m);
	ct=n;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		b[a[i]]=i;
	for(int i=1;i<=n;i+=bl)
		f[++ft]=i;
	f[++ft]=n+1;
	for(int i=1;i<ft;i++)
		val[i]=solve(f[i],f[i+1]-1);
	for(int i=1;i<=m;i++)
	{
		int l,r,ans=0;
		scanf("%d%d",&l,&r);
		for(int j=1;j<ft;j++)
			ans=merge(ans,query(j,f[j],f[j+1]-1,l,r));
		qans[i]=ans;
	}
	printf("%d\n",ct);
	for(int i=1;i<=tt;i++)
		printf("%d %d\n",tans[i][0],tans[i][1]);
	for(int i=1;i<=m;i++)
		printf("%d ",qans[i]);
	return 0;
}
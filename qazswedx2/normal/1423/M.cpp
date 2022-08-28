#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int query(int x,int y)
{
	printf("? %d %d\n",x,y);
	fflush(stdout);
	int ans;
	scanf("%d",&ans);
	return ans;
}
/*int val[105][105];
int query(int x,int y)
{
	printf("query:x=%d,y=%d\n",x,y);
	return val[x][y];
}*/
int ans=1e9,st[1000005],tp;
int f[1000005],tmp[1000005],M;
void solve(vector<int> r,vector<int> c)
{
	int n=r.size(),m=c.size();
//	printf("solve:n=%d,m=%d\n",n,m);
	if(n<m)
	{
		tp=0;
		for(int i=1;i<=m;i++)
		{
			while(tp>0&&query(r[tp-1],c[st[tp]-1])>=query(r[tp-1],c[i-1]))
				tp--;
			if(tp<n) st[++tp]=i;
		}
		vector<int> cc;
		for(int i=1;i<=tp;i++)
			cc.push_back(c[st[i]-1]);
		solve(r,cc);
		return;
	}
	if(n==1)
	{
		ans=min(ans,query(r[0],c[0]));
		f[r[0]]=c[0];
		return;
	}
	vector<int> rr;
	for(int i=1;i<=n;i+=2)
		rr.push_back(r[i-1]);
	solve(rr,c);
	int ct=0;
	for(int i=0;i<m;i++)
		tmp[i]=c[i];
//	printf("ssolve:n=%d,m=%d\n",n,m);
	for(int i=2;i<=n;i+=2)
	{
		int L=f[rr[ct]],R;
		if(ct+1<(int)rr.size()) R=f[rr[ct+1]];
		else R=M;
		//printf("i=%d,r=%d,L=%d,R=%d\n",i,r[i-1],L,R);
		L=lower_bound(tmp,tmp+m,L)-tmp;
		R=upper_bound(tmp,tmp+m,R)-tmp-1;
		//printf("i=%d,r=%d,L=%d,R=%d\n",i,r[i-1],L,R);
		int mn=1e9+1,id=0;
		for(int j=L;j<=R;j++)
		{
			int q=query(r[i-1],c[j]);
			if(q<mn)
			{
				mn=q;
				id=j;
			}
		}
		f[r[i-1]]=c[id];
		ans=min(ans,mn);
		ct++;
	}
}
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	M=m;
	//for(int i=1;i<=n;i++)
	//	for(int j=1;j<=m;j++)
	//		scanf("%d",&val[i][j]);
	vector<int> v1,v2;
	for(int i=1;i<=n;i++)
		v1.push_back(i);
	for(int i=1;i<=m;i++)
		v2.push_back(i);
	solve(v1,v2);
	printf("! %d\n",ans);
	return 0;
}
#include <bits/stdc++.h>
#define INF 1000000000
#define F first
#define S second
#define N 400010
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
using namespace std;
char buf[1<<23],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
int rint(){
	int ret=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret;
}
void print(int x) {
    if(x>9) print(x/10);
    *O++=x%10+'0';
}
struct SegT{
	int lo[N<<2],hi[N<<2],v[5][N<<2],pre[N],idx[N];
	void build(int x,int l,int r)
	{
		lo[x]=l,hi[x]=r,v[0][x]=v[1][x]=v[2][x]=v[3][x]=INF;
		if(l==r)
		{
			idx[l]=x;
			v[4][x]=pre[l];
			return;
		}
		int mid=(l+r)>>1,a=x<<1;
		build(a,l,mid);
		build(a|1,mid+1,r);
		v[4][x]=(v[4][a]<v[4][a|1])?v[4][a]:v[4][a|1];
		return;
	}
	void update(int l,int val0,int val1,int val2,int val3)
	{
		v[0][idx[l]]=val0,v[1][idx[l]]=val1,v[2][idx[l]]=val2,v[3][idx[l]]=val3;
		for(int x=idx[l]>>1;x;x>>=1)
		{
			v[0][x]=(v[0][x<<1]<v[0][x<<1|1])?v[0][x<<1]:v[0][x<<1|1],v[1][x]=(v[1][x<<1]<v[1][x<<1|1])?v[1][x<<1]:v[1][x<<1|1],v[2][x]=(v[2][x<<1]<v[2][x<<1|1])?v[2][x<<1]:v[2][x<<1|1],v[3][x]=(v[3][x<<1]<v[3][x<<1|1])?v[3][x<<1]:v[3][x<<1|1];
		}
		return;
	}
	int query(int x,int l,int r,int id)
	{
		int tl=lo[x],tr=hi[x];
		if(l<=tl&&tr<=r)
		{
			return v[id][x];
		}
		int mid=(tl+tr)>>1,a=x<<1,ret=INF;
		if(mid>=l)
		{
			ret=query(a,l,r,id);
		}
		if(mid<r)
		{
			ret=min(ret,query(a|1,l,r,id));
		}
		return ret;
	}
}segt;
struct SegT2{
	int lo[N<<2],hi[N<<2],v[2][N<<2],pre[N],idx[N];
	void build(int x,int l,int r)
	{
		lo[x]=l,hi[x]=r,v[0][x]=v[1][x]=INF;
		if(l==r)
		{
			idx[l]=x;
			return;
		}
		int mid=(l+r)>>1,a=x<<1;
		build(a,l,mid);
		build(a|1,mid+1,r);
		return;
	}
	void update(int l,int val0,int val1)
	{
		v[0][idx[l]]=val0,v[1][idx[l]]=val1;
		for(int x=idx[l]>>1;x;x>>=1)
		{
			v[0][x]=(v[0][x<<1]<v[0][x<<1|1])?v[0][x<<1]:v[0][x<<1|1],v[1][x]=(v[1][x<<1]<v[1][x<<1|1])?v[1][x<<1]:v[1][x<<1|1];
		}
		return;
	}
	int query(int x,int l,int r,int id)
	{
		int tl=lo[x],tr=hi[x];
		if(l<=tl&&tr<=r)
		{
			return v[id][x];
		}
		int mid=(tl+tr)>>1,a=x<<1,ret=INF;
		if(mid>=l)
		{
			ret=query(a,l,r,id);
		}
		if(mid<r)
		{
			ret=min(ret,query(a|1,l,r,id));
		}
		return ret;
	}
}segt2;
int n,q,a[N],ans[N];
pair<int,int> stk[N];
vector<pair<pair<int,int>,pair<int,int> > > qry[N],qrys0[N],qrys1[N];
int main(){
	int l1,l2,r1,r2;
	n=rint();
	for(int i=1;i<=n;++i)
	{
		a[i]=rint();
		segt.pre[i]=a[i];
	}
	segt.build(1,1,n);
	q=rint();
	for(int i=0;i<q;++i)
	{
		l1=rint(),r1=rint(),l2=rint(),r2=rint();
		qry[l2].push_back(make_pair(make_pair(l1,r1),make_pair(r2,i)));
		if(l1<l2)
		{
			qrys0[l1].push_back(make_pair(make_pair(l2,r1),make_pair(r2,i)));
			qrys1[l2].push_back(make_pair(make_pair(l1,r1),make_pair(r2,i)));
		}
		else
		{
			qrys0[l2].push_back(make_pair(make_pair(l1,r1),make_pair(r2,i)));
			qrys1[l1].push_back(make_pair(make_pair(l2,r1),make_pair(r2,i)));
		}
		ans[i]=abs(l2-l1)+min(r2+1,abs(min(r1,segt.query(1,min(l1,l2),max(l1,l2),4))-r2));
	}
	int len=0;
	for(int i=n;i>0;--i)
	{
		while(len&&stk[len-1].F>=a[i])
		{
			segt.update(stk[len-1].S,INF,INF,INF,INF);
			--len;
		}
		segt.update(i,2*i+a[i],2*i-a[i],a[i],-a[i]);
		stk[len++]=make_pair(a[i],i);
		for(int j=0;j<qry[i].size();++j)
		{
			l1=qry[i][j].F.F,r1=qry[i][j].F.S,r2=qry[i][j].S.F;
			pair<int,int> tmp=make_pair(r2,-INF);
			int x=lower_bound(stk,stk+len,tmp)-stk,y=stk[x].S,id=qry[i][j].S.S;
			if(l1<=y)
			{
				ans[id]=min(ans[id],segt.query(1,l1,y,0)-l1-i-r2+1);
			}
			if(y<n)
			{
				ans[id]=min(ans[id],segt.query(1,max(l1,y+1),n,1)-l1-i+r2+1);
			}
			if(l1>i)
			{
				ans[id]=min(ans[id],segt.query(1,i,min(l1-1,y),2)+l1-i-r2+1);
			}
			if(y+1<l1)
			{
				ans[id]=min(ans[id],segt.query(1,y+1,l1-1,3)+l1-i+r2+1);
			}
		}
	}
	segt.build(1,1,n);
	len=0;
	for(int i=1;i<=n;++i)
	{
		while(len&&stk[len-1].F>=a[i])
		{
			segt.update(stk[len-1].S,INF,INF,INF,INF);
			--len;
		}
		segt.update(i,a[i],-a[i],-2*i+a[i],-2*i-a[i]);
		stk[len++]=make_pair(a[i],i);
		for(int j=0;j<qry[i].size();++j)
		{
			l1=qry[i][j].F.F,r1=qry[i][j].F.S,r2=qry[i][j].S.F;
			pair<int,int> tmp=make_pair(r2,-INF);
			int x=lower_bound(stk,stk+len,tmp)-stk,y=stk[x].S,id=qry[i][j].S.S;
			if(l1<=i)
			{
				ans[id]=min(ans[id],segt.query(1,max(l1,y),i,0)-l1+i-r2+1);
			}
			if(l1<y)
			{
				ans[id]=min(ans[id],segt.query(1,l1,y-1,1)-l1+i+r2+1);
			}
			if(l1>y)
			{
				ans[id]=min(ans[id],segt.query(1,y,l1-1,2)+l1+i-r2+1);
			}
			if(y>0)
			{
				ans[id]=min(ans[id],segt.query(1,1,min(y,l1)-1,3)+l1+i+r2+1);
			}
		}
	}
	segt2.build(1,1,n);
	len=0;
	for(int i=n;i>0;--i)
	{
		while(len&&stk[len-1].F>=a[i])
		{
			segt2.update(stk[len-1].S,INF,INF);
			--len;
		}
		segt2.update(i,2*i+a[i],2*i-a[i]);
		stk[len++]=make_pair(a[i],i);
		for(int j=0;j<qrys0[i].size();++j)
		{
			l1=qrys0[i][j].F.F,r1=qrys0[i][j].F.S,r2=qrys0[i][j].S.F;
			pair<int,int> tmp=make_pair(r2,-INF);
			int x=lower_bound(stk,stk+len,tmp)-stk,y=(x==len)?i-1:stk[x].S,id=qrys0[i][j].S.S;
			tmp=make_pair(r1,-INF);
			int st=lower_bound(stk,stk+len,tmp)-stk;
			st=(st==len)?i-1:stk[st].S;
			st=max(st,l1-1);
			if(st<y)
			{
				ans[id]=min(ans[id],segt2.query(1,st+1,y,0)-i-l1-r2);
			}
			if(st<n&&y<n)
			{
				ans[id]=min(ans[id],segt2.query(1,max(st,y)+1,n,1)-i-l1+r2);
			}
		}
	}
	segt2.build(1,1,n);
	len=0;
	for(int i=1;i<=n;++i)
	{
		while(len&&stk[len-1].F>=a[i])
		{
			segt2.update(stk[len-1].S,INF,INF);
			--len;
		}
		segt2.update(i,-2*i+a[i],-2*i-a[i]);
		stk[len++]=make_pair(a[i],i);
		for(int j=0;j<qrys1[i].size();++j)
		{
			l1=qrys1[i][j].F.F,r1=qrys1[i][j].F.S,r2=qrys1[i][j].S.F;
			pair<int,int> tmp=make_pair(r2,-INF);
			int x=lower_bound(stk,stk+len,tmp)-stk,y=(x==len)?i+1:stk[x].S,id=qrys1[i][j].S.S;
			tmp=make_pair(r1,-INF);
			int st=lower_bound(stk,stk+len,tmp)-stk;
			st=(st==len)?i+1:stk[st].S;
			st=min(st,l1+1);
			if(y<st)
			{
				ans[id]=min(ans[id],segt2.query(1,y,st-1,0)+i+l1-r2);
			}
			if(st>1&&y)
			{
				ans[id]=min(ans[id],segt2.query(1,1,min(st,y)-1,1)+i+l1+r2);
			}
		}
	}
	for(int i=0;i<q;++i)
	{
		O=obuf;
		print(ans[i]),fwrite(obuf,O-obuf,1,stdout);
		putchar('\n');
	}
	return 0;
}
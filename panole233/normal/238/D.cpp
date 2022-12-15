#include<bits/stdc++.h>
using namespace std;

struct node{int s[10];};
pair<int,int> sta[100001];
struct seg{int l,r,val;}t[400100];
struct que{int l,r,po;}q[100010];
bool cmp(que a,que b) {return a.r<b.r;}
node s[100010],laz,sum0[100010],sum1[100010],ans[100010];
int n,Q,nxt[100010],la[100010],f[100010][18],o[21],oN,lo[100010],tp,L,R,Mid,Ans;
char str[100010];

node operator +(node A,node B)
{
	for (int i=0; i<10; i++) A.s[i]+=B.s[i];
	return A;
}

node operator -(node A,node B)
{
	for (int i=0; i<10; i++) A.s[i]-=B.s[i];
	return A;
}

int getmax(int l,int r)
{
	int len=lo[r-l+1];
	return max(f[l][len],f[r-(1<<len)+1][len]);
}

void build(int i,int l,int r)
{
	t[i].l=l,t[i].r=r,t[i].val=n+1;
	if (l==r) return;
	int mid=(l+r)>>1;
	build(i<<1,l,mid),build(i<<1|1,mid+1,r);
}

int query(int i,int l,int r)
{
	if (t[i].l==l&&t[i].r==r) return t[i].val;
	int mid=(t[i].l+t[i].r)>>1;
	if (r<=mid) return query(i<<1,l,r);
	if (l>mid) return query(i<<1|1,l,r);
	return min(query(i<<1,l,mid),query(i<<1|1,mid+1,r));	
}

void change(int i,int x,int v)
{
	if (t[i].l==t[i].r) {t[i].val=v; return;}
	int mid=(t[i].l+t[i].r)>>1;
	if (x<=mid) change(i<<1,x,v);
	else change(i<<1|1,x,v);
	t[i].val=min(t[i<<1].val,t[i<<1|1].val);
}

int find(int i,int l,int v)
{
	if (t[i].l==t[i].r) return t[i].l;
	int mid=(t[i].l+t[i].r)>>1;
	if (l>mid) return find(i<<1|1,l,v);
	if (query(i,l,mid)<v) return find(i<<1,l,v);
	else return find(i<<1|1,mid+1,v);
}

void print(int x)
{
	if (!x) putchar('0'); else
	{
		oN=0;
		while (x) o[++oN]=x%10,x/=10;
		for (int i=oN; i; i--) putchar(o[i]+48);
	}
	putchar(' ');
}

int main()
{
	lo[1]=0;
	for (int i=2; i<=100000; i++) lo[i]=lo[i>>1]+1;
	scanf("%d%d",&n,&Q),scanf("%s",str+1);
	la[0]=0;
	for (int i=1; i<=n; i++) 
		if (str[i]=='<'||str[i]=='>') la[i]=i;
		else la[i]=la[i-1];
	nxt[n+1]=n+1;
	for (int i=n; i; i--)
		if (str[i]=='<'||str[i]=='>') nxt[i]=i;
		else nxt[i]=nxt[i+1];
	for (int i=1; i<=n; i++)
		if (str[i]=='<'||str[i]=='>') f[i][0]=-1;
		else f[i][0]=str[i]-'0';
	for (int j=1; j<=17; j++)
		for (int i=1; i<=n; i++)
			if (i+(1<<j)<=n+1)
				f[i][j]=max(f[i][j-1],f[i+(1<<j-1)][j-1]);
	memset(sum0,0,sizeof(sum0));
	memset(sum1,0,sizeof(sum1));
	for (int i=1; i<=n; i++)
	{
		sum0[i]=sum0[i-1],sum1[i]=sum1[i-1];
		if (str[i]>='0'&&str[i]<='9')
		{
			sum0[i].s[str[i]-'0']++;
			if (str[i]!='0') sum1[i].s[str[i]-'1']++;
		}
	}
	build(1,1,n);
	for (int i=1; i<=Q; i++) scanf("%d%d",&q[i].l,&q[i].r),q[i].po=i;
	sort(q+1,q+1+Q,cmp),tp=0;
	memset(laz.s,0,sizeof(laz.s));
	memset(s[0].s,0,sizeof(s[0].s));
	for (int i=1,po,p,nwq=1; i<=n; i++)
	{
		if (str[i]=='<')
		{
			p=po=la[i-1];
			while (p)
			{
				if (str[p]=='<') 
				{
					laz=(laz-(sum1[sta[tp].second]-sum1[sta[tp].first]));
					po=sta[tp].second,p=sta[tp].first,tp--; continue;
				}
				if (getmax(po,nxt[po+1])&1) po=p=la[p-1];
				else break;
			}
			sta[++tp]=make_pair(p,i);
			laz=(laz+(sum1[i]-sum1[p]));
			s[tp]=((sum1[i]-sum1[p])-laz);
			change(1,i,p);
		}
		while (nwq<=Q&&q[nwq].r==i)
		{
			if (query(1,q[nwq].l,q[nwq].r)<q[nwq].l) 
			{
				p=find(1,q[nwq].l,q[nwq].l);
				ans[q[nwq].po]=(sum1[p]-sum1[nxt[q[nwq].l]]);
				for (int i=8; i>=0; i--) ans[q[nwq].po].s[i]+=ans[q[nwq].po].s[i+1];
				ans[q[nwq].po]=(ans[q[nwq].po]+(sum0[p]-sum0[q[nwq].l-1]));
				ans[q[nwq].po]=(ans[q[nwq].po]+(sum1[nxt[q[nwq].l]]-sum1[q[nwq].l-1]));
			} else
			{
				L=1,R=tp,Ans=0;
				while (L<=R)
				{
					Mid=(L+R)>>1;
					if (sta[Mid].second>=q[nwq].l) Ans=Mid,R=Mid-1; else L=Mid+1;
				}
				if (Ans)
				{
					ans[q[nwq].po]=(s[Ans]+laz);
					for (int i=8; i>=0; i--) ans[q[nwq].po].s[i]+=ans[q[nwq].po].s[i+1];
					ans[q[nwq].po]=(ans[q[nwq].po]+(sum0[i]-sum0[q[nwq].l-1]));
				} else ans[q[nwq].po]=(sum0[i]-sum0[q[nwq].l-1]);
			}
			nwq++;
		}
	}
	for (int i=1; i<=Q; i++,putchar('\n'))
		for (int j=0; j<10; j++) print(ans[i].s[j]);
	return 0;
}
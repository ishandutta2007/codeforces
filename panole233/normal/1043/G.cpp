#include<cstdio>
#include<cstring>
#include<cmath>

const int N=500,inf=(1e9);
int h[400101],H[401001],n,rk[401001][3],cnt,ans1[401001],sq[1001],k,x,y,hd[401001],nxt[401001],n1[410001],n2[401001],n3[410001],sum[200011][26],f[400101][19],tmp,lo[400101],p[200101][10],pn[200101],q,l,r;
char s[401001];
bool b[1001];

int getmax(int a,int b) {return a>b?a:b;}
int getmin(int a,int b) {return a<b?a:b;}

int lcp(int x,int y)
{
	if (x<n&&y>=n||x>=n&&y<n) return 0;
	x=rk[x][0]; y=rk[y][0];
	if (x>y) tmp=x,x=y,y=tmp;
	y--; int len=lo[y-x+1];
	return getmin(f[x][len],f[y-(1<<len)+1][len]);
}

struct node2
{
	int i,l,r,val;
}T[800001],t[800001];

void build(int i,int l,int r)
{
	t[i].l=l; t[i].r=r; t[i].val=-inf;
	if (l==r) return;
	int mid=(l+r)>>1;
	build(i<<1,l,mid); build(i<<1|1,mid+1,r);
}

void pushdown(int i)
{
	if (t[i].l==t[i].r||t[i].val==-inf) return;
	t[i<<1].val=getmax(t[i<<1].val,t[i].val);
	t[i<<1|1].val=getmax(t[i<<1|1].val,t[i].val);
	t[i].val=-inf;
}

void change(int i,int l,int r,int v)
{
	pushdown(i);
	if (l==t[i].l&&r==t[i].r) {t[i].val=getmax(t[i].val,-v); return;}
	int mid=(t[i].l+t[i].r)>>1;
	if (r<=mid) change(i<<1,l,r,v); else
	if (l>mid) change(i<<1|1,l,r,v); else
	change(i<<1,l,mid,v),change(i<<1|1,mid+1,r,v);
}

void WORK(int i)
{
	pushdown(i);
	if (t[i].l==t[i].r) {t[i].val+=t[i].l; return;}
	WORK(i<<1); WORK(i<<1|1);
	t[i].val=getmax(t[i<<1].val,t[i<<1|1].val);
}

int query(int i,int l,int r)
{
	if (t[i].l==l&&t[i].r==r) return t[i].val;
	int mid=(t[i].l+t[i].r)>>1;
	if (r<=mid) return query(i<<1,l,r);
	if (l>mid) return query(i<<1|1,l,r);
	return getmax(query(i<<1,l,mid),query(i<<1|1,mid+1,r));
}

void Build(int i,int l,int r)
{
	T[i].l=l; T[i].r=r; T[i].val=inf;
	if (l==r) return;
	int mid=(l+r)>>1;
	Build(i<<1,l,mid); Build(i<<1|1,mid+1,r);
}

void Pushdown(int i)
{
	if (T[i].l==T[i].r||T[i].val==inf) return;
	T[i<<1].val=getmin(T[i<<1].val,T[i].val);
	T[i<<1|1].val=getmin(T[i<<1|1].val,T[i].val);
	T[i].val=inf;
}

void Change(int i,int l,int r,int v)
{
	Pushdown(i);
	if (l==T[i].l&&r==T[i].r) {T[i].val=getmin(T[i].val,v); return;}
	int mid=(T[i].l+T[i].r)>>1;
	if (r<=mid) Change(i<<1,l,r,v); else
	if (l>mid) Change(i<<1|1,l,r,v); else
	Change(i<<1,l,mid,v),Change(i<<1|1,mid+1,r,v);
}

void Work(int i)
{
	Pushdown(i);
	if (T[i].l==T[i].r) {T[i].val+=T[i].l; return;}
	Work(i<<1); Work(i<<1|1);
	T[i].val=getmin(T[i<<1].val,T[i<<1|1].val);
}

int Query(int i,int l,int r)
{
	if (T[i].l==l&&T[i].r==r) return T[i].val;
	int mid=(T[i].l+T[i].r)>>1;
	if (r<=mid) return Query(i<<1,l,r);
	if (l>mid) return Query(i<<1|1,l,r);
	return getmin(Query(i<<1,l,mid),Query(i<<1|1,mid+1,r));
}

void work(int n)
{
	memset(b,0,sizeof(b));
	for (int i=0; i<n; i++) b[s[i]-'a']=1;
	if (b[0]) sq[0]=1; else sq[0]=0;
	for (int i=1; i<26; i++) 
		if (b[i]) sq[i]=sq[i-1]+1; else sq[i]=sq[i-1];
	for (int i=0; i<n; i++) rk[i][0]=sq[s[i]-'a'];
	x=2;
	for (k=1; x<=n; k++) x<<=1;
	for (int ljj=1; ljj<=k; ljj++)
	{
		x=1<<(ljj-1);
		for (int i=0; i<n-x; i++) rk[i][1]=rk[i+x][0];
		for (int i=n-x; i<n; i++) rk[i][1]=0;
		for (int i=0; i<=n; i++) hd[i]=-1;
		for (int i=0; i<n; i++) 
		{
			nxt[i]=hd[rk[i][1]]; hd[rk[i][1]]=i;
			n1[i]=rk[i][0]; n2[i]=rk[i][1];
		}
		cnt=0;
		for (int i=0; i<=n; i++)
			for (int j=hd[i]; j!=-1; j=nxt[j]) n1[cnt]=rk[j][0],n2[cnt]=rk[j][1],rk[cnt][2]=j,cnt++;
		for (int i=0; i<n; i++) rk[i][0]=n1[i],rk[i][1]=n2[i];
		for (int i=0; i<=n; i++) hd[i]=-1;
		for (int i=0; i<n; i++)
		{
			nxt[i]=hd[rk[i][0]]; hd[rk[i][0]]=i;
		}
		cnt=n-1;
		for (int i=n; i; i--)
			for (int j=hd[i]; j!=-1; j=nxt[j]) n1[cnt]=rk[j][0],n2[cnt]=rk[j][1],n3[cnt]=rk[j][2],cnt--;
		for (int i=0; i<n; i++) rk[n3[i]][0]=i+1;
		y=0;
		for (int i=1; i<n; i++)
		{
			if (n1[i]==n1[i-1]&&n2[i]==n2[i-1]) y++;
			rk[n3[i]][0]-=y;
		}
	}
	for (int i=0; i<n; i++) ans1[rk[i][0]]=i;
	k=0; int j;
	for (int i=0; i<n; i++)
	{
		if (rk[i][0]==1) h[i]=k=0;
		else 
		{
			j=ans1[rk[i][0]-1];
			if (k>0) k--;
			while (i+k<n&&j+k<n&&s[i+k]==s[j+k]) k++;
			h[i]=k;
		}
		H[rk[i][0]]=h[i];
	}
	for (int i=1; i<n; i++) H[i]=H[i+1],f[i][0]=H[i];
	for (int j=1; j<19; j++)
		for (int i=1; i<n; i++)
			if (i+(1<<j)-1<n) 
				f[i][j]=getmin(f[i][j-1],f[i+(1<<j-1)][j-1]);
}

int main()
{
	memset(pn,0,sizeof(pn));
	for (int i=2; i<=200000; i++)
		if (!pn[i])
			for (int j=i; j<=200000; j+=i) p[j][++pn[j]]=i;
	lo[1]=0;
	for (int i=2; i<=400000; i++) lo[i]=lo[i>>1]+1;
	scanf("%d",&n); scanf("%s",&s);
	for (int i=n; i<(n<<1); i++) s[i]=s[(n<<1)-i-1];
	work(n<<1);
	Build(1,0,n-1); build(1,0,n-1);
	for (int i=1; (i<<1)<=n; i++)
		for (int j=i; i+j<=n; j+=i)
		{
			int a=i-getmin(n-j-i,getmin(i,lcp(j,j+i))),b=getmin(i,lcp((n<<1)-j,(n<<1)-j-i));
			if (a<=b) Change(1,j-b,j-a,i<<1),change(1,j-b+i+i-1,j-a+i+i-1,i<<1);
		}
	WORK(1); Work(1); work(n);
	scanf("%d",&q);
	for (int i=1; i<=n; i++)
		for (int j=0; j<26; j++)
			sum[i][j]=sum[i-1][j]+(s[i-1]==j+'a');
	while (q--)
	{
		scanf("%d%d",&l,&r),r--,l--;
		bool bo=0;
		for (int j=0; j<26; j++)
			if (sum[r+1][j]-sum[l][j]>=2) bo=1;
		if (!bo) {puts("-1"); continue;}
		bo=0;
		for (int j=1; j<=pn[r-l+1]; j++)
			if (lcp(l,l+(r-l+1)/p[r-l+1][j])>=r-(l+(r-l+1)/p[r-l+1][j])+1) {bo=1; break;}
		if (bo) {puts("1"); continue;}
		if (Query(1,l,l)<=r+1||query(1,r,r)>=l-1) {puts("2"); continue;}
		if (r-l<=N)
		{
			for (int i=l+1; i<=r; i++)
				if (lcp(l,i)>=r-i+1) {bo=1; break;}
		} else
		{
			for (int i=r-N; i<=r; i++)
				if (lcp(l,i)>=r-i+1) {bo=1; break;}
			if (!bo)
			{
				for (int i=getmax(rk[l][0]-N,1); i<=getmin(rk[l][0]+N,n); i++)
					if (ans1[i]>l&&ans1[i]<=r&&lcp(ans1[i],l)>=r-ans1[i]+1) {bo=1; break;}
			}
		}
		if (bo) {puts("2"); continue;}
		if (Query(1,l,r)<=r+1) {puts("3"); continue;}
		if (sum[r+1][s[l]-'a']-sum[l][s[l]-'a']>=2) {puts("3"); continue;}
		if (sum[r+1][s[r]-'a']-sum[l][s[r]-'a']>=2) {puts("3"); continue;}
		puts("4");
	}
	return 0;
}
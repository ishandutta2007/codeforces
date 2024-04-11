#include<cstdio>
#include<cstring>

const int L=1,R=250000;
int len[250001],n,ord,x,y,a[250001],ans[250001],cnt,tot,rt[250001],T;

struct node
{
	int ls,rs,laz,po;
}t[25000001];

void pushdown(int i,int l,int r)
{
	if (l==r||!i) return;
	int i1=(!t[i].ls?t[i].ls=(++tot):t[i].ls),i2=(!t[i].rs?t[i].rs=(++tot):t[i].rs);
	if (!t[i].laz) return;
	if (t[i].laz==1) t[i1].po=t[i2].po=0;
	else t[i1].po=(l+r)>>1,t[i2].po=r;
	t[i1].laz=t[i2].laz=t[i].laz;
	t[i].laz=0;
}

void change(int i,int I,int l,int r,int ql,int qr,int bo)
{
	pushdown(I,l,r);
	if (ql==l&&qr==r) {t[i].laz=bo+1; if (bo) t[i].po=r; else t[i].po=0; return;}
	int mid=(l+r)>>1;
	if (qr<=mid) 
	{
		t[i].rs=t[I].rs;
		change(t[i].ls=(++tot),t[I].ls,l,mid,ql,qr,bo);
	} else
	if (ql>mid)
	{
		t[i].ls=t[I].ls;
		change(t[i].rs=(++tot),t[I].rs,mid+1,r,ql,qr,bo);
	} else
	{
		change(t[i].ls=(++tot),t[I].ls,l,mid,ql,mid,bo);
		change(t[i].rs=(++tot),t[I].rs,mid+1,r,mid+1,qr,bo);
	}
	if (t[t[i].rs].po) t[i].po=t[t[i].rs].po;
	else t[i].po=t[t[i].ls].po;
}

int find(int i,int l,int r,int x)
{
	if (!t[i].po) return 0;
	if (l==r) return l;
	int mid=(l+r)>>1;
	if (x<=mid)
	{
		if (!t[i].ls) {if (t[i].laz==2) return x; return 0;}
		return find(t[i].ls,l,mid,x);
	}
	if (!t[i].rs) 
	{
		if (t[i].laz==2) return x;
		if (!t[i].ls) return 0;
		return t[t[i].ls].po;
	}
	int ans=find(t[i].rs,mid+1,r,x);
	if (ans) return ans;
	if (!t[i].ls) 
	{
		if (t[i].laz==2) return mid;
		return 0;
	}
	return t[t[i].ls].po;
}

void atk(int x,int y)
{
	if (a[x]>=len[y]) ans[y]=T; else
	{
		int po=find(rt[y],L,R,len[y]-a[x]);
		if (!po) ans[y]=T; else
		{
			if (po==len[y]-a[x]) 
			{
				tot++; int To=tot;
				change(tot,rt[y],L,R,po,po,0);
				rt[y]=To;
				if (!find(rt[y],L,R,R)) ans[y]=T;
			} else
			{
				tot++; int To=tot;
				change(tot,rt[y],L,R,po,po,0);
				rt[y]=To;
				tot++; To=tot;
				change(tot,rt[y],L,R,po+1,len[y]-a[x],1);
				rt[y]=To;
			}
		}
	}
}

int main()
{
	t[0].ls=t[0].rs=0;
	scanf("%d",&n); cnt=tot=0;
	for (T=1; T<=n; T++)
	{
		scanf("%d",&ord);
		if (ord==1) 
		{
			len[++cnt]=1; rt[cnt]=(++tot);
			a[cnt]=0; ans[cnt]=-1; change(rt[cnt],0,L,R,1,1,1);
		} else
		if (ord==2)
		{
			scanf("%d",&x); a[x]++;
		} else
		if (ord==3)
		{
			scanf("%d",&x); len[x]++;
		} else
		if (ord==4)
		{
			scanf("%d",&x); 
			if (ans[x]==-1)
			{
				ans[++cnt]=-1;
				rt[cnt]=rt[x];
				len[cnt]=len[x];
				a[cnt]=a[x];
			} else ans[++cnt]=T;
		} else
		{
			scanf("%d%d",&x,&y);
			if (ans[x]!=-1||ans[y]!=-1) continue;
			atk(x,y); atk(y,x);
		}
	}
	printf("%d\n",cnt);
	for (int i=1; i<=cnt; i++) printf("%d ",ans[i]); if (cnt) puts("");
	return 0;
}
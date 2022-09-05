#include<bits/stdc++.h>
using namespace std;

bool bo[100010];
int n,a[100010],m,b[100010],ma[510],bel[200010],cnt,na,la[100010],po[200010],pma[510],f[200010],prm[200010],prp[200010],nw,q[100010],qn,l,r,mid,ans,val[200010];
pair<int,int> vala[200010];

void ins(int vf,int v,int p)
{
	if (vf>f[v])
	{
		f[v]=vf,po[v]=p;
		if (vf>ma[bel[v]]) ma[bel[v]]=vf,pma[bel[v]]=p;
	}
}

int main()
{
	scanf("%d",&n),na=0;
	for (int i=1; i<=n; i++) 
	{
		scanf("%d",&a[i]);
		if (a[i]!=-1) vala[++na]=make_pair(a[i],i);
	}
	scanf("%d",&m);
	for (int i=1; i<=m; i++) scanf("%d",&b[i]),vala[++na]=make_pair(b[i],-i);
	sort(vala+1,vala+na+1),cnt=0;
	for (int i=1; i<=na; i++)
	{
		if (i==1||vala[i].first!=vala[i-1].first) val[++cnt]=vala[i].first;
		if (vala[i].second>0) a[vala[i].second]=cnt;
		else b[-vala[i].second]=cnt;
	}
	sort(b+1,b+1+m),bel[0]=-1;
	for (int i=1; i<=cnt; i++) po[i]=f[i]=-1;
	for (int i=1; i<=cnt; i++) bel[i]=(i-1)/400+1;
	for (int i=1; i<=bel[cnt]; i++) pma[i]=ma[i]=-1;
	for (int i=1; i<=n; i++)
	{
		if (a[i]==-1)
		{
			prp[0]=prm[0]=0;
			for (int j=1; j<=cnt; j++)
				if (f[j]>prm[j-1]) prm[j]=f[j],prp[j]=po[j];
				else prm[j]=prm[j-1],prp[j]=prp[j-1];
			for (int j=1; j<=m; j++) ins(prm[b[j]-1]+1,b[j],prp[b[j]-1]);
		} else
		{
			int Ma=0,maa=0;
			if (a[i]>1)
			{
				for (int j=1; j<bel[a[i]-1]; j++) 
					if (Ma<ma[j]) Ma=ma[j],maa=pma[j];
				for (int j=a[i]-1; bel[j]==bel[a[i]-1]; j--)
					if (Ma<f[j]) Ma=f[j],maa=po[j];
			}
			la[i]=maa,ins(Ma+1,a[i],i);
		}
	}
	int Ma=0,maa=0;
	for (int i=1; i<=cnt; i++)
		if (f[i]>Ma) Ma=f[i],maa=po[i];
	memset(bo,0,sizeof(bo)),qn=0;
	while (maa) q[++qn]=maa,maa=la[maa];
	for (int i=1; i<qn-i+1; i++) swap(q[i],q[qn-i+1]);
	q[0]=0,q[qn+1]=n+1,a[0]=0,a[n+1]=cnt+1;
	memset(bo,1,sizeof(bo));
	for (int nw,i=0; i<=qn; i++)
	{
		nw=a[q[i]];
		for (int j=q[i]+1; j<q[i+1]; j++)
			if (a[j]==-1) 
			{
				l=1,r=m,ans=0;
				while (l<=r)
				{
					mid=(l+r)>>1;
					if (b[mid]>nw) ans=mid,r=mid-1; else l=mid+1;
				}
				if (ans&&b[ans]<a[q[i+1]]) nw=a[j]=b[ans],bo[ans]=0;
			}
	}
	int p=1;
	for (int i=1; i<=n; i++) if (a[i]==-1)
	{
		while (!bo[p]) p++;
		bo[p]=0,a[i]=b[p];
	}
	for (int i=1; i<=n; i++) printf("%d ",val[a[i]]);
	return puts(""),0;
}
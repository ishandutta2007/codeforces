#include<bits/stdc++.h>
using namespace std;

bool bo[200010];
int la[200010],a[200010],b[200010],pa[200010],pb[200010],x,y,hd[200010],cnt,n,t[2][200010],tn[2],sa,sb,c[200010],cn,d[200010],q[200010],l,r,C[200010],Cn;
struct node{int to,next;}e[400010];
long long ans;

void addedge(int x,int y)
{
	e[++cnt]=(node){y,hd[x]},hd[x]=cnt;
	e[++cnt]=(node){x,hd[y]},hd[y]=cnt;
}

bool getpath(int x,int fa,int y,int o)
{
	if (x==y) return t[o][++tn[o]]=x,1;
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=fa&&getpath(e[i].to,x,y,o)) return t[o][++tn[o]]=x,1;
	return 0;
}

void bfs(int x)
{
	memset(la,-1,sizeof(la));
	q[l=r=1]=x,la[x]=0;
	while (l<=r)
	{
		x=q[l++];
		for (int i=hd[x]; i; i=e[i].next)
			if (bo[e[i].to]&&la[e[i].to]==-1) la[q[++r]=e[i].to]=x;
	}
}

int main()
{
	scanf("%d",&n),cnt=0,memset(hd,0,sizeof(hd)),ans=0;
	for (int i=1; i<=n; i++) scanf("%d",&a[i]),pa[a[i]]=i;
	for (int i=1; i<=n; i++) scanf("%d",&b[i]),pb[b[i]]=i;
	for (int i=1; i<n; i++) scanf("%d%d",&x,&y),addedge(x,y);
	sa=pa[0],sb=pb[0];
	while (1)
	{
		bool bo=0;
		for (int i=hd[pa[0]]; i; i=e[i].next)
			if (a[e[i].to]==b[pa[0]]) {bo=1,swap(a[pa[0]],a[e[i].to]),swap(pa[0],pa[a[pa[0]]]),ans++; break;}
		if (!bo) break;
	}
	while (1)
	{
		bool bo=0;
		for (int i=hd[pb[0]]; i; i=e[i].next)
			if (b[e[i].to]==a[pb[0]]) {bo=1,swap(b[pb[0]],b[e[i].to]),swap(pb[0],pb[b[pb[0]]]),ans++; break;}
		if (!bo) break;
	}
	if (pa[0]==pb[0])
	{
		bool boo=1;
		for (int i=1; i<=n; i++) if (a[i]!=b[i]) {boo=0; break;}
		if (boo) return printf("0 %lld\n",ans),0;
		for (int i=1; i<=n; i++) if (a[i]!=b[i])
			for (int j=hd[i]; j; j=e[j].next) if (a[e[j].to]!=b[e[j].to]) d[i]++;
		int cnt=0,Cnt=0;
		for (int i=1; i<=n; i++) if (a[i]!=b[i])
		{
			if (d[i]==1) cnt++; else
			if (d[i]==0) Cnt++; else
			if (d[i]!=2) return puts("-1"),0;
		}
		if (cnt/2+Cnt>2) return puts("-1"),0;
		int p=0;
		if (cnt/2+Cnt==1)
		{
			for (int i=1; i<=n; i++) if (a[i]!=b[i]) {p=i; break;}
			memset(bo,0,sizeof(bo));
			for (int i=1; i<=n; i++) if (a[i]!=b[i]) bo[i]=1;
			bfs(p),bfs(q[r]);
			tn[0]=tn[1]=0,getpath(q[r],0,sa,0),getpath(q[r],0,sb,1);
			if (t[0][tn[0]-1]==t[1][tn[1]-1]&&!bo[t[0][tn[0]-1]]) p=t[0][tn[0]-1],tn[0]--,tn[1]--; else
			{
				tn[0]=tn[1]=0,getpath(q[1],0,sa,0),getpath(q[1],0,sb,1);
				if (t[0][tn[0]-1]==t[1][tn[1]-1]&&!bo[t[0][tn[0]-1]]) p=t[0][tn[0]-1],tn[0]--,tn[1]--;
				else return puts("-1"),0;
			}
		} else
		{
			for (int i=1; i<=n; i++) if (a[i]==b[i])
			{
				cnt=0;
				for (int j=hd[i]; j; j=e[j].next) if (a[e[j].to]!=b[e[j].to]) cnt++;
				if (cnt==2) {p=i; break;}
			}
			if (!p) return puts("-1"),0;
			tn[0]=tn[1]=0,getpath(sa,0,p,0),getpath(sb,0,p,1);
			if (tn[0]>1&&a[t[0][2]]!=b[t[0][2]]) return puts("-1"),0;
			if (tn[1]>1&&a[t[1][2]]!=b[t[1][2]]) return puts("-1"),0;
		}
		ans=tn[0]+tn[1]-2;
		memset(bo,0,sizeof(bo)),bo[p]=1;
		for (int i=1; i<=n; i++) if (a[i]!=b[i]) bo[i]=1;
		bfs(p),bfs(q[r]),cn=0,sa=q[1],sb=q[r];
		for (int i=1; i<=r; i++) if (q[i]!=p) c[++cn]=q[i];
		int del=0;
		for (int i=2; i<=cn; i++) if (a[c[i]]==b[c[1]]) {del=i-1; break;}
		for (int i=2; i<=cn; i++) if (a[c[(i+del-1)%cn+1]]!=b[c[i]]) return puts("-1"),0;
		del=min(del,cn-del);
		if (sa>sb) swap(sa,sb);
		printf("%d %d %lld\n",sa,sb,ans+1ll*del*(cn+1));
	} else
	{
		if (b[pa[0]]==a[pb[0]]) 
		{
			bool boo=1;
			for (int i=1; i<=n; i++) if (i!=pa[0]&&i!=pb[0]&&a[i]!=b[i]) {boo=0; break;}
			if (boo)
			{
				if (pa[0]>pb[0]) swap(pa[0],pb[0]);
				return printf("%d %d %lld\n",pa[0],pb[0],ans+1),0;
			}
		}
		memset(bo,0,sizeof(bo));
		for (int i=1; i<=n; i++) if (a[i]!=b[i]) bo[i]=1;
		int cnt1=0,cnt2=0;
		for (int i=1; i<=n; i++) if (a[i]!=b[i])
		{
			for (int j=hd[i]; j; j=e[j].next) if (a[e[j].to]!=b[e[j].to]) d[i]++;
			if (d[i]==1) cnt1++; else if (d[i]==2) cnt2++; else return puts("-1"),0;
		}
		if (cnt1!=2) return puts("-1"),0;
		bfs(pa[0]),bfs(q[r]),tn[0]=0,getpath(pb[0],0,pa[0],0);
		int A=0,B=0;
		for (int i=1; i<=r; i++) if (q[i]==pa[0]) A=i;
		for (int i=1; i<=r; i++) if (q[i]==pb[0]) B=i;
		cn=Cn=0;
		for (int i=1; i<=r; i++) if (q[i]!=pa[0]) c[++cn]=a[q[i]];
		for (int i=1; i<=r; i++) if (q[i]!=pb[0]) C[++Cn]=b[q[i]];
		int del=0;
		for (int i=2; i<=cn; i++) if (c[i]==C[1]) {del=i-1; break;}
		for (int i=2; i<=cn; i++) if (c[(i+del-1)%cn+1]!=C[i]) return puts("-1"),0;
		if (q[1]>q[r]) swap(q[1],q[r]);
		if (A<B) printf("%d %d %lld\n",q[1],q[r],ans+min(1ll*del*(cn+1)+tn[0]-1,1ll*(cn-1-del)*(cn+1)+r-tn[0]+1));
		else printf("%d %d %lld\n",q[1],q[r],ans+min(1ll*(del-1)*(cn+1)+r-tn[0]+1,1ll*(cn-del)*(cn+1)+tn[0]-1));
	}
	return 0;
}
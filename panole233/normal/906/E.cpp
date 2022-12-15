#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<algorithm>

using namespace std;

struct node
{
	int d,s,len;
}a[2][1000001];

struct node2
{
	int d,val,la;
	node2(int dd=0,int vall=0,int laa=0) {d=dd; val=vall; la=laa;}
	bool operator <(node2 a) {return d<a.d;}
};

vector<node2> f[1000001];
int num[2],n,x,y,len,e,l,r,xx,mid,gg,pp,e1,e2,an,g[1000001],po[1000001];
char s[1000001],s1[500001],s2[500001];
bool bo,bb[1000001];

int find(int x,int val)
{
	l=0; r=f[x].size()-2; an=r+1;
	while (l<=r)
	{
		mid=(l+r)>>1;
		if (f[x][mid].d>=val) an=mid,r=mid-1;
		else l=mid+1;
	}
	if (f[x][an].d==val) return an; else return f[x].size()-1;
}
 
void ins(int i,int x,int y,int z)
{
	if (y<g[i]) g[i]=y,po[i]=x;
	f[i].push_back(node2(x,y,z));
}
 
int main()
{
	//freopen("E0.in","r",stdin);
	gets(s1); gets(s2); n=strlen(s1);
	while (s1[n-1]>'z'||s1[n-1]<'a') n--;
	num[0]=num[1]=0; len=(n<<1);
	s[0]='#';
	for (int i=0; i<n; i++) s[1+(i<<1)]=s1[i],s[(i<<1)+2]=s2[i];
	for (int i=0; i<=1000000; i++) f[i].clear(),g[i]=1e9,f[i].push_back(node2(1e9,1e9,0)); 
	g[0]=0;
	for (int i=1; i<=len; i++)
	{
		y=(i&1); x=(y^1); num[y]=0; bo=0;
		for (int j=1; j<=num[x]; j++)
			if (a[x][j].d>1)
			{
				if (a[x][j].s==i-1) 
				{
					if (s[i-1]==s[i]) bo=1,a[y][++num[y]].s=i,a[y][num[y]].d=1,a[y][num[y]].len=1;
					int po=i-1;
					while (s[po]==s[i]) a[y][num[y]].len++,po--;
				}
				if (a[x][j].len>1&&s[a[x][j].s-1]==s[i])
				{
					a[y][++num[y]]=a[x][j]; a[y][num[y]].s--; a[y][num[y]].len--;
					while (i-a[y][num[y]].s+1>a[y][num[y]].d) a[y][num[y]].s+=a[y][num[y]].d,a[y][num[y]].len++;
					if (a[y][num[y]].s==i) bo=1;
					e=a[y][num[y]].s-a[y][num[y]].d*a[y][num[y]].len;
					if (e>=1&&s[e]==s[i]) a[y][num[y]].len++;
				} else
				{
					e=a[x][j].s-a[x][j].d*(a[x][j].len-1);
					if (e>=1&&s[e-1]==s[i]) 
					{
						a[y][++num[y]].s=e-1; a[y][num[y]].d=i-e+2;
						a[y][num[y]].len=1; 
					}
				}
			} else
			{
				if (s[i]==s[i-1])
				{
					a[y][++num[y]].s=i; a[y][num[y]].d=1;
					a[y][num[y]].len=a[x][j].len+1; bo=1; 
				} else
				{
					e=a[x][j].s-a[x][j].len;
					if (e>=1&&s[e]==s[i]) 
					{
						a[y][++num[y]].s=e; a[y][num[y]].d=a[x][j].len+2;
						a[y][num[y]].len=1;
					}
				}
			} 
		if (!bo) a[y][++num[y]].s=i,a[y][num[y]].len=1,a[y][num[y]].d=1;
		for (int j=1; j<=num[y]; j++) bb[j]=1;
		bo=0;
		while (1)
		{
			for (int j=1; j<num[y]; j++)
				for (int k=j+1; k<=num[y]; k++)
					if (bb[j]&&bb[k])
					{
						if ((a[y][k].s-a[y][j].s)%a[y][j].d==0&&a[y][k].d%a[y][j].d==0)
						{
							e2=a[y][k].s-(a[y][k].len-1)*a[y][k].d;
							e1=a[y][j].s-(a[y][j].len-1)*a[y][j].d;
							if (e2<e1-a[y][j].d) continue;
							if (a[y][k].s>a[y][j].s+a[y][j].d) continue; 
							if (e2<e1) a[y][j].len++;
							if (a[y][k].s>a[y][j].s) a[y][j].len++,a[y][j].s+=a[y][j].d;
							bb[k]=0; bo=1;
						} else
						if ((a[y][k].s-a[y][j].s)%a[y][k].d==0&&a[y][j].d%a[y][k].d==0)
						{
							e2=a[y][k].s-(a[y][k].len-1)*a[y][k].d;
							e1=a[y][j].s-(a[y][j].len-1)*a[y][j].d;
							if (e1<e2-a[y][k].d) continue;
							if (a[y][j].s>a[y][k].s+a[y][k].d) continue;
							if (e1<e2) a[y][k].len++;
							if (a[y][k].s<a[y][j].s) a[y][k].len++,a[y][k].s+=a[y][k].d;
							bb[j]=0; bo=1;
						} else
						if ((!(a[y][j].d&1))&&(a[y][k].s-a[y][j].s)%(a[y][j].d/2)==0&&a[y][j].d==a[y][k].d)
						{
							e2=a[y][k].s-(a[y][k].len-1)*a[y][k].d;
							e1=a[y][j].s-(a[y][j].len-1)*a[y][j].d;
							if (e1<e2-a[y][j].d/2||e2<e1-a[y][j].d/2) continue;
							if (a[y][j].s>a[y][k].s+a[y][j].d/2||a[y][k].s>a[y][j].s+a[y][j].d/2) continue;
							a[y][j].d/=2; a[y][j].len*=2; a[y][j].len--;
							if (e2<e1) a[y][j].len++;
							if (a[y][k].s>a[y][j].s) a[y][j].s+=a[y][j].d,a[y][j].len++;
							bb[k]=0; bo=1;
						}
					}
			if (!bo) break;
			bo=0;
		}
		int nn=num[y]; num[y]=0;
		for (int j=1; j<=nn; j++)
			if (bb[j]) a[y][++num[y]]=a[y][j];
		for (int j=1; j<=num[y]; j++)
		{
		//	printf("%d %d %d\n",a[y][j].s,a[y][j].d,a[y][j].len);
			if (a[y][j].d==1) 
			{
				if (a[y][j].len>1) 
				{
					gg=g[i-2]; pp=i-1; e=a[y][j].s-a[y][j].d*(a[y][j].len-1);
					if (!((i-e)&1)) e+=a[y][j].d;
					if (e<a[y][j].s&&g[e-1]<gg) gg=g[e-1],pp=e;
					xx=find(i-2,1);
					if (a[y][j].len<=3||gg<f[i-2][xx].val) ins(i,a[y][j].d,gg,pp);
					else ins(i,a[y][j].d,f[i-2][xx].val,f[i-2][xx].la);
				} 
			} else
			if (a[y][j].d&1)
			{
				if ((i-a[y][j].s)&1) 
				{
					gg=g[a[y][j].s-1]; pp=a[y][j].s; 
					e=a[y][j].s-a[y][j].d*(a[y][j].len-1);
					if (!((i-e)&1)) e+=a[y][j].d;
					if (e<a[y][j].s&&g[e-1]<gg) gg=g[e-1],pp=e;	
					if (i>a[y][j].d*2)
					{			
						xx=find(i-a[y][j].d*2,a[y][j].d);
						if (a[y][j].len<=3||gg+1<f[i-2*a[y][j].d][xx].val)
							ins(i,a[y][j].d,gg+1,pp);
						else
							ins(i,a[y][j].d,f[i-2*a[y][j].d][xx].val,f[i-2*a[y][j].d][xx].la);
					}
					else ins(i,a[y][j].d,gg+1,pp);
				}
				else if (a[y][j].len>1) 
				{
					gg=g[a[y][j].s-a[y][j].d-1]; pp=a[y][j].s-a[y][j].d;
					e=a[y][j].s-a[y][j].d*(a[y][j].len-1);
					if (!((i-e)&1)) e+=a[y][j].d;
					if (e<a[y][j].s&&g[e-1]<gg) gg=g[e-1],pp=e;
					if (i>a[y][j].d*2)
					{
						xx=find(i-a[y][j].d*2,a[y][j].d);
						if (a[y][j].len<=3||gg+1<f[i-a[y][j].d*2][xx].val)
							ins(i,a[y][j].d,gg+1,pp);
						else
							ins(i,a[y][j].d,f[i-a[y][j].d*2][xx].val,f[i-a[y][j].d*2][xx].la);
					}
					else ins(i,a[y][j].d,gg+1,pp);
				}
			}
			else if ((i-a[y][j].s)&1) 
			{
				gg=g[a[y][j].s-1]; pp=a[y][j].s;
				e=a[y][j].s-a[y][j].d*(a[y][j].len-1);
				if (e<a[y][j].s&&g[e-1]<gg) gg=g[e-1],pp=e;
				xx=find(i-a[y][j].d,a[y][j].d);
				if (a[y][j].len<=2||gg+1<f[i-a[y][j].d][xx].val)
					ins(i,a[y][j].d,gg+1,pp);
				else
					ins(i,a[y][j].d,f[i-a[y][j].d][xx].val,f[i-a[y][j].d][xx].la);
			}
		}
		//printf("\n");
		sort(f[i].begin(),f[i].end());
		po[i]=find(i,po[i]);
	}
	if (g[len]==1e9) {printf("-1\n"); return 0;} 
	printf("%d\n",g[len]);
	int i=len;
	while (i!=0)
	{
		if (g[i]!=g[f[i][po[i]].la-1]) printf("%d %d\n",(f[i][po[i]].la-1)/2+1,(i-1)/2+1);
		i=f[i][po[i]].la-1;
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

long long ans,res;
int n,m,cnt,k,valy[3050],suf[3050],pre[3050],f[3050];
struct P{int x,y;}p[3050];

bool cmpy(P a,P b) {return a.y<b.y;}
bool cmpx(P a,P b) {return a.x<b.x;}

void ins(int x) {suf[pre[x]]=x,pre[suf[x]]=x;}
void del(int x) {suf[pre[x]]=suf[x],pre[suf[x]]=pre[x];}

int main()
{
	scanf("%d%d%d%d",&n,&m,&cnt,&k),res=0;
	for (int i=1; i<=cnt; i++) scanf("%d%d",&p[i].x,&p[i].y);
	sort(p+1,p+1+cnt,cmpy),valy[0]=0;
	for (int i=1; i<=cnt; i++) valy[i]=p[i].y,p[i].y=i;
	for (int i=cnt+1; i<=cnt+k; i++) valy[i]=m+1;
	sort(p+1,p+1+cnt,cmpx);
	for (int i=1,l=1,nw,x; i<=n; i++)
	{
		while (l<=cnt&&p[l].x<i) l++;
		if (l>cnt) break;
		for (int j=0; j<=cnt+k; j++) pre[j]=j-1,suf[j]=j+1;
		for (int j=1; j<l; j++) del(p[j].y);
		for (int j=cnt; j>=l; j--) del(p[j].y);
		nw=l,ans=0,f[cnt+1]=cnt+k;
		for (int j=i; j<=n; j++)
		{
			while (nw<=cnt&&p[nw].x<=j) 
			{
				ins(x=p[nw].y),f[x]=x;
				for (int o=1; o<k; o++) f[x]=suf[f[x]];
				ans+=1ll*(valy[x]-valy[pre[x]])*(valy[f[suf[x]]]-valy[f[x]]);
				for (int o=1; o<k; o++)
				{
					x=pre[x];
					if (!x) break;
					ans+=1ll*(valy[x]-valy[pre[x]])*(valy[f[x]]-valy[pre[f[x]]]);
					f[x]=pre[f[x]];
				}
				nw++;
			}
			res+=ans;
		}
	}
	printf("%I64d\n",res);
	return 0;
}
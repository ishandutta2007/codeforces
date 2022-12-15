#include<cstdio>
#include<cstring>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

int read()
{
	int p=0; char c=getchar();
	while (c>'9'||c<'0') c=getchar();
	while (c>='0'&&c<='9') p=p*10+c-48,c=getchar();
	return p;
}

const int inf=1000000000;
int n,k,f[200001][18],lo[200001],l[200001],r[200001],a[200001],siz;
bool bo;
vector<int> p1[200001],p2[200001];
set<int> s;
set<int>::iterator it;

int getmin(int a,int b) {return a<b?a:b;}
int ask(int l,int r)
{
	int len=lo[r-l+1];
	return getmin(f[l][len],f[r-(1<<len)+1][len]);
}

int main()
{
	lo[1]=0;
	for (int i=2; i<=200000; i++) lo[i]=lo[i>>1]+1;
	n=read(); k=read(); bo=0;
	memset(l,0,sizeof(l));
	for (int i=1; i<=n; i++) 
	{
		f[i][0]=read();
		if (f[i][0]) 
		{
			if (!l[f[i][0]]) l[f[i][0]]=i;
			r[f[i][0]]=i;
		}
		else f[i][0]=inf,bo=1;
		a[i]=f[i][0];
	}
	if ((!bo)&&(!l[k])) {printf("NO\n"); return 0;}
	for (int j=1; j<=17; j++)
		for (int i=1; i<=n; i++)
			if (i+(1<<j)-1<=n)
				f[i][j]=getmin(f[i][j-1],f[i+(1<<j-1)][j-1]);
	for (int i=1; i<=k; i++)
		if (l[i])
			if (ask(l[i],r[i])!=i) {printf("NO\n"); return 0;}
	if (l[k]) bo=0;
	printf("YES\n");
	if (bo)
	{
		for (int i=1; i<=n; i++)
			if (a[i]==inf) {a[i]=k; break;}
	}
	for (int i=1; i<=n; i++) p1[i].clear(),p2[i].clear();
	s.clear(); s.insert(1);
	for (int i=2; i<=k; i++)
		if (l[i]) p1[l[i]].push_back(i),p2[r[i]].push_back(i);
	for (int i=1; i<=n; i++)
	{
		siz=p1[i].size();
		for (int j=0; j<siz; j++) s.insert(p1[i][j]);
		if (a[i]==inf) it=s.end(),it--,a[i]=(*it);
		siz=p2[i].size();
		for (int j=0; j<siz; j++) s.erase(p2[i][j]);
	}
	for (int i=1; i<=n; i++) printf("%d ",a[i]);
	printf("\n");
	return 0;
}
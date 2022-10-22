#include<bits/stdc++.h>
using namespace std;
int T,n; 
int a[200005],b[200005];
int col[200005],coler;
int ca[200005],cb[200005],cnta,cntb,num[200005];
int fa[200005];
void print()
{
	for (int i=1;i<=n;i++) cout << col[i] << " ";
	cout << endl;
}
int find(int x)
{
	if (fa[x]==-1) return -1;
	if (fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int main()
{
	cin >> T;
	while (T--)
	{
		cin >> n;
		cnta=0,cntb=0;
		for (int i=1;i<=n;i++) num[i]=0;
		for (int i=1;i<=n;i++) 
		{
			char x;
			cin >> x;
			if (x=='1') a[i]=1;
			else a[i]=0;
			if (a[i]==1) ca[++cnta]=i,num[i]=cnta;
			else cb[++cntb]=i,num[i]=cntb;
		}
		for (int i=1;i<=n;i++) b[i]=-1;
		for (int i=1;i<=n;i++) fa[i]=i;
		int last0=-1,last1=-1;
		for (int i=n;i>=1;i--)
		{
			if (a[i]==0)
			{
				if (last1!=-1) b[i]=last1;
				last0=i;
			}
			else
			{
				if (last0!=-1) b[i]=last0;
				last1=i;
			}
		}
		for (int i=1;i<=n;i++) col[i]=0;
		coler=0;
		int zhizhen0=0,zhizhen1=0;
		for (int i=1;i<=n;i++)
		{
			if (col[i]!=0) continue;
			coler++;
			int u=i;
			while (1)
			{
				//print();
				col[u]=coler;
				if (a[u]==1)
				{
					if (num[u]!=cnta) fa[u]=ca[num[u]+1];
					else fa[u]=-1;
				}
				else
				{
					if (num[u]!=cntb) fa[u]=cb[num[u]+1];
					else fa[u]=-1;
				}
				u=b[u];
				if (u==-1) break;
				if (col[u]!=0) u=find(u);
				if (u==-1) break;
			}
		} 
		cout << coler << endl;
		for (int i=1;i<=n;i++) cout << col[i] << " ";
		cout << endl;
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n,res;
int h[100001],t[200001],nxt[200001],cnt,fa[100001],sizeee[100001],f[100001];
int X[100001],Y[100001];
void add(int x,int y)
{
	t[++cnt]=y;
	nxt[cnt]=h[x];
	h[x]=cnt;
}
int dfs(int x,int s,int fath)
{
	fa[x]=fath;
	res+=s;
	sizeee[x]=1;
	for (int i=h[x];i;i=nxt[i])
	{
		if (t[i]!=fa[x])
		{
			sizeee[x]+=dfs(t[i],s+1,x);
		}
	}
	return sizeee[x];
}
void dfs2(int x)
{
	if (x!=1) f[x]=f[fa[x]]+sizeee[1]-2*sizeee[x];
	for (int i=h[x];i;i=nxt[i])
	{
		if (t[i]!=fa[x])
		{
			dfs2(t[i]);
		}
	}
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		cin >> n;
		cnt=0,res=0;
		for (int i=1;i<=n;i++) h[i]=0;
		for (int i=0;i<=2*n;i++) t[i]=0;
		for (int i=0;i<=2*n;i++) nxt[i]=0;
		for (int i=1;i<=n;i++) f[i]=0;
		for (int i=1;i<n;i++)
		{
			int x,y;
			cin >> x >> y;
			add(y,x),add(x,y);
			X[i]=x,Y[i]=y;
		}
		dfs(1,0,0);
		f[1]=res;
		dfs2(1);
		int ans1=1,ans2=-1;
		for (int i=2;i<=n;i++)
		{
			if (f[i]<f[ans1]) 
			{
				ans1=i,ans2=-1;
			}
			else if (f[i]==f[ans1]) ans2=i;
		}
		if (ans2==-1)
		{
			cout << X[1] << " " << Y[1] << endl << X[1] << " " << Y[1] << endl;
		}
		else
		{
			bool flag=0;
			for (int i=h[ans1];i;i=nxt[i]) 
			{
				if (t[i]!=ans2) 
				{
					cout << ans1 << " " << t[i] << endl;
					cout << ans2 << " " << t[i] << endl;
					flag=1;
					break;
				}
			}
			if (flag==0)
			{
				for (int i=h[ans2];i;i=nxt[i]) 
				{
					if (t[i]!=ans1) 
					{
						cout << ans2 << " " << t[i] << endl;
						cout << ans1 << " " << t[i] << endl;
						break;
					}
				}	
			}
		}
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int t; 
int n,m;
int a[200001],b[200001],c[200001];
int B[200001],ans[200001],w[200001];
vector<int>q[200001];
inline int read()
{
	char C=getchar();
	int F=1,ANS=0;
	while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
	while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
	return F*ANS;
} 
int main()
{
	t=read();
	while (t--)
	{
		n=read(),m=read();
		for (int i=1;i<=n;i++) a[i]=read();
		for (int i=1;i<=n;i++) w[i]=0;
		for (int i=1;i<=n;i++) q[i].clear();
		for (int i=1;i<=n;i++) B[i]=0;
		for (int i=1;i<=n;i++) 
		{
			b[i]=read();
			B[b[i]]=i;
		}
		for (int i=1;i<=m;i++) c[i]=read();
		for (int i=1;i<=n;i++)
		{
			if (a[i]!=b[i]) q[b[i]].push_back(i);
		}
		int tot=1;
		for (int i=m;i>=1;i--)
		{
			if (i==m)
			{
				if (B[c[i]]==0) 
				{
					cout << "NO" << endl;
					goto pp;
				}
				else if (w[c[i]]<q[c[i]].size())
				{
					ans[i]=q[c[i]][w[c[i]]];
					w[c[i]]++;
					tot=ans[i];
				}
				else 
				{
					ans[i]=B[c[i]];
					tot=ans[i];
				}
			}
			else
			{
				if (B[c[i]]==0) 
				{
					ans[i]=tot;
				}
				else if (w[c[i]]<q[c[i]].size())
				{
					ans[i]=q[c[i]][w[c[i]]];
					w[c[i]]++;
				}
				else 
				{
					ans[i]=tot;
				}
			}
		}
		for (int i=1;i<=n;i++) 
		{
			if (w[i]!=q[i].size())
			{
				cout << "NO" << endl;
				goto pp;
			}
		}
		cout << "YES" << endl;
		for (int i=1;i<=m;i++) cout << ans[i] << " ";
		cout << endl;
		pp:;
	}
	return 0;
}
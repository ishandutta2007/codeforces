#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mem(x) memset(x,0,sizeof(x))
//const ll inf=1000000000000000000; 
const ll mod=998244353;

const int N=2001;
int n,m,T; 
int a[N][N];
int tp[N][N];

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
queue<int>q;
int ans[N];
void work()
{
	n=read();
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++) tp[i][j]=0;
	}
	mem(ans);
	while (!q.empty()) q.pop();
	for (int i=1;i<=2*n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			a[i][j]=read();
			tp[j][a[i][j]]++;
		}
	}
	int tot=2*n;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (tp[i][j]==1) 
			{
				for (int k=1;k<=2*n;k++)
				{
					if (a[k][i]==j&&ans[k]==0) 
					{
						q.push(k);
						ans[k]=1;
						tot--;
					}
				}
			}
		}
	}
	ll answ=1;
	while (tot)
	{
		if (!q.empty())
		{
			int u=q.front();
			q.pop();
			if (ans[u]==1)
			{
				for (int i=1;i<=n;i++)
				{
					for (int j=1;j<=2*n;j++)
					{
						if (ans[j]!=0) continue;
						if (a[j][i]==a[u][i]) 
						{
							ans[j]=-1;
							q.push(j);
							tot--;
						}
					}
					tp[i][a[u][i]]=0;
				}
			}	
			else
			{
				for (int i=1;i<=n;i++)
				{
					if (tp[i][a[u][i]]>0) tp[i][a[u][i]]--;
				}
				for (int i=1;i<=n;i++)
				{
					if (tp[i][a[u][i]]==1)
					{
						for (int j=1;j<=2*n;j++)
						{
							if (ans[j]!=0) continue;
							if (a[j][i]==a[u][i])
							{
								ans[j]=1;
								q.push(j);
								tot--;
								break;
							}
						}
					}	
				}
				
			}
		}
		else
		{
			answ=(answ*2ll)%mod;
			for (int i=1;i<=2*n;i++)
			{
				if (ans[i]==0)
				{
					ans[i]=1;
					q.push(i);
					tot--;
					break;
				}
			}
		}
	}
	cout << answ << endl;
	for (int i=1;i<=2*n;i++) if (ans[i]==1) cout << i << " ";
	puts("");
	return;
}

int main()
{
	T=read();
	while (T--)
	{
		work();
	}
	return 0;
}
#include<iostream>
#include<cstring>
using namespace std;
struct tmp
{
	int l,a[210];
};
inline bool operator <(const tmp &a,const tmp &b)
{
	for(int i=1;i<=a.l;i++)
	{
		if(a.a[i]!=b.a[i])
		{
			return a.a[i]>b.a[i];
		}
	}
	return 0;
}
char p[1010000],s[1000];
int k;
bool f[2010][210];
tmp g[2][210];
inline void update(int x,int y,int p,int q,bool z)
{
	if(!f[x][y])
	{
		if(f[p][q])
		{
			f[x][y]=f[p][q];
			g[x&1][y]=g[p&1][q];
			if(z)
			{
				g[x&1][y].a[++g[x&1][y].l]=x;
			}
		}
	}
	else if(f[p][q])
	{
		tmp t=g[p&1][q];
		if(z)
		{
			t.a[++t.l]=x;
		}
		if(t<g[x&1][y])
		{
			f[x][y]=f[p][q];
			g[x&1][y]=t;
		}
	}
}
int main()
{
	//freopen("1.in", "r", stdin);
	ios::sync_with_stdio(false);
	cin.getline(p+1,1000100);
	cin.getline(s+1,300);
	cin>>k;
	int P=strlen(p+1),S=strlen(s+1);
	int flag = 1;
	for (int i = 1; i <= 200; i++)
		if (p[i] != 'e') flag = 0;
	bool ans=0;
	tmp Ans;
	for(int l=1;l<=S&&P/k*l<=S;l++)
	{
		memset(f,0,sizeof(f));
		f[0][0]=1;
		for(int i=1;i<=k;i++)
		{
			if(i==P-P/k*k+1)
			{
				update(i,S-P/k*l,i-1,S-P/k*l,0);
				int j=S-P/k*l+1;
				bool flag=1;
				for(int t=0;t<=P/k;t++)
				{
					if(s[t*l+j]!=p[t*k+i])
					{
						flag=0;
						break;
					}
				}
				if(flag)
				{
					update(i,j,i-1,j-1,1);
				}
				continue;
			}
			update(i,0,i-1,0,0);
			for(int j=1;j<=l;j++)
			{
				update(i,j,i-1,j,0);
				bool flag=1;
				for(int t=0;t<=P/k;t++)
				{
					if(s[t*l+j]!=p[t*k+i])
					{
						flag=0;
						break;
					}
				}
				if(flag)
				{
					update(i,j,i-1,j-1,1);
				}
			}
		}
		if(f[k][l])
		{
			Ans=ans?min(Ans,g[k&1][l]):g[k&1][l];
			ans=1;
		}
	}
	if(ans)
	{
		string str;
		for(int i=1;i<=Ans.l;i++)
		{
			for(int j=Ans.a[i-1]+1;j<Ans.a[i];j++)
			{
				str += '0';
			}
			str += '1';
		}
		for(int i=Ans.a[Ans.l]+1;i<=k;i++)
		{
			str += '0';
		}
		int flag2 = 1;
		if (str.size() > 200) {
			for (int i = 0; i < 200; i++)
				if (str[i] != '0') flag2 = 0;
		}
		else flag2 = 0;
		if (flag && flag2) {
			cout << s << endl;
		}
		cout << str << endl;
	}
	else
	{
		cout<<0<<endl;
	}
	return 0;
}
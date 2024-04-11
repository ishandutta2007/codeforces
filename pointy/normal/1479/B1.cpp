#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
const int N=100005;
int a[N];
int ans;
int b,c;
int w[N],num[N],cnt;
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
void work()
{
	n=read();
	for (int i=1;i<=n;i++) 
	{
		a[i]=read();
		if (i==1||a[i]!=a[i-1]) 
		{
			++cnt;
			w[cnt]=a[i];
			num[cnt]++;
		}
		else num[cnt]++;
	}
	/*for (int i=1;i<=cnt;i++)
	{
		cout << w[i] << " " << num[i] << endl;
	}*/
	b=0,c=0;
	for (int i=1;i<=cnt;i++)
	{
		if (num[i]>1) 
		{
			if (b!=w[i]) ans++;
			if (c!=w[i]) ans++;
			b=w[i],c=w[i];
		}
		else
		{
			int tot=i;
			while (tot<=cnt)
			{
				if (num[tot]==1) tot++;
				else break;
			}
			tot--;
			int nc=-1;
			bool flag1=0,flag2=0;
			ans+=tot-i+1;
			if (tot!=cnt) nc=w[tot+1];
			else
			{
					b=-1,c=-1;
					goto ttt;
			}
			if (nc!=b)
			{
					b=-1,c=-1;
					goto ttt;
			}
			for (int j=i+1;j<=tot-1;j++) 
			{
				if (w[j]!=b&&w[j+1]!=w[j-1])
				{
					b=-1,c=-1;
					goto ttt;
				}
			}
			if (tot-i+1!=1&&w[i+1]!=b)
			{
					b=-1,c=-1;
					goto ttt;
			}
			if (tot-i+1!=1&&w[tot-1]!=b)
			{
					b=-1,c=-1;
					goto ttt;
			}
			if (tot-i+1==2)
			{
					b=-1,c=-1;
					goto ttt;
			}
			b=-1,c=nc;
			ttt:;
			i=tot;
		}
	}
}
int main()
{
	work();
	cout << ans;
	return 0;
}
// A ESE A
// A
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mem(x) memset(x,0,sizeof(x))
//const ll inf=1000000000000000000; 

const int N=100010;
int n,m,T; 
char a[N];

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
int u[30];
int b[N];
bool check(int x)
{
	int y=n-x;
	for (int i=0;i<=25;i++)
	{
		int tmp=m-u[i]%m;
		if (tmp==m) tmp=0;
		y-=tmp;
	}
	if (y<0) return 0;
	return 1;
} 
void work()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++) cin >> a[i];
	mem(u);
	for (int i=1;i<=n;i++) u[a[i]-'a']++;
	bool flag=0;
	for (int i=0;i<=25;i++)
	{
		if (u[i]%m!=0) flag=1;
	}
	if (flag==0)
	{
		for (int i=1;i<=n;i++) cout << a[i];
		cout << endl;
		return;
	}
	if (n%m!=0)
	{
		cout << -1 << endl;
		return;
	}
	mem(u);
	int tot=0,ans=1,cnt=0,wer;
	for (int i=1;i<=n;i++)
	{
		int p=a[i]-'a';
		for (int j=p+1;j<=25;j++)
		{
			u[j]++;
			if (check(i))
			{
				u[j]--;
				ans=i;
				wer=j;
				break;
			}
			u[j]--;
		}
		u[p]++;
		if ((ans!=i&&!check(i))||i==n) 
		{
			u[p]--;
			break;
		}
	}
	mem(u);
	for (int i=1;i<=ans;i++) u[a[i]-'a']++;
	u[a[ans]-'a']--,u[wer]++;
	for (int i=1;i<ans;i++) cout << a[i];
	cout << (char)('a'+wer);
	for (int i=0;i<=25;i++)
	{
		int w=m-u[i]%m;
		if (w==m) w=0;
		for (int j=1;j<=w;j++) b[++cnt]=i;
	}
	for (int i=cnt+1;i<=n-ans;i++) b[++cnt]=0;
	sort(b+1,b+cnt+1);
	for (int i=ans+1;i<=n;i++)
	{
		char tmp=b[i-ans]+'a';
		cout << tmp;
	}
	cout << endl;
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
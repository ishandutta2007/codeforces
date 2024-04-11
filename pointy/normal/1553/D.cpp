#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mem(x) memset(x,0,sizeof(x))
//const ll inf=1000000000000000000; 

const int N=200001;
int n,m,T; 
char a[N],b[N];

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
int lena,lenb;
void work()
{
	scanf("%s",a+1);
	scanf("%s",b+1);
	lena=strlen(a+1);
	lenb=strlen(b+1);
	if (lenb>lena)
	{
		cout << "NO\n";
		return;
	}
	if (lena==1)
	{
		if (a[1]==b[1]) cout << "YES\n";
		else cout << "NO\n";
		return ;
	}
	int tot=1;
	int last=-1;
	if ((lenb+lena)%2==1)
	{
		last=1;
		tot=2;
	}
	else last=0;
	for (int i=1;i<=lenb;i++)
	{
		while (1)
		{
			if (a[tot]==b[i]&&((tot-last)%2==1)) 
			{
				last=tot;
				tot++;
				break;
			}
			tot++;
			if (tot>lena) 
			{
				cout << "NO\n";
				return;
			}
		}
	}
	if ((n+1-last)%2==1)
	{
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
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
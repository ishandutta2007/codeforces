#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mem(x) memset(x,0,sizeof(x))
//const ll inf=1000000000000000000; 

const int N=200001;
int n,m,T; 
int a[N];
int b[N];

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
	for (int i=1;i<=n;i++) a[i]=read();
	int ma=n,tp=n;
	mem(b);
	for (int i=1;i<=n;i++)
	{
		for (int j=ma;j>=1;j--) 
		{
			if (b[j]==0) 
			{
				ma=j;
				break;
			}
		}
		for (int j=tp;j>=1;j--)
		{
			//cout << a[j] << " ";
			b[a[j]]=1;
			if (a[j]==ma)
			{
				for (int k=j;k<=tp;k++) cout << a[k] << " ";
				ma--;
				tp=j-1;
 				break;
			}
		}
		if (tp==0) return;
	}
	return;
}

int main()
{
	T=read();
	while (T--)
	{
		work();
		cout << endl;
	}
	return 0;
}
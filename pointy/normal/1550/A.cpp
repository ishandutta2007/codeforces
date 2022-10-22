#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mem(x) memset(x,0,sizeof(x))
//const ll inf=1000000000000000000; 
//const ll mod=1000000007;
//const ll mod=998244353;

const int N=100001;
int n,m,T; 
int a[N];

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
	int tot=1,ans=0;
	while (1)
	{
		if (tot>=n) 
		{
			cout << ans+1 << endl;
			return ;
		}
		n-=tot;
		tot+=2;
		ans++;
	}
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
// 1 3 5 7 9 11
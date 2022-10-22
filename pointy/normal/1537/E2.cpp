#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mem(x) memset(x,0,sizeof(x))
//const ll inf=1000000000000000000; 

const int N=100001;
int n,m,T; 
string a;
int ans;

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
	n=read(),m=read();
	cin >> a;
	ans=0;
	for (int i=1;i<n;i++)
	{
		int tot=i%(ans+1);
		if (a[tot]<a[i]) break;
		if (a[tot]>a[i]) ans=i;
	}
	for (int i=0;i<m;i++) cout << a[i%(ans+1)];
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mem(x) memset(x,0,sizeof(x))
//const ll inf=1000000000000000000; 

const int N=100001;
int n,m,T; 
string a,s,ans,t;

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
	for (int i=0;i<n;i++)
	{
		s+=a[i];
		int tmp=0;
		t="";
		while (tmp<m)
		{
			t+=s;
			tmp+=(i+1);
		}
		if (t<ans||ans=="") ans=t;
	}
	for (int i=0;i<m;i++) cout << ans[i];
	return 0;
}
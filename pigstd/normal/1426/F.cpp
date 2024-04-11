#include<bits/stdc++.h>
#define int long long
using namespace std;

const int sjy=1e9+7;
const int M=2e5+10;
const int _3=333333336;

int n,f[M][4],m1=1,m2;
char s[M];

signed main()
{
	cin>>n>>s+1;
	for (int i=1;i<=n;i++)m1=(m1*(s[i]=='?'?3:1))%sjy;
	m2=m1*_3;m2%=sjy;//cout<<m1<<endl;
	for (int i=1;i<=n;i++)
	{
		if (s[i]=='a')
			f[i][1]=f[i-1][1]+m1,
			f[i][2]=f[i-1][2],
			f[i][3]=f[i-1][3];
		if (s[i]=='b')
			f[i][1]=f[i-1][1],
			f[i][2]=f[i-1][2]+f[i-1][1],
			f[i][3]=f[i-1][3];
		if (s[i]=='c')
			f[i][1]=f[i-1][1],
			f[i][2]=f[i-1][2],
			f[i][3]=f[i-1][3]+f[i-1][2];
		if (s[i]=='?')
			f[i][1]=f[i-1][1]+m2,
			f[i][2]=f[i-1][2]+f[i-1][1]*_3,
			f[i][3]=f[i-1][3]+f[i-1][2]*_3;
		f[i][1]%=sjy,f[i][2]%=sjy,f[i][3]%=sjy;
	}
	cout<<f[n][3];
	return 0;
}
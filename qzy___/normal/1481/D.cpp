#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e3+1;
int T,n,m,A;
string s[N];
void C(int x,int y,int z)
{
	if(m%4==2)
	{
		cout<<x<<' ';
		for(int i=1;i<=m/2;i++)
			if(i&1)
				cout<<y<<' '<<z<<' ';
			else
				cout<<y<<' '<<x<<' ';
		cout<<'\n';
		return;
	}
	cout<<y<<' ';
	for(int i=1;i<=m/4;i++)
		cout<<z<<' '<<y<<' ';
	for(int i=1;i<=m/4;i++)
		cout<<x<<' '<<y<<' ';
	cout<<'\n';
}
signed main()
{
	cin>>T;
	while(T--&&cin>>n>>m)
	{
		for(int i=1;i<=n;i++)
			cin>>s[i],s[i]="1"+s[i];
		A=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
				if(s[i][j]==s[j][i]||m&1)
				{
					cout<<"YES"<<'\n',A=1;
					for(int k=1;k<=m+1;k++)
						if(k&1)
							cout<<i<<' ';
						else
							cout<<j<<' ';
					cout<<'\n';
					break;
				}
			if(A)
				break;
		}
		if(A)
			continue;
		if(n==2)
		{
			cout<<"NO"<<'\n';
			continue;
		}
		cout<<"YES"<<'\n';
		if(s[1][2]==s[2][3])
			C(1,2,3);
		else if(s[2][3]==s[3][1])
			C(2,3,1);
		else
			C(3,1,2);
	}
	return 0;
}
#include <bits/stdc++.h>
#define N 2000
#define M 110
using namespace std;
int n,a[M],b[M],ans=0,num;
string s;
int main(){
	int i,j;
	cin>>n>>s;
	for(i=0;i<s.size();i++)
	{
		if(s[i]=='1')
		{
			ans++;
		}
	}
	for(i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
	}
	for(i=1;i<=N;i++)
	{
		num=0;
		for(j=0;j<n;j++)
		{
			if(i>=b[j])
			{
				if((i-b[j])%a[j]==0)
				{
					if(s[j]=='0')
					{
						s[j]='1';
						num++;
					}
					else
					{
						s[j]='0';
					}
				}
				else
				{
					num+=(s[j]=='1');
				}
			}
			else
			{
				num+=(s[j]=='1');
			}
		}
		ans=max(ans,num);
	}
	cout<<ans<<endl;
	return 0;
}
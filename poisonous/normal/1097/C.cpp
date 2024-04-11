#include<bits/stdc++.h>
using namespace std;
string s[100010];
int num1[1000010],num2[1000010];
int lm[100010],rm[100010],nl[1000010],nr[1000010];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		int len=s[i].length();
		int x=0;
		for(int j=0;j<len;j++)
		{
			if(s[i][j]==')')
				x--,nr[i]++;
			else
				x++,nl[i]++;
			lm[i]=min(lm[i],x);
		}
		x=0;
		for(int j=len-1;j>=0;j--)
		{
			if(s[i][j]=='(')
				x--;
			else
				x++;
			rm[i]=min(rm[i],x);
		}
		if(lm[i]==0)
			num1[-rm[i]]++;
		else
			if(rm[i]==0)
				num2[-lm[i]]++;
	}
	int ans=num1[0]/2;
	for(int i=1;i<=1000000;i++)
		ans+=min(num1[i],num2[i]);
	cout<<ans;
			
}
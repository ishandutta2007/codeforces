#include<bits/stdc++.h>
using namespace std;
char s[10010];
int num[10010],num2[10010],k[10010];
int main()
{
	cin>>(s+1);
	int len=strlen(s+1);
	for(int i=1;i<=len;i++)
		if(s[i]=='(')
			num[i]=num[i-1]+1;
		else
			num[i]=num[i-1];
	for(int i=len;i>=1;i--)
	{
		if(s[i]==')')
			num2[i]=num2[i+1]+1;
		else
			num2[i]=num2[i+1];
	}
	int mx=0;
	for(int i=1;i<=len;i++)
	{
		mx=max(mx,min(num[i],num2[i+1]));
	}
	if(mx==0)
	{
		cout<<0;
		return 0;
	}
	cout<<1<<endl;
	cout<<mx*2<<endl;
	int p=0;
	for(int i=1;i<=len;i++)
		if(s[i]=='('&&p<mx)
		{
			p++;
			k[p]=i;
		}
	for(int i=len;i>=1;i--)
		if(s[i]==')'&&p<2*mx)
		{
			p++;
			k[p]=i;	
		}
	sort(k+1,k+mx*2+1);
	for(int i=1;i<=mx*2;i++)
		cout<<k[i]<<' ';
}
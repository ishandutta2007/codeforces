#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
char s[233];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>(s+1);
		n=strlen(s+1);
		int a=0,b=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='0')a++;
			else b++;
		}
		if(min(a,b)%2!=0)cout<<"DA"<<endl;
		else cout<<"NET"<<endl;
	}
	return 0;
}
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
using namespace std;
int main(int argc, char** argv) 
{
	long long n,k;
	string s;
	cin>>n>>k;
	long long v[n+1],uk=0;
	bool u[n+1];
	fill(u,u+n+1,false);
	fill(v,v+n+1,0ll);
	for(int i=0;i<=n;i++)
	{
		cin>>s;
		if(s[0]=='?')
		{
			uk++;
			u[i]=true;
		}
		else 
		{
			if(s[0]!='-') for(int j=0;j<s.size();j++) v[i]=v[i]*10+(int)(s[j]-'0');
			else for(int j=1;j<s.size();j++) v[i]=v[i]*10-(int)(s[j]-'0');
		}
	}
	if(k==0)
	{
		if(u[0]) v[0]=1;
		if(v[0]==0||(u[0]&&(n+1-uk)%2==1)) cout<<"Yes";
		else cout<<"No";
	}
	else
	{
		if(uk==0)
		{
			for(int i=n;i>0;i--)
			{
				v[i-1]+=k*v[i];
				if(v[i-1]>1000000000000000000||v[i-1]<-1000000000000000000) v[i-1]/=4;
			}
			if(v[0]==0) cout<<"Yes";
			else cout<<"No";
		}
		else
		{
			if((n+1)%2==0) cout<<"Yes";
			else cout<<"No";
		}
	}
	return 0;
}
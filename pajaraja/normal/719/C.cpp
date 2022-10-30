#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
int main(int argc, char** argv) 
{
	string s;
	int n,t,k=0,g,p,r,m=1,br=1;
	cin>>n>>t;
	bool nenadjen=true,h=true;
	cin>>s;
	while(nenadjen)
	{
		if(s[k]=='.')
		{
			g=k;
			nenadjen=false;
		}
		k++;
	}
	nenadjen=true;
	while(nenadjen&&k<n)
	{
		r=s[k]-'0';
		if(r>=5) nenadjen=false;
		k++;
	}
	k-=2;
	if(nenadjen)
	{
		cout<<s;
		return 0;
	}
	while(h&&br<=t)
	{
		br++;
		if(g==k)
		{
			m++;
			k--;
			h=false;
		}
		r=s[k+m]-'0';
		if(r<5) break;
		else s[k]++;
		k--;
	}
	if(k==g-2&&(s[k+1]==':'))
	{
		int l=k+1;
		s[l]='9';
		while(s[l]=='9'&&l>=0)
		{
			s[l]='0';
			l--;
		}
		if(l==-1) cout<<1;
		else s[l]++;
	}
		k+=2;
		if(k>n) k=n;
		if(k==g+1) k++;
	for(int i=0;i<k;i++) cout<<s[i];
	return 0;
}
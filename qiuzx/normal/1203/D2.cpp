#include <bits/stdc++.h>
#define N 200010
using namespace std;
string s,t;
int ft[N],bk[N];
void make()
{
	int i=0,j;
	ft[0]=-1;
	for(j=0;j<s.size();j++)
	{
		if(s[j]==t[i])
		{
			ft[i+1]=j;
			i++;
		}
	}
	i=t.size()-1;
	for(j=s.size()-1;j>=0;j--)
	{
		if(s[j]==t[i])
		{
			bk[i]=j;
			i--;
		}
	}
	bk[t.size()]=s.size();
	return;
}
int main(){
	int i,ans=0;
	cin>>s>>t;
	make();
	for(i=0;i<=t.size();i++)
	{
		ans=max(ans,bk[i]-ft[i]-1);
	}
	cout<<ans<<endl;
	return 0;
}
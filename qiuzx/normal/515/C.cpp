//cubelover
#include <bits/stdc++.h>
using namespace std;
int d[10]={};
vector<int> ans;
void add(int x,int y)
{
	int i,j,t;
	for(j=2;j<=x;j++)
	{
		t=j;
		for(i=2;i<=7;i++)
		{
			while(t%i==0)
			{
				d[i]+=y;
				t/=i;
			}
		}
	}
}
bool f(int x)
{
	int i;
	for(i=0;i<10;i++)
	{
		if(d[i]<0)
		{
			return false;
		}
		if(d[i])
		{
			break;
		}
	}
	if(i==10)
	{
		return true;
	}
	while(x>1)
	{
		if(x%2==1||x==2)
		{
			add(x,-1);
			if(f(x))
			{
				ans.push_back(x);
				return true;
			}
			add(x,1);
		}
		x--;
	}
	return false;
}
int main(){
	int n,i;
	string s;
	cin>>n>>s;
	for(i=0;i<n;i++)
	{
		add(s[i]-'0',1);
	}
	f(7);
	reverse(ans.begin(),ans.end());
	for(i=0;i<ans.size();i++)
	{
		cout<<ans[i];
	}
	cout<<endl;
	return 0;
}
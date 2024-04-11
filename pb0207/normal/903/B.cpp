#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int h1,a1,c1,h2,a2;

vector<int>ans;

int main()
{
	cin>>h1>>a1>>c1;
	cin>>h2>>a2;
	while(true)
	{
		if(h2<=a1)
		{
			ans.push_back(1);
			break;
		}
		if(h1<=a2)
			h1+=c1,ans.push_back(0);
		else
			h2-=a1,ans.push_back(1);
		h1-=a2;
	}
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)
		if(ans[i]==0)
			puts("HEAL");
		else
			puts("STRIKE");
}
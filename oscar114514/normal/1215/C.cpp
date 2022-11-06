#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[233333],t[233333];
vector<int> ab,ba;
vector<pair<int,int> >ans;
int main()
{
	scanf("%d %s %s",&n,s+1,t+1);
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='a'&&t[i]=='b')ab.push_back(i);
		else if(s[i]=='b'&&t[i]=='a')ba.push_back(i);
	}
	if((ab.size()+ba.size())%2)return printf("-1"),0;
	if(ab.size()%2==1)
	{
		ans.push_back(make_pair(ab[0],ab[0]));
		ans.push_back(make_pair(ab[0],ba[0]));
		for(int i=1;i<ab.size();i+=2)
		{
			ans.push_back(make_pair(ab[i],ab[i+1]));
		}
		for(int i=1;i<ba.size();i+=2)
		{
			ans.push_back(make_pair(ba[i],ba[i+1]));
		}
	}
	else
	{
		for(int i=0;i<ab.size();i+=2)
		{
			ans.push_back(make_pair(ab[i],ab[i+1]));
		}
		for(int i=0;i<ba.size();i+=2)
		{
			ans.push_back(make_pair(ba[i],ba[i+1]));
		}
	}
	printf("%d\n",ans.size());
	for(auto x:ans)
	{
		printf("%d %d\n",x.first,x.second);
	}
	return 0;
}
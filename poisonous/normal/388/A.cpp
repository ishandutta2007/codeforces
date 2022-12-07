#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
using namespace std;
multiset<int,greater<int> > s;
int main()
{
	int box[110];
	int n,n1;
	cin>>n;
	for(n1=1;n1<=n;n1++)
		cin>>box[n1];
	sort(box+1,box+n+1);
	int ans=0;
	for(n1=1;n1<=n;n1++)
	{
		if(s.lower_bound(box[n1])!=s.end())
		{
			int k=*s.lower_bound(box[n1]);
			s.erase(s.find(k));
			s.insert(k+1);
		}
		else
		{
			s.insert(1);
			ans++;
		}
	}
	cout<<ans;
}
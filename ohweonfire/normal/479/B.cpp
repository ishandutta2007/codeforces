#include <bits/stdc++.h>
using namespace std;
set<pair<int,int> > st;
int n,k,a,b;
vector<int> ansx,ansy;
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		st.insert(make_pair(a,i));
	}
	while(k--)
	{
		pair<int,int> p1=*st.begin(),p2=*(--st.end());
		if(p1.first>p2.first-2)
			break;
		st.erase(p1);
		st.erase(p2);
		p1.first++;
		p2.first--;
		st.insert(p1);
		st.insert(p2);
		ansx.push_back(p2.second);
		ansy.push_back(p1.second);
	}
	pair<int,int> p1=*st.begin(),p2=*(--st.end());
	printf("%d %d\n",p2.first-p1.first,ansx.size());
	for(int i=0;i<ansx.size();i++)
		printf("%d %d\n",ansx[i],ansy[i]);
	return 0;
}
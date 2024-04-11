#include <string>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int priority[202][202],ord[202],n,cnt;
string name[202];
string myname,a,b,c,d,e;
map<string,int> mp;
bool cmp(int x,int y)
{
	if(priority[x][0]!=priority[y][0])
		return priority[x][0]>priority[y][0];
	return name[x]<name[y];
}
inline int getid(string &tmp)
{
	if(mp.find(tmp)==mp.end())
	{
		mp[tmp]=++cnt;
		name[cnt]=tmp;
		return cnt;
	}
	else
		return mp[tmp];
}
int main()
{
	cin>>myname;
	mp[myname]=0;
	cin>>n;
	while(n--)
	{
		cin>>a>>b;
		if(b=="likes")
		{
			cin>>c>>d;
			c=c.substr(0,c.size()-2);
			int ta=getid(a),tb=getid(c);
			priority[ta][tb]+=5;
			priority[tb][ta]+=5;
		}
		else if(b=="posted")
		{
			cin>>c>>d>>e;
			d=d.substr(0,d.size()-2);
			int ta=getid(a),tb=getid(d);
			priority[ta][tb]+=15;
			priority[tb][ta]+=15;
		}
		else
		{
			cin>>c>>d>>e;
			d=d.substr(0,d.size()-2);
			int ta=getid(a),tb=getid(d);
			priority[ta][tb]+=10;
			priority[tb][ta]+=10;
		}
	}
	for(int i=1;i<=cnt;i++)
		ord[i]=i;
	sort(ord+1,ord+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
		cout<<name[ord[i]]<<endl;
	return 0;
}
/*
aba
1
likes likes posted's post
*/
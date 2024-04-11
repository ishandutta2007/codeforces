#include<bits/stdc++.h>
using namespace std;
const int MAX=109;
int n,a[MAX],cnt1,cnt2,res1,res2;
set<pair<int,int> > s;
string ans1[MAX*MAX],ans2[MAX*MAX],zer,tmp;
stringstream ss,tt;
int main()
{
	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i],zer+='0';
	if (n==2)
	{	
		if (a[0]==a[1]) cout<<a[0]<<'\n'<<0<<endl;
		else 
		{
			cout<<0<<endl<<max(a[0],a[1])<<endl;
			for (int i=0;i<max(a[0],a[1]);i++) cout<<11<<endl;
		}
		return 0;
	}
	for (int i=0;i<n;i++) s.insert({a[i],i});
	while ((*s.begin()).first!=(*s.rbegin()).first)
	{
		auto it=*(s.rbegin());
		s.erase(it);
		auto it2=*(s.rbegin());
		s.erase(it2);
		it.first=max(0,it.first-1);
		it2.first=max(0,it2.first-1);
		tmp=zer;
		tmp[it.second]=tmp[it2.second]='1';
		ans1[cnt1++]=tmp;
		s.insert(it);
		s.insert(it2);
	}
	res1=(*s.begin()).first;
	ss<<(*s.begin()).first<<endl<<cnt1<<endl;
	for (int i=0;i<cnt1;i++) ss<<ans1[i]<<'\n';
	s.clear();
	for (int i=0;i<n;i++) s.insert({a[i],i});
	auto it=*(s.rbegin());
	s.erase(it);
	auto it2=*(s.rbegin());
	s.erase(it2);
	auto it3=*(s.rbegin());
	s.erase(it3);
	it.first=max(0,it.first-1);
	it2.first=max(0,it2.first-1);
	it3.first=max(0,it3.first-1);
	tmp=zer;
	tmp[it.second]=tmp[it2.second]=tmp[it3.second]='1';
	ans2[cnt2++]=tmp;
	s.insert(it);
	s.insert(it2);	
	s.insert(it3);	
	while ((*s.begin()).first!=(*s.rbegin()).first)
	{
		auto it=*(s.rbegin());
		s.erase(it);
		auto it2=*(s.rbegin());
		s.erase(it2);
		it.first=max(0,it.first-1);
		it2.first=max(0,it2.first-1);
		tmp=zer;
		tmp[it.second]=tmp[it2.second]='1';
		ans2[cnt2++]=tmp;
		s.insert(it);
		s.insert(it2);
	}
	if ((*s.begin()).first>res1)
	{
		cout<<(*s.begin()).first<<endl<<cnt2<<endl;
		for (int i=0;i<cnt2;i++) cout<<ans2[i]<<'\n';
	} else cout<<ss.str();
	
	return 0;
}
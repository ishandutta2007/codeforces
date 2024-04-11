#include <bits/stdc++.h>
#define N 100010
using namespace std;
int main(){
	string s[N];
	int n,i,j,l,r,pos,cor=0,ans;
	vector<pair<int,int> > vp;
	vector<int> v;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>s[i];
	}
	for(i=0;i<n;i++)
	{
		l=0;
		r=0;
		for(j=0;j<s[i].size();j++)
		{
			if(s[i][j]=='(')
			{
				l++;
			}
			else
			{
				if(l)
					l--;
				else
					r++;
			}
		}
		if(l==0&&r==0)
		{
			cor++;
		}
		else if(l&&r)
		{
			continue;
		}
		else
		{
			vp.push_back(make_pair(l,r));
			v.push_back(l);
		}
	}
	cor/=2;
	ans=cor;
	sort(vp.begin(),vp.end());
	sort(v.begin(),v.end());
	i=0;
	if(!vp.size())
	{
		cout<<ans<<endl;
		return 0;
	}
	while(vp[i].first==0)
	{
		if(vp[i].second==0)
		{
			i++;
			continue;
		}
		pos=find(v.begin(),v.end(),vp[i].second)-v.begin();
		if(pos!=v.size())
		{
			ans++;
			v.erase(v.begin()+pos);
			vp.erase(vp.begin()+pos);
		}
		i++;
	}
	cout<<ans<<endl;
	return 0;
}
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define F first
#define S second
#define ll long long
using namespace std;
vector<int> va[30];
int main(){
	int T,i,ans=0,pos,j;
	string s,t;
	cin>>T;
	while(T--)
	{
		cin>>s>>t;
		for(i=0;i<26;i++)
		{
			va[i].clear();
		}
		for(i=0;i<s.size();i++)
		{
			va[s[i]-'a'].push_back(i);
		}
		ans=0;
		for(i=0;i<t.size();)
		{
			pos=0;
			ans++;
			while(pos!=-1&&i<t.size())
			{
				j=lower_bound(va[t[i]-'a'].begin(),va[t[i]-'a'].end(),pos)-va[t[i]-'a'].begin();
				if(j!=va[t[i]-'a'].size())
				{
					pos=va[t[i]-'a'][j]+1;
					i++;
				}
				else
				{
					if(pos==0)
					{
						ans=-1;
						i=t.size();
						break;
					}
					pos=-1;
				} 
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
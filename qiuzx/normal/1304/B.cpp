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
#define N 110
using namespace std;
int n,m;
vector<int> ansl,ansr;
bool book[N];
string s[N];
map<string,int> mp;
bool palin(string a)
{
	int i,j;
	for(i=0,j=a.size()-1;i<=j;i++,j--)
	{
		if(a[i]!=a[j])
		{
			return false;
		}
	}
	return true;
}
int main(){
	int i,ans;
	string t;
	cin>>n>>m;
	memset(book,false,sizeof(book));
	for(i=1;i<=n;i++)
	{
		cin>>s[i];
		if(mp[s[i]]!=0)
		{
			ansl.push_back(mp[s[i]]);
			book[mp[s[i]]]=false;
			ansr.push_back(i);
			book[i]=false;
		}
		else if(palin(s[i]))
		{
			book[i]=true;
		}
		t=s[i];
		reverse(t.begin(),t.end());
		mp[t]=i;
	}
	ans=(ansl.size()+ansr.size())*m;
	for(i=1;i<=n;i++)
	{
		if(book[i])
		{
			ans+=m;
			break;
		}
	}
	cout<<ans<<endl;
	for(i=0;i<ansl.size();i++)
	{
		cout<<s[ansl[i]];
	}
	for(i=1;i<=n;i++)
	{
		if(book[i])
		{
			cout<<s[i];
			break;
		}
	}
	reverse(ansr.begin(),ansr.end());
	for(i=0;i<ansr.size();i++)
	{
		cout<<s[ansr[i]];
	}
	cout<<endl;
	return 0;
}
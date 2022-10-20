#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 110
using namespace std;
int n,ans=0;
bool l,r;
string s;
int main(){
	int i,x;
	cin>>n>>s;
	s="?"+s+"?";
	while(1&&s.size()>1)
	{
		char c='a'-1;
		for(i=1;i+1<s.size();i++)
		{
			if(s[i]==s[i-1]+1||s[i]==s[i+1]+1)
			{
				if(s[i-1]-1==s[i+1]||s[i+1]-1==s[i-1])
				{
					if(c<s[i])
					{
						x=i;
						c=s[i];
					}
				}
			}
		}
		if(c==('a'-1))
		{
			break;
		}
		s.erase(s.begin()+x);
		ans++;
	//	cout<<s<<endl; 
	}
	while(1&&s.size()>1)
	{
		char c='a'-1;
		for(i=1;i+1<s.size();i++)
		{
			if(s[i]==s[i-1]+1||s[i]==s[i+1]+1)
			{
				if(c<s[i])
				{
					x=i;
					c=s[i];
				}
			}
		}
		if(c==('a'-1))
		{
			break;
		}
		s.erase(s.begin()+x);
		ans++;
	//	cout<<s<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
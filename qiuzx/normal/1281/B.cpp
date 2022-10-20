#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define F first
#define S second
#define ll long long
using namespace std;
int main(){
	int T,i,pos;
	bool fd;
	string s,c;
	cin>>T;
	while(T--)
	{
		cin>>s>>c;
		if(s<c)
		{
			cout<<s<<endl;
			continue;
		}
		fd=false;
		for(i=0;i<s.size();i++)
		{
			for(char c='A';c<s[i];c++)
			{
				pos=s.rfind(c);
				if(pos>i)
				{
					char c=s[i];
					s[i]=s[pos];
					s[pos]=c;
					fd=true;
					break;
				}
			}
			if(fd)
			{
				break;
			}
		}
		if(s<c)
		{
			cout<<s<<endl;
		}
		else
		{
			cout<<"---"<<endl;
		}
	}
	return 0;
}
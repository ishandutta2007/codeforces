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
	ll T,n,i,j,ssz;
	string s,t,c;
	cin>>T;
	while(T--)
	{
		cin>>n>>s;
		ssz=s.size();
		j=0;
		t=s;
		c=s;
		while(s.size()<n)
		{
			t.erase(t.begin());
			c=t;
			for(i=1;i<s[j]-'0';i++)
			{
				s+=c;
				t+=c;
			}
			j++;
		}
		for(i=0;i<n;i++)
		{
			/*if(c.size()<=n)
			{
				for(j=1;j<s[i]-'0';j++)
				{
					s+=c.substr(i+1);
				}
				c=s;
			}*/
			ssz=(i+1+(s[i]-'0')*((ssz+MOD-i-1)%MOD))%MOD;
		}
		cout<<ssz<<endl; 
	}
	return 0;
}
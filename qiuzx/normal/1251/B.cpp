#include <bits/stdc++.h>
using namespace std;
int t,n,on,o,z;
string s;
int main(){
	int i,j;
	cin>>t;
	while(t--)
	{
		cin>>n;
		on=o=z=0;
		for(i=0;i<n;i++)
		{
			cin>>s;
			if(s.size()%2==1)
			{
				on++;
			}
			for(j=0;j<s.size();j++)
			{
				if(s[j]=='0')
				{
					o++;
				}
				else
				{
					z++;
				}
			}
		}
		if(on==0&&o%2==1&&z%2==1)
		{
			cout<<n-1<<endl;
		}
		else
		{
			cout<<n<<endl;
		}
	}
	return 0;
}
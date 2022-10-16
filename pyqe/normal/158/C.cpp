#include <bits/stdc++.h>

using namespace std;

long long nn=0;
vector<long long> sk[100069];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long t,rr,i,j,k,ln,sz;
	string s;
	vector<long long> v;
	
	cin>>t;
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		if(s[0]=='p')
		{
			for(i=1;i<=nn;i++)
			{
				cout<<"/";
				sz=sk[i].size();
				for(j=0;j<sz;j++)
				{
					cout<<(char)(sk[i][j]+'a');
				}
			}
			cout<<"/\n";
		}
		else
		{
			cin>>s;
			ln=s.length();
			i=0;
			if(s[0]=='/')
			{
				nn=0;
				i++;
			}
			for(;i<ln;i++)
			{
				if(s[i]=='/')
				{
					nn++;
					sk[nn]=v;
					v.clear();
				}
				else if(s[i]=='.')
				{
					nn--;
					i+=2;
				}
				else
				{
					k=s[i]-'a';
					v.push_back(k);
				}
			}
			if(!v.empty())
			{
				nn++;
				sk[nn]=v;
				v.clear();
			}
		}
	}
}
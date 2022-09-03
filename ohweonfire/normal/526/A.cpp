#include <bits/stdc++.h>
using namespace std;
const int maxn=105;
string s;
int n;
int main()
{
	cin>>n;
	cin>>s;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
		{
			int len=j-i;
			if(i+len*4>n)continue;
			bool ok=true;
			for(int k=0;k<5&&ok;k++)
				ok&=s[i+len*k]=='*';
			if(!ok)continue;
			puts("yes");
			return 0;
		}
	puts("no");
	return 0;
}
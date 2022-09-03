#include <string>
#include <iostream>
using namespace std;
string tmp,s[8]={"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
int n;
int main()
{
	cin>>n>>tmp;
	for(int i=0;i<8;i++)
	{
		if(n!=s[i].size())continue;
		int j;
		for(j=0;j<n;j++)
			if(tmp[j]!='.'&&s[i][j]!=tmp[j])break;
		if(j==n)
		{
			cout<<s[i]<<endl;
			return 0;
		}
	}
	return 0;
}
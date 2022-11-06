#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
char s[233333];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>s;
		n=strlen(s);
		for(int i=0;i<n;i+=2)cout<<s[i];
		cout<<s[n-1]<<endl;
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
long long x[200][200],y[200];
char s[100010];
long long ans=0;
int main()
{	
	cin>>(s+1);
	int l=strlen(s+1);
	for(int i=1;i<=l;i++)
	{
		for(int j='a';j<='z';j++)
			x[j][s[i]]+=y[j];
		y[s[i]]++;
	}
	for(int i='a';i<='z';i++)
	{
		ans=max(ans,y[i]);
		for(int j='a';j<='z';j++)
			ans=max(ans,x[i][j]);
	}
	cout<<ans;
}
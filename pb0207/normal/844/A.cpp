#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

char s[1001];

int tong[1001],k;

int main()
{
	scanf("%s",s);
	cin>>k;
	int n=strlen(s);
	if(k>n)
	{
		cout<<"impossible";
		return 0;
	}
	for(int i=0;i<n;i++)
		tong[s[i]]++;
	int ans=0;
	for(int i='a';i<='z';i++)
	{
		if(tong[i])
			ans++;
	}
	cout<<max(k-ans,0);
}
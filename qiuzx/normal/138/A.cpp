#include <bits/stdc++.h>
#define N 100010
using namespace std;
string s[N];
int n,k;
int getpos(string a)
{
	int i,cnt=0;
	for(i=a.size()-1;i>=0;i--)
	{
		if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u')
		{
			cnt++;
		}
		if(cnt==k)
		{
			return i;
		}
	}
	return -1;
}
int main(){
	bool aabb=true,abab=true,abba=true;
	int i,pos;
	cin>>n>>k;
	n*=4;
	for(i=0;i<n;i++)
	{
		cin>>s[i];
	}
	for(i=0;i<n;i++)
	{
		pos=getpos(s[i]);
		if(pos==-1)
		{
			cout<<"NO"<<endl;
			return 0;
		}
		s[i]=s[i].substr(pos);
	}
	for(i=0;i<n;i+=4)
	{
		aabb&=(s[i]==s[i+1]&&s[i+2]==s[i+3]);
		abab&=(s[i]==s[i+2]&&s[i+1]==s[i+3]);
		abba&=(s[i]==s[i+3]&&s[i+1]==s[i+2]);
	}
	if(aabb&&abab&&abba)
	{
		cout<<"aaaa"<<endl;
	}
	else if(aabb)
	{
		cout<<"aabb"<<endl;
	}
	else if(abab)
	{
		cout<<"abab"<<endl;
	}
	else if(abba)
	{
		cout<<"abba"<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}
	return 0;
}
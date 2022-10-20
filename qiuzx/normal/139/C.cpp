#include <bits/stdc++.h>
#define N 100010
using namespace std;
string s[N];
int n,k;
string check()
{
	bool aaaa=true,aabb=true,abab=true,abba=true;
	int i;
	for(i=0;i<n;i+=4)
	{
		if(s[i]!=s[i+1]||s[i]!=s[i+2]||s[i]!=s[i+3])
		{
			aaaa=false;
		}
		if(s[i]!=s[i+1]||s[i+2]!=s[i+3])
		{
			aabb=false;
		}
		if(s[i]!=s[i+2]||s[i+1]!=s[i+3])
		{
			abab=false;
		}
		if(s[i]!=s[i+3]||s[i+1]!=s[i+2])
		{
			abba=false;
		}
	}
	if(aaaa)
	{
		return "aaaa";
	}
	if(aabb)
	{
		return "aabb";
	}
	if(abab)
	{
		return "abab";
	}
	if(abba)
	{
		return "abba";
	}
	return "NO";
}
bool vow(char a)
{
	if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u')
	{
		return true;
	}
	return false;
}
int getpos(string a)
{
	int i,cnt=0;
	for(i=a.size()-1;i>=0;i--)
	{
		if(vow(a[i]))
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
	cout<<check()<<endl;
	return 0;
}
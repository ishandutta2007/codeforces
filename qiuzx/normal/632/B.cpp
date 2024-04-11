#include <bits/stdc++.h>
#define N 500010
using namespace std;
long long n,p[N],i,mx,qdh[N],con;
int main(){
	string s;
	cin>>n;
	qdh[0]=0;
	for(i=0;i<n;i++)
	{
		cin>>p[i];
	}
	cin>>s;
	for(i=0;i<s.size();i++)
	{
		if(s[i]=='B')
		{
			qdh[i+1]=qdh[i]+p[i];
		}
		else
		{
			qdh[i+1]=qdh[i];
		}
	}
	mx=qdh[n];
	con=0;
	for(i=0;i<n;i++)
	{
		if(s[i]=='A')
		{
			con+=p[i];
		}
		mx=max(mx,con+qdh[n]-qdh[i+1]);
	}
	con=0;
	for(i=n-1;i>=0;i--)
	{
		if(s[i]=='A')
		{
			con+=p[i];
		}
		mx=max(mx,con+qdh[i+1]);
	}
	cout<<mx<<endl;
	return 0;
}
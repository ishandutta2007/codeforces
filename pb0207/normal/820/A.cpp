#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int c,vv,a,v,l,cc,vnow,ans;

int main()
{
	cin>>c>>v>>vv>>a>>l;
	cc=c,vnow=v;
	while(cc>0)
	{
		int tmpv=vnow;
		if(c-cc<l)
			tmpv-=c-cc;
		else
			tmpv-=l;
		cc-=tmpv;
		vnow=min(vnow+a,vv);
		ans++;
	}
	cout<<ans;
}
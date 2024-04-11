#include <bits/stdc++.h>

using namespace std;

const string ky="DURL";
long long n,m,d,yk[26];

int main()
{
	long long t,rr,i,k,y,x,ymn,ymx,xmn,xmx;
	string s;
	
	for(i=0;i<4;i++)
	{
		yk[ky[i]-'A']=i;
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		cin>>s;
		d=s.length();
		y=0;
		x=0;
		ymn=0;
		ymx=0;
		xmn=0;
		xmx=0;
		for(i=1;i<=d;i++)
		{
			k=yk[s[i-1]-'A'];
			if(k<2&&ymx-ymn<n-1)
			{
				y+=!k*2-1;
				ymn=min(ymn,y);
				ymx=max(ymx,y);
			}
			if(k>=2&&xmx-xmn<m-1)
			{
				x+=!(k%2)*2-1;
				xmn=min(xmn,x);
				xmx=max(xmx,x);
			}
		}
		printf("%lld %lld\n",1-ymn,1-xmn);
	}
}
#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,d,a[10],fq[10],ls[10];
bitset<1069> vtd[1069];
queue<pair<pair<long long,long long>,long long>> q[10];

int main()
{
	long long rr=1,i,j,k,c=0,y,x,w,im,ky[4]={-1,0,1,0},kx[4]={0,1,0,-1},yy,xx;
	string s;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=1;i<=d;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=1;i<=n;i++)
	{
		cin>>s;
		for(j=1;j<=m;j++)
		{
			vtd[i][j]=s[j-1]=='#';
			if(s[j-1]!='.'&&s[j-1]!='#')
			{
				k=s[j-1]-'0';
				q[k].push({{i,j},0});
				vtd[i][j]=1;
				fq[k]++;
			}
			c+=vtd[i][j];
		}
	}
	for(i=1;1;i=i%d+1)
	{
		for(;!q[i].empty();)
		{
			y=q[i].front().fr.fr;
			x=q[i].front().fr.sc;
			w=q[i].front().sc;
			if(w==a[i]*rr)
			{
				break;
			}
			q[i].pop();
			for(im=0;im<4;im++)
			{
				yy=y+ky[im];
				xx=x+kx[im];
				if(yy&&xx&&yy<=n&&xx<=m&&!vtd[yy][xx])
				{
					q[i].push({{yy,xx},w+1});
					vtd[yy][xx]=1;
					fq[i]++;
					c++;
				}
			}
		}
		if(c==ls[i])
		{
			break;
		}
		ls[i]=c;
		if(i==d)
		{
			rr++;
		}
	}
	for(i=1;i<=d;i++)
	{
		printf("%lld%c",fq[i]," \n"[i==d]);
	}
}
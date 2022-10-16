#include <bits/stdc++.h>

using namespace std;

long long yk[26],fq[1000069][6],sq[100069][3],zs=0;
vector<string> a[1000069][6];

void ins(long long x,long long y,long long w)
{
	zs++;
	sq[zs][0]=x;
	sq[zs][1]=y;
	sq[zs][2]=w;
}

int main()
{
	long long t,rr,i,j,r,ii,ln,k,c,ls,sz,z=0;
	string s;
	
	yk[0]=1;
	yk[4]=2;
	yk[8]=3;
	yk[14]=4;
	yk[20]=5;
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		ln=s.length();
		c=0;
		for(i=1;i<=ln;i++)
		{
			k=yk[s[i-1]-'a'];
			if(k)
			{
				c++;
				ls=k;
			}
		}
		a[c][ls].push_back(s);
		fq[c][ls]++;
	}
	for(i=1;i<=1000000;i++)
	{
		for(j=1;j<=5;j++)
		{
			for(r=1;r<fq[i][j];r+=2)
			{
				ins(i,j,r-1);
				ins(i,j,r);
			}
		}
	}
	z=zs/2;
	for(i=1;i<=1000000;i++)
	{
		ls=0;
		for(j=1;j<=5;j++)
		{
			if(fq[i][j]%2)
			{
				if(!ls)
				{
					ls=j;
				}
				else
				{
					ins(i,ls,fq[i][ls]-1);
					ins(i,j,fq[i][j]-1);
					ls=0;
				}
			}
		}
	}
	z=min(z,zs/4);
	printf("%lld\n",z);
	for(i=2;i<=zs+1-i&&sq[i-1][1]==sq[i][1];i+=2)
	{
		for(ii=0;ii<2;ii++)
		{
			printf("%s %s\n",a[sq[zs+1-i+ii][0]][sq[zs+1-i+ii][1]][sq[zs+1-i+ii][2]].c_str(),a[sq[i-ii][0]][sq[i-ii][1]][sq[i-ii][2]].c_str());
		}
	}
}
#include <bits/stdc++.h>

using namespace std;

long long d[2]={0,0},w[2]={0,0},p[2][2];
string s[3];
bool m[2][3][3],g,gg[2];

void dd(long long y1,long long x1,long long y2,long long x2,long long id)
{
	long long i,j,e1=(y2-y1)/2,e2=(x2-x1)/2,c=0;
	
	g=true;
	if(!gg[id])
	{
		i=y1;
		j=x1;
		for(c=0;c<3;c++)
		{
			if(m[id][i][j])
			{
				g=false;
				gg[id]=true;
				p[id][0]=i;
				p[id][1]=j;
			}
			m[id][i][j]=true;
			i+=e1;
			j+=e2;
		}
	}
	else
	{
		i=y1;
		j=x1;
		for(c=0;c<3;c++)
		{
			if(i==p[id][0]&&j==p[id][1])
			{
				g=false;
			}
			i+=e1;
			j+=e2;
		}
	}
	if(g)
	{
		w[id]++;
	}
}

int main()
{
	long long i,j;
	
	for(i=0;i<3;i++)
	{
		cin>>s[i];
		for(j=0;j<3;j++)
		{
			if(s[i][j]=='X')
			{
				d[0]++;
			}
			else if(s[i][j]=='0')
			{
				d[1]++;
			}
		}
	}
	if(d[0]<d[1]||d[0]-d[1]>1)
	{
		printf("illegal\n");
		return 0;
	}
	for(i=0;i<3;i++)
	{
		if(s[i]=="XXX")
		{
			dd(i,0,i,2,0);
		}
		if(s[0][i]=='X'&&s[1][i]=='X'&&s[2][i]=='X')
		{
			dd(0,i,2,i,0);
		}
		if(s[i]=="000")
		{
			dd(i,0,i,2,1);
		}
		if(s[0][i]=='0'&&s[1][i]=='0'&&s[2][i]=='0')
		{
			dd(0,i,2,i,1);
		}
	}
	if(s[0][0]=='X'&&s[1][1]=='X'&&s[2][2]=='X')
	{
		dd(0,0,2,2,0);
	}
	if(s[0][2]=='X'&&s[1][1]=='X'&&s[2][0]=='X')
	{
		dd(0,2,2,0,0);
	}
	if(s[0][0]=='0'&&s[1][1]=='0'&&s[2][2]=='0')
	{
		dd(0,0,2,2,1);
	}
	if(s[0][2]=='0'&&s[1][1]=='0'&&s[2][0]=='0')
	{
		dd(0,2,2,0,1);
	}
	if(w[0]+w[1]>1)
	{
		printf("illegal\n");
		return 0;
	}
	if(w[0]==1)
	{
		if(d[0]==d[1])
		{
			printf("illegal\n");
			return 0;
		}
		printf("the first player won\n");
		return 0;
	}
	if(w[1]==1)
	{
		if(d[0]>d[1])
		{
			printf("illegal\n");
			return 0;
		}
		printf("the second player won\n");
		return 0;
	}
	if(d[0]==5&&d[1]==4)
	{
		printf("draw\n");
		return 0;
	}
	if(d[0]>d[1])
	{
		printf("second\n");
		return 0;
	}
	if(d[0]==d[1])
	{
		printf("first\n");
	}
}
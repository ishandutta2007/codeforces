#include <bits/stdc++.h>

using namespace std;

int n,ma=62,yk[256],am[11][62][62],pc[62][62][62],dv=998244353;
map<string,bool> vtd;

int main()
{
	int rr,i,j,r,ii,jj,sz,w,ca[4],z=0;
	string s;
	
	for(i=0;i<26;i++)
	{
		yk[i+'a']=i;
	}
	for(i=0;i<26;i++)
	{
		yk[i+'A']=i+26;
	}
	for(i=0;i<10;i++)
	{
		yk[i+'0']=i+52;
	}
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		cin>>s;
		sz=s.size();
		for(ii=0;ii<2;ii++)
		{
			if(!vtd[s])
			{
				vtd[s]=1;
				am[sz][yk[s[0]]][yk[s[sz-1]]]++;
			}
			reverse(s.begin(),s.end());
		}
	}
	for(rr=3;rr<=10;rr++)
	{
		for(i=0;i<ma;i++)
		{
			for(j=i;j<ma;j++)
			{
				for(r=j;r<ma;r++)
				{
					pc[i][j][r]=0;
					for(jj=0;jj<ma;jj++)
					{
						pc[i][j][r]=(pc[i][j][r]+(long long)am[rr][i][jj]*am[rr][j][jj]%dv*am[rr][r][jj]%dv)%dv;
					}
				}
			}
		}
		w=24;
		ca[0]=1;
		for(i=0;i<ma;i++)
		{
			w/=ca[0]+1;
			ca[1]=ca[0]+1;
			for(j=i;j<ma;j++)
			{
				w/=ca[1]+1;
				ca[2]=ca[1]+1;
				for(r=j;r<ma;r++)
				{
					w/=ca[2]+1;
					ca[3]=ca[2]+1;
					for(jj=r;jj<ma;jj++)
					{
						z=(z+(long long)pc[i][j][r]*pc[i][j][jj]%dv*pc[i][r][jj]%dv*pc[j][r][jj]%dv*w%dv)%dv;
						w*=ca[3];
						ca[3]=1;
					}
					w*=ca[2];
					ca[2]=1;
				}
				w*=ca[1];
				ca[1]=1;
			}
			w*=ca[0];
			ca[0]=1;
		}
	}
	printf("%d\n",z);
}
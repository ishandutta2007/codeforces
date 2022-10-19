#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 300010
using namespace std;
ll n,o_num[3],z_num[3];
char buf[N];
string s[3];
void solveo(ll a,ll b)
{
	ll i=0,j=0;
	while(i<2*n)
	{
		if(s[a][i]=='1')
		{
			while(j<2*n&&s[b][j]=='0')
			{
				putchar('0');
				j++;
			}
			j++;
		}
		printf("%c",s[a][i]);
		i++;
	}
	while(j<2*n)
	{
		printf("%c",s[b][j]);
		j++;
	}
	puts("");
	return;
}
void solvez(ll a,ll b)
{
	ll i=0,j=0;
	while(i<2*n)
	{
		if(s[a][i]=='0')
		{
			while(j<2*n&&s[b][j]=='1')
			{
				putchar('1');
				j++;
			}
			j++;
		}
		printf("%c",s[a][i]);
		i++;
	}
	while(j<2*n)
	{
		printf("%c",s[b][j]);
		j++;
	}
	puts("");
	return;
}
int main(){
	ll T,i,j;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		scanf("%s",&buf);
		s[0]=buf;
		scanf("%s",&buf);
		s[1]=buf;
		scanf("%s",&buf);
		s[2]=buf;
		memset(o_num,0,sizeof(o_num));
		memset(z_num,0,sizeof(z_num));
		for(i=0;i<2*n;i++)
		{
			for(j=0;j<3;j++)
			{
				o_num[j]+=(s[j][i]=='1');
				z_num[j]+=(s[j][i]=='0');
			}
		}
		i=0,j=0;
		if(min(o_num[0],o_num[1])>=n)
		{
			if(o_num[0]>=o_num[1])
			{
				solveo(0,1);
			}
			else
			{
				solveo(1,0);
			}
		}
		else if(min(z_num[0],z_num[1])>=n)
		{
			if(z_num[0]>=z_num[1])
			{
				solvez(0,1);
			}
			else
			{
				solvez(1,0);
			}
		}
		else if(min(o_num[0],o_num[2])>=n)
		{
			if(o_num[0]>=o_num[2])
			{
				solveo(0,2);
			}
			else
			{
				solveo(2,0);
			}
		}
		else if(min(z_num[0],z_num[2])>=n)
		{
			if(z_num[0]>=z_num[2])
			{
				solvez(0,2);
			}
			else
			{
				solvez(2,0);
			}
		}
		else if(min(o_num[1],o_num[2])>=n)
		{
			if(o_num[1]>=o_num[2])
			{
				solveo(1,2);
			}
			else
			{
				solveo(2,1);
			}
		}
		else if(min(z_num[1],z_num[2])>=n)
		{
			if(z_num[1]>=z_num[2])
			{
				solvez(1,2);
			}
			else
			{
				solvez(2,1);
			}
		}
		else
		{
			cout<<s[0]<<s[1]<<s[2]<<endl;
		}
	}
	return 0;
}
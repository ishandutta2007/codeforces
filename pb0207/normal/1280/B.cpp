#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int N=2e6+1e3+7,P=1e9+7;
 
int T,r,c;
 
char s[61][61];
 
ll len;
 
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&r,&c);
		for(int i=1;i<=r;i++)
			scanf("%s",s[i]+1);
		bool ans0=1,ans1=0,ans2=0,ans3=0,ans4=0;
		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++)
				ans0&=s[i][j]=='A';
		bool flag=1;
		for(int i=1;i<=r;i++)
			flag&=s[i][1]=='A';
		if(flag)
			ans1=1;
		flag=1;
		for(int i=1;i<=r;i++)
			flag&=s[i][c]=='A';
		if(flag)
			ans1=1;
		flag=1;
		for(int i=1;i<=c;i++)
			flag&=s[1][i]=='A';
		if(flag)
			ans1=1;
		flag=1;
		for(int i=1;i<=c;i++)
			flag&=s[r][i]=='A';
		if(flag)
			ans1=1;
		for(int i=2;i<=r-1;i++)
		{
			bool flag=1;
			for(int j=1;j<=c;j++)
				flag&=s[i][j]=='A';
			if(flag)
				ans2=1;
		}
		for(int j=2;j<=c-1;j++)
		{
			bool flag=1;
			for(int i=1;i<=r;i++)
				flag&=s[i][j]=='A';
			if(flag)
				ans2=1;
		}
		if(s[1][1]=='A'||s[1][c]=='A'||s[r][1]=='A'||s[r][c]=='A')
			ans2=1;
		for(int i=2;i<=r-1;i++)
			if(s[i][1]=='A'||s[i][c]=='A')
				ans3=1;
		for(int j=2;j<=c-1;j++)
			if(s[1][j]=='A'||s[r][j]=='A')
				ans3=1;
		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++)
				if(s[i][j]=='A')
					ans4=1;
		if(ans0)
			puts("0");
		else if(ans1)
			puts("1");
		else if(ans2)
			puts("2");
		else if(ans3)
			puts("3");
		else if(ans4)
			puts("4");
		else 
			puts("MORTAL");
	}
}
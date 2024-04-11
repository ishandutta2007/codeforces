//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 310
using namespace std;
ll n,num[N];
bool badid[N];
string s;
int main(){
	ll T,i,j,x,y;
	cin>>T;
	while(T--)
	{
		cin>>n>>s;
		memset(badid,false,sizeof(badid));
		j=0;
		x=-1;
		y=-1;
		for(i=0;i<s.size();i++)
		{
			if(s[i]=='2')
			{
				badid[i]=true;
				num[i]=j;
				j++;
			}
		}
		if(j==1||j==2)
		{
			puts("NO");
			continue;
		}
		puts("YES");
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(i==j)
				{
					putchar('X');
				}
				else if((!badid[i])||(!badid[j]))
				{
					putchar('=');
				}
				else
				{
					if(num[i]+1==num[j])
					{
						putchar('+');
					}
					else if(num[i]==num[j]+1)
					{
						putchar('-');
					}
					else if(i<j)
					{
						putchar('-');
					}
					else
					{
						putchar('+');
					}
				}
			}
			puts("");
		}
	}
	return 0;
}
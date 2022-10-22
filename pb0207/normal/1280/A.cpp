#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int N=2e6+1e3+7,P=1e9+7;
 
int x,T;
 
char s[N];
 
 
ll len;
 
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		bool flag=true;
		scanf("%d",&x);
		scanf("%s",s+1);
		len=strlen(s+1);
		for(int i=1;i<=x;i++)
		{
			ll apl=(len-i+P)%P;
			for(int k=1;k<=s[i]-'0'-1;k++)
			{
				if(flag)
					for(int j=len+1;j<=min(len+apl,(ll)x);j++)
						if(j-apl>0)
							s[j]=s[j-apl];
				if(len+apl>x)
					flag=false;
				len=(len+apl)%P;
			}
		}
		printf("%lld\n",len);
	}
}
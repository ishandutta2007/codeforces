#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=1e6+1e3+7;

int T;

char s[N];

int n;

ll res,pos[N];

int main()
{
	cin>>T;
	while(T--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		int st=0,mn=0;
		res=0;
		for(int i=1;i<=n;i++)	
		{
			if(s[i]=='-') 
				st--;
			else
				st++;
			if(st<mn)
				mn=st,pos[-st]=i,res+=i;
		}
		printf("%lld\n",res+n);
	}	
}
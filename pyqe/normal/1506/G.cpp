#include <bits/stdc++.h>

using namespace std;

long long n,mx[26];
queue<long long> vl[26];

int main()
{
	long long t,rr,i,k,w,p,e;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		n=s.length();
		for(i=0;i<26;i++)
		{
			for(;!vl[i].empty();vl[i].pop());
			mx[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			k=s[i-1]-'a';
			vl[k].push(i);
			mx[k]=i;
		}
		for(p=0;1;)
		{
			w=n+1;
			e=-1;
			for(i=0;i<26;i++)
			{
				if(mx[i])
				{
					for(;vl[i].front()<=p;vl[i].pop());
					if(vl[i].front()<w)
					{
						e=i;
					}
					w=min(w,mx[i]);
				}
			}
			if(e==-1)
			{
				break;
			}
			printf("%c",(char)e+'a');
			mx[e]=0;
			p=vl[e].front();
		}
		printf("\n");
	}
}
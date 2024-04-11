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
#define N 100010
using namespace std;
char buf[N];
ll app[N];
string s;
int main(){
	ll T,i,tp;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%s",&buf);
		s=buf;
		for(i=0;i<26;i++)
		{
			app[i]=0;
		}
		tp=0;
		for(i=0;i<s.size();i++)
		{
			app[s[i]-'a']++;
			if(app[s[i]-'a']==1)
			{
				tp++;
			}
		}
		if(tp>=3)
		{
			vector<char> chs;
			char spc='!';
			ll sum=0;
			for(i=0;i<26;i++)
			{
				if(app[i]>0)
				{
					chs.push_back((char)(i+'a'));
					sum+=app[i];
				}
				if(app[i]==1)
				{
					if(spc=='!')
					{
						spc=(char)(i+'a');
					}
				}
			}
			if(spc!='!')
			{
				putchar(spc);
				app[spc-'a']--;
				for(i=0;i<chs.size();i++)
				{
					while(app[chs[i]-'a']>0)
					{
						putchar(chs[i]);
						app[chs[i]-'a']--;
					}
				}
			}
			else
			{
				putchar(chs[0]);
				app[chs[0]-'a']--;
				sum--;
				if(app[chs[0]-'a']>0&&app[chs[0]-'a']-1<=sum-app[chs[0]-'a'])
				{
					putchar(chs[0]);
					app[chs[0]-'a']--;
					i=1;
					while(app[chs[0]-'a']>0)
					{
						putchar(chs[i]);
						app[chs[i]-'a']--;
						if(app[chs[i]-'a']==0)
						{
							i++;
						}
						putchar(chs[0]);
						app[chs[0]-'a']--;
					}
					for(i=0;i<chs.size();i++)
					{
						while(app[chs[i]-'a']>0)
						{
							putchar(chs[i]);
							app[chs[i]-'a']--;
						}
					}
				}
				else
				{
					putchar(chs[1]);
					app[chs[1]-'a']--;
					while(app[chs[0]-'a']>0)
					{
						putchar(chs[0]);
						app[chs[0]-'a']--;
					}
					putchar(chs[2]);
					app[chs[2]-'a']--;
					for(i=0;i<chs.size();i++)
					{
						while(app[chs[i]-'a']>0)
						{
							putchar(chs[i]);
							app[chs[i]-'a']--;
						}
					}
				}
			}
			puts("");
		}
		else if(tp==2)
		{
			//abbbb...baa... is always good
			char a='!',b='!',spc='!';
			for(i=0;i<26;i++)
			{
				if(app[i]>0)
				{
					if(a=='!')
					{
						a=(char)(i+'a');
					}
					else
					{
						b=(char)(i+'a');
					}
				}
				if(app[i]==1)
				{
					if(spc=='!')
					{
						spc=(char)(i+'a');
					}
				}
			}
			if(spc!='!')
			{
				putchar(spc);
				app[spc-'a']--;
				for(i=0;i<26;i++)
				{
					while(app[i]>0)
					{
						putchar(i+'a');
						app[i]--;
					}
				}
			}
			else
			{
				ll x=app[a-'a'],y=app[b-'a'];
				putchar(a);
				app[a-'a']--;
				if(app[a-'a']>0&&app[b-'a']>=app[a-'a']-1)
				{
					putchar(a);
					app[a-'a']--;
					while(app[a-'a']>0)
					{
						putchar(b);
						putchar(a);
						app[b-'a']--;
						app[a-'a']--;
					}
					while(app[b-'a']>0)
					{
						putchar(b);
						app[b-'a']--;
					}
				}
				else
				{
					while(app[b-'a']>0)
					{
						putchar(b);
						app[b-'a']--;
					}
					while(app[a-'a']>0)
					{
						putchar(a);
						app[a-'a']--;
					}
				}
			}
			puts("");
		}
		else
		{
			printf("%s\n",s.c_str());
		}
	}
	return 0;
}
#include <bits/stdc++.h>

std::vector<int> query(const char s[])
{
	printf("? %s\n",s);
	fflush(stdout);
	
	int sz;
	scanf("%d",&sz);
	if(sz==-1)exit(0);
	std::vector<int> ret;
	while(sz--)
	{
		int x;
		scanf("%d",&x);
		ret.push_back(x);
	}
	return ret;
}

namespace M1
{
	char s[55];
	std::vector<int> vs;
	void solve(int n)
	{
		memset(s,0,sizeof(s));
		vs=query("CH");
		for(int i=0;i<(int)vs.size();i++)
		{
			s[vs[i]]='C';
			s[vs[i]+1]='H';
		}
		vs=query("CO");
		for(int i=0;i<(int)vs.size();i++)
		{
			s[vs[i]]='C';
			s[vs[i]+1]='O';
		}
		vs=query("CC");
		for(int i=0;i<(int)vs.size();i++)
		{
			s[vs[i]]='C';
			s[vs[i]+1]='C';
		}
		vs=query("HH");
		for(int i=0;i<(int)vs.size();i++)
		{
			s[vs[i]]='H';
			s[vs[i]+1]='H';
		}
		vs=query("OH");
		for(int i=0;i<(int)vs.size();i++)
		{
			s[vs[i]]='O';
			s[vs[i]+1]='H';
		}
		for(int i=2;i<n;i++)if(!s[i])s[i]='O';
		std::vector<char> cd1,cd2;
		if(s[1])cd1.push_back(s[1]);
		else
		{
			cd1.push_back('O');
			cd1.push_back('H');
		}
		if(s[n])cd2.push_back(s[n]);
		else
		{
			cd2.push_back('O');
			cd2.push_back('C');
		}
		for(int i=0;i<cd1.size();i++)for(int j=0;j<cd2.size();j++)
		{
			s[1]=cd1[i];s[n]=cd2[j];
			if((i==cd1.size()-1&&j==cd2.size()-1)||query(s+1).size())
			{
				printf("! %s\n",s+1);
				fflush(stdout);
				return;
			}
		}
	}
}

namespace M2
{
	char s[100];
	std::vector<int> vs;
	void disclose_all(int n)
	{
		int piv=1;
		while(piv<n&&!s[piv])piv++;
		for(int i=piv-1;i>=1;i--)if(!s[i])
		{
			bool find=0;
			
			s[i]='O';
			vs=query(s+i);
			for(int j=0;j<(int)vs.size();j++)if(vs[j]==i)find=1;
			if(find)continue;
			
			s[i]='H';
			vs=query(s+i);
			for(int j=0;j<(int)vs.size();j++)if(vs[j]==i)find=1;
			if(find)continue;
			
			s[i]='C';
		}
		for(int i=piv+1;i<=n;i++)if(!s[i])
		{
			s[i]='O';
			vs=query(s+1);
			if(vs.size()&&vs[0]==1)continue;
			
			s[i]='H';
			vs=query(s+1);
			if(vs.size()&&vs[0]==1)continue;
			
			s[i]='C';
		}
		printf("! %s\n",s+1);
		fflush(stdout);
	}
	void solve(int n)
	{
		memset(s,0,sizeof(s));
		vs=query("CH");
		for(int i=0;i<(int)vs.size();i++)
		{
			s[vs[i]]='C';
			s[vs[i]+1]='H';
		}
		vs=query("CO");
		for(int i=0;i<(int)vs.size();i++)
		{
			s[vs[i]]='C';
			s[vs[i]+1]='O';
		}
		vs=query("HO");
		for(int i=0;i<(int)vs.size();i++)
		{
			s[vs[i]]='H';
			s[vs[i]+1]='O';
		}
		vs=query("HC");
		for(int i=0;i<(int)vs.size();i++)
		{
			s[vs[i]]='H';
			s[vs[i]+1]='C';
		}
		
		int piv=1;
		while(piv<=n&&!s[piv])piv++;
		
		static char tmp[100];
		if(piv<n)disclose_all(n);
		else
		{
			vs=query("OOO");
			for(int i=0;i<(int)vs.size();i++)s[vs[i]]=s[vs[i]+1]=s[vs[i]+2]='O';
			piv=1;while(piv<=n&&!s[piv])piv++;
			if(piv<n)
			{
				disclose_all(n);
				return;
			}
			
			vs=query("CCC");
			for(int i=0;i<(int)vs.size();i++)s[vs[i]]=s[vs[i]+1]=s[vs[i]+2]='C';
			vs=query("HHH");
			for(int i=0;i<(int)vs.size();i++)s[vs[i]]=s[vs[i]+1]=s[vs[i]+2]='H';
			piv=1;while(piv<=n&&!s[piv])piv++;
			
			if(piv<n)
			{
				for(int i=1;i<=n;i++)if(!s[i])s[i]='O';
				printf("! %s\n",s+1);
				fflush(stdout);
			}
			else if(query("OOCC").size())
			{
				printf("! OOCC\n");
				fflush(stdout);
			}
			else
			{
				printf("! OOHH\n");
				fflush(stdout);
			}
		}
	}
}

int main()
{
	int tc;scanf("%d",&tc);
	while(tc--)
	{
		int n;scanf("%d",&n);
		if(n>4) M1::solve(n);
		else M2::solve(n);
		scanf("%*d");
	}
	return 0;
}
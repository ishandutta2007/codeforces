#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int T;

char s[N];

struct TO{
	int a,b;
	int c,d;
	TO(int _a=0,int _b=0,int _c=0,int _d=0){a=_a,b=_b,c=_c,d=_d;}
};

bool operator <(TO a,TO b)
{
	if(a.a==b.a&&a.b==b.b&&a.c==b.c)
		return a.d<b.d;
	if(a.a==b.a&&a.b==b.b)
		return a.c<b.c;
	if(a.a==b.a)
		return a.b<b.b;
	return a.a<b.a;
}

map<TO,bool>mp;

int dx[N],dy[N];

int main() 
{
	dy['N']=1,dy['S']=-1;
	dx['E']=1,dx['W']=-1;
	cin>>T;
	while(T--)
	{
		mp.clear();
		scanf("%s",s+1);
		int n=strlen(s+1);
		int x=0,y=0,ans=0;
		for(int i=1;i<=n;i++)
		{
			int tx=x+dx[s[i]],ty=y+dy[s[i]];
			if(mp.find(TO(x,y,tx,ty))!=mp.end()||mp.find(TO(tx,ty,x,y))!=mp.end())
				ans++;
			else
				ans+=5,mp[TO(x,y,tx,ty)]=1;
			x=tx,y=ty;
		}
		printf("%d\n",ans);
	}
}
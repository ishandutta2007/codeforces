#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

const int N=2e5+1e3+7;

int n,Q;

struct HA{
	ll sd,P;
	
	ll hs[26][N],mi[N];
	
	void init()
	{
		mi[0]=1;
		for(int i=1;i<=n;i++)
			mi[i]=mi[i-1]*sd%P;
	}
	
	ll geth(ll *ha,int l,int r)
	{
		return (ha[r]-ha[l-1]*mi[r-l+1]%P+P)%P;	
	}
}ha[2];
	
int sw[N],tw[N];

char s[N];

int main()
{
	ha[0].sd=1313131,ha[0].P=1e9+7;
	ha[1].sd=1313113,ha[1].P=998244353;
	scanf("%d%d",&n,&Q);
	ha[0].init();
	ha[1].init();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
		for(int j=0;j<26;j++)
		{
			ha[0].hs[j][i]=(ha[0].hs[j][i-1]*ha[0].sd%ha[0].P+((s[i]-'a')==j))%ha[0].P;
			ha[1].hs[j][i]=(ha[1].hs[j][i-1]*ha[1].sd%ha[1].P+((s[i]-'a')==j))%ha[1].P;
		}
	while(Q--)
	{
		int x,y,len;
		scanf("%d%d%d",&x,&y,&len);
		for(int j=0;j<26;j++)
			sw[j]=ha[0].geth(ha[0].hs[j],x,x+len-1),tw[j]=ha[0].geth(ha[0].hs[j],y,y+len-1);
		sort(sw,sw+26),sort(tw,tw+26);
		bool flag=true;
		for(int j=0;j<26;j++)
			if(sw[j]!=tw[j])
				flag=false;
		for(int j=0;j<26;j++)
			sw[j]=ha[1].geth(ha[1].hs[j],x,x+len-1),tw[j]=ha[1].geth(ha[1].hs[j],y,y+len-1);
		sort(sw,sw+26),sort(tw,tw+26);
		for(int j=0;j<26;j++)
			if(sw[j]!=tw[j])
				flag=false;
		puts(flag?"YES":"NO");
	}
}
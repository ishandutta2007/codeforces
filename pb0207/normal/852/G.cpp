#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=1e5+1e3+7,base=1313131,P=998244353,P1=1e9+7;

int n,m,p[5],a[5],ans;

multiset< pair<ll,ll> >se;
map<pair<ll,ll>,int>qt;

ll hs;

char s[N],s1[N];

void dfs(int now)
{
	if(now==0)
	{
		int len=strlen(s1);
		ll tmp=0,tmp1=0;
		for(int i=0;i<len;i++)
		{
			if(p[1]==i)
			{
				if(a[1]!=0)
					tmp=(tmp*base%P+a[1]+'a'-1)%P,
					tmp1=(tmp1*base%P1+a[1]+'a'-1)%P1;
				continue;
			}
			if(p[2]==i)
			{
				if(a[2]!=0)
					tmp=(tmp*base%P+a[2]+'a'-1)%P,
					tmp1=(tmp1*base%P1+a[2]+'a'-1)%P1;
				continue;
			}
			if(p[3]==i)
			{
				if(a[3]!=0)
					tmp=(tmp*base%P+a[3]+'a'-1)%P,
					tmp1=(tmp1*base%P1+a[3]+'a'-1)%P1;
				continue;
			}
			tmp=(tmp*base%P+s1[i])%P;
			tmp1=(tmp1*base%P1+s1[i])%P1;
		}
		if(qt[make_pair(tmp,tmp1)]!=m+1)
		ans+=se.count(make_pair(tmp,tmp1)),qt[make_pair(tmp,tmp1)]=m+1;
		return;
	}
	for(int i=0;i<=5;i++)
		a[now]=i,dfs(now-1);
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		hs=0;ll hs1=0;
		scanf("%s",s);
		int len=strlen(s);
		for(int j=0;j<len;j++)
		{
			hs=(hs*base%P+s[j])%P;
			hs1=(hs1*base%P1+s[j])%P1;
		}
		se.insert(make_pair(hs,hs1));
	}
	while(m--)
	{
		ans=0;
		scanf("%s",s1);
		int len=strlen(s1);
		int ct=0;
		for(int i=1;i<=3;i++)
			p[i]=-1;
		for(int i=0;i<len;i++)
			if(s1[i]=='?')
				p[++ct]=i;
		dfs(ct);
		printf("%d\n",ans);
	}
}
/*
3 4
abc
aec
ac
a?c
ac?
?ac
ac?
*/
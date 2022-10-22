#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e6+1;

char s[N],t[N];
ll a[1001],b[1001],d[1001];
ll n,m,tmp=0;
int q[N];
bool can(ll ans,bool tag)
{
	ll ret=0;
	memset(d,0,sizeof(d));
	for(int i=0;i<=50;++i)d[i]=a[i]-ans*b[i];
	for(int i=0;i<=50;++i)if(d[i]<0)ret-=d[i];
	if(tag)
	{
		for(int i=0;i<=50;++i)
		if(d[i]<0)
		{
			for(int t=1;t<=-d[i];++t)
			q[++q[0]]=(i+'a'),tmp--;
		}
		for(int i=1;i<=tmp;++i)q[++q[0]]='a';
		for(int i=1;i<=n;++i)
		{
			if(s[i]!='?')printf("%c",s[i]);
			else	printf("%c",(char)q[q[0]--]);
		}
		return 0;
	}
	if(ret<=tmp)return 1;
	return 0;
}

int main()
{
//	freopen("c.in","r",stdin);
//	freopen("c.out","w",stdout);
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1),m=strlen(t+1);
	for(int i=1;i<=n;++i)
	if(s[i]!='?')a[s[i]-'a']++;
	else	tmp++;
	for(int i=1;i<=m;++i)b[t[i]-'a']++;
	int l=0,r=n;
	while(l!=r)
	{
		int mid=l+r+1>>1;
		if(can(mid,0))l=mid;
		else	r=mid-1;
	}
	can(l,1);
	
}
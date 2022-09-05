#include<bits/stdc++.h>
using namespace std;

const int mod=1000000007;
int Aa,Ab,Al,Ba,Bb,Bl,t[110],T,tn,tt[110];
bool bo[100010];

int dfs(int x,int s)
{
	if (x==tn+1) return 1ll*s*s%mod;
	int ans=0;
	for (int i=0,nw=1; i<=t[x]; i++,nw*=tt[x]) ans=(ans+dfs(x+1,s*nw))%mod;
	return ans;
}

int main()
{
	for (int i=2; i<=100000; i++) if (!bo[i])
		for (int j=i+i; j<=100000; j+=i) bo[j]=1;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d%d%d%d",&Aa,&Ab,&Al,&Ba,&Bb,&Bl);
		if (Bb%Ab!=0||Ba<Aa||Ba+1ll*(Bl-1)*Bb>Aa+1ll*(Al-1)*Ab) {puts("0"); continue;}
		if ((Ba-Aa)%Ab!=0) {puts("0"); continue;}
		if (Ba-Bb<Aa) {puts("-1"); continue;}
		if (Ba+1ll*Bl*Bb>Aa+1ll*(Al-1)*Ab) {puts("-1"); continue;}
		int x=Ab,y=Bb; tn=0;
		for (int i=2; i*i<=Ab; i++) if (!bo[i]&&x%i==0)
		{
			int cnt=0;
			while (x%i==0) x/=i,y/=i,cnt++;
			if (y%i!=0) t[++tn]=cnt,tt[tn]=i;
		}
		if (x!=1)
		{
			if ((y/x)%x!=0) t[++tn]=1,tt[tn]=x;
		}
		printf("%d\n",dfs(1,1));
	}
	return 0;
}
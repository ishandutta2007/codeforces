#include<bits/stdc++.h>
using namespace std;

const int B=500,N=B*200000,BB=200000/B;

long long ans;
int n,s[200010],t[N+200010],l[200010],r[200010];
char str[200010];

long long calc(int l,int r,int k)
{
	l--;
	int nw1=l/k,nw2=r/k;
	if (l!=-1) return ((1ll*(nw2-1)*nw2)>>1)*k+1ll*nw2*(r-nw2*k+1)-((1ll*(nw1-1)*nw1)>>1)*k-1ll*nw1*(l-nw1*k+1);
	else return ((1ll*(nw2-1)*nw2)>>1)*k+1ll*nw2*(r-nw2*k+1);
}

//sigma i=l..r  i/k

int main()
{
	scanf("%s",str+1),n=strlen(str+1),s[0]=0,ans=0;
	for (int i=1; i<=n; i++) s[i]=s[i-1]+(str[i]=='1');
	for (int i=1; i<=B; i++)
	{
		for (int j=0,nw; j<=n; j++)
		{
			nw=j-s[j]*i+N;
			ans+=t[nw],t[nw]++;
		}
		for (int j=0; j<=n; j++) t[j-s[j]*i+N]=0; 
	}
	for (int i=0; i<=n; i++) l[i]=-1;
	for (int i=0; i<=n; i++)
	{
		if (l[s[i]]==-1) l[s[i]]=i;
		r[s[i]]=i;
	}
	for (int i=0; i<=s[n]; i++)
	{
		int l1,r1,l2,r2,k,p;
		for (int j=i+1; j<=i+BB&&j<=s[n]; j++)
		{
			l1=l[i],r1=r[i],l2=l[j],r2=r[j],k=j-i;
			r1=min(r1,r2-k*B-1);
			if (r1<l1) continue;
			if (l1+k*B>=l2)
			{
				ans+=calc(r2-r1,r2-l1,k)-1ll*B*(r1-l1+1);
				continue;
			}
			p=min(l2-k*B,r1+1);
			if (p<=r1) ans+=calc(r2-r1,r2-p,k)-1ll*B*(r1-p+1);
			ans+=calc(r2-(p-1),r2-l1,k)-calc(l2-(p-1)-1,l2-l1-1,k);
		}
	}
	printf("%I64d\n",ans);
	return 0;
}